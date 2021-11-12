#include <stdio.h>
#include <math.h>

long jc(int n)
{
    int i;
    long k = 1;
    for (i = 1; i <= n; i++)
    {
        k = k * i;
    }
    return k;
}

int main()
{
    double x, t, sinx, cosx;
    sinx = 0;
    scanf("%lf %lf", &x, &t);
    int sign = 1;
    int i = 0;
    while (fabs(pow(x, i) / jc(i)) > t)
    {
        sinx += sign * (pow(x, i) / jc(i));
        i += 2;
        sign *= -1;
    }

    printf("%.6lf\n", sinx);

    return 0;
}