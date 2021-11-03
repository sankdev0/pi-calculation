#include <stdio.h>
#include <time.h>
#include <chrono>

#define CHUNKSIZE 1000000

using namespace std::chrono;

/**
* ¬ычисление приближени€ числа Pi в нескольких потоках.
*/
double calc_pi_multi_threaded_reduction()
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
		//  од программы, который будет выполн€тьс€ параллельно
		for (i = 0; i < num_steps; i++) {
			x = (i + .5) * step;
			sum = sum + 4.0 / (1. + x * x);
		}
	}

	pi = sum * step;

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	printf("===>>> ќбработка цикла зан€ла %lld микросекунд.\n", (long long)duration.count());

	return pi;
}

/**
* ¬ычисление приближени€ числа Pi в нескольких потоках.
*/
double calc_pi_multi_threaded_critical()
{
	int chunk = CHUNKSIZE;
	long long num_steps = 1000000000;
	double step;
	double x, pi, sum = 0.0;
	int i;
	double temp; // дл€ временного хранени€ слагаемого
	step = 1. / (double)num_steps;

	auto start = high_resolution_clock::now();

#pragma omp parallel num_threads(6) shared(chunk) private(i, x, temp)
	{
#pragma omp for schedule(dynamic,chunk) nowait
		//  од программы, который будет выполн€тьс€ параллельно
		for (i = 0; i < num_steps; i++) {
			x = (i + .5) * step;
			temp = 4.0 / (1. + x * x);
#pragma omp critical
			sum += temp;
		}
	}

	pi = sum * step;

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	printf("===>>> ќбработка цикла зан€ла %lld микросекунд.\n", (long long)duration.count());

	return pi;
}

/**
* ¬ычисление приближени€ числа Pi в нескольких потоках.
*/
double calc_pi_multi_threaded_atomic()
{
	int chunk = CHUNKSIZE;
	long long num_steps = 1000000000;
	double step;
	double x, pi, sum = 0.0;
	int i;
	double temp; // дл€ временного хранени€ слагаемого
	step = 1. / (double)num_steps;

	auto start = high_resolution_clock::now();

#pragma omp parallel num_threads(6) shared(chunk) private(i, x, temp)
	{
#pragma omp for schedule(dynamic,chunk) nowait
		//  од программы, который будет выполн€тьс€ параллельно
		for (i = 0; i < num_steps; i++) {
			x = (i + .5) * step;
			temp = 4.0 / (1. + x * x);
#pragma omp atomic
			sum += temp;
		}
	}

	pi = sum * step;

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	printf("===>>> ќбработка цикла зан€ла %lld микросекунд.\n", (long long)duration.count());

	return pi;
}