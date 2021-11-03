#include <stdio.h>
#include <time.h>
#include <chrono>

using namespace std::chrono;

/**
* ¬ычисление приближени€ числа Pi в одном потоке.
*/
double calc_pi_single_threaded()
{
	long long num_steps = 1000000000;
	double step;
	double x, pi, sum = 0.0;
	int i;
	step = 1. / (double)num_steps;

	auto start = high_resolution_clock::now();

	for (i = 0; i < num_steps; i++) {
		x = (i + .5) * step;
		sum = sum + 4.0 / (1. + x * x);
	}

	pi = sum * step;

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	printf("===>>> ќбработка цикла зан€ла %lld микросекунд.\n", (long long)duration.count());
	
	return pi;
}