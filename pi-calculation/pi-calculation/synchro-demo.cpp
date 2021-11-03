#include <omp.h>
#include <stdio.h>

int syncro_demo()
{
	int x;
	x = 0;

#pragma omp parallel num_threads(4)
	{
//#pragma omp critical 
#pragma omp atomic
		x += 1;
		printf("����� [%d]: x = %d\n", omp_get_thread_num(), x);

#pragma omp barrier

#pragma omp master
		printf("� ������� ����� [%d]! �������� � = %d.\n", omp_get_thread_num(),  x);
	}
	return 0;
}