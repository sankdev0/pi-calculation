#include <stdio.h>
#include <time.h>
#include <chrono>

#define CHUNKSIZE 1000000

using namespace std::chrono;

/**
* Вычисление приближения числа Pi в нескольких потоках.
*/
double calc_pi_multi_threaded()
{
	int chunk = CHUNKSIZE;
	long long num_steps = 1000000000;
	double step;
	double x, pi, sum = 0.0;
	int i;
	step = 1. / (double)num_steps;

	auto start = high_resolution_clock::now();

#pragma omp parallel num_threads(6) shared(chunk) private(i, x) reduction(+: sum)
	{
#pragma omp for schedule(dynamic,chunk) nowait
		// Код программы, который будет выполняться параллельно
		for (i = 0; i < num_steps; i++) {
			x = (i + .5) * step;
			sum = sum + 4.0 / (1. + x * x);
			//printf("Hello, world! %d", omp_get_thread_num());
		}
	}

	pi = sum * step;

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	printf("===>>> Обработка цикла заняла %lld микросекунд.\n", (long long)duration.count());

	return pi;
}