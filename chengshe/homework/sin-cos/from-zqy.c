#include <stdio.h>
#include <math.h>
int main()
{
	double x, y, k, w;
	double sinx, cosx = 0;
	scanf("%lf %lf", &x, &y);
	double pi = 3.14159265;
	x = fmod(x, pi * 2); // in case of big degree
	int sign = 1;
	sinx = x;
	k = x;
	int i = 3;
	while (1)
	{
		w = pow(x, 2) / (i * (i - 1));
		k = k * w;
		if (k < y)
			break;
		sign *= -1;
		sinx = sinx + sign * k;
		i += 2;
	}
	i = 2;
	cosx = 1;
	k = 1;
	sign = 1;
	while (1)
	{
		w = pow(x, 2) / (i * (i - 1));
		k = k * w;
		if (k < y)
			break;
		sign *= -1;
		cosx = cosx + sign * k;
		i += 2;
	}
	printf("%lf\n", sinx);
	printf("%lf\n", cosx);
	return 0;
}