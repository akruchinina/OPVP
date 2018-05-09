#include <stdio.h>
#include <stdlib.h>

int main() 
{
	//кол-во шагов
	static long n = 1000000000;
	//размер шага
	double h = 1.0 / (double)n;

	int i;
	double x, pi, sum = 0.0;

	#pragma omp simd
	for (i = 0; i < n; i++)
	{
		x = (i + 0.5) * h;
		sum += 4.0 / (1.0 + x * x);
	}

	pi = h * sum;
	printf("PI = %.16g\n", pi);
}