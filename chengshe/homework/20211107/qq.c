#include <stdio.h>
int abs(int c)
{
	if(c >=0)
	{
		return c;
	}
	else
	{
		return -c;
	}
}

int main()
{
	long n,i,j, t;
	long sum =0;
	long min = 0;
	scanf("%ld", &n);
	long arr[n];
	long arrmin[n] ;
	for(i = 0; i< n; i++)
	{
		scanf("%ld", &arr[i]);
	}
//	for(i = 0; i < n; i ++)
//    {
//    	printf("%d",arr[i]);
//	}
	for(i = 1;i < n;i++)
	{
	    
		for(j = 0; j< i;j++)
		{
			long z = arr[i] - arr[j];
		    t = abs(z);
			do{
				
			}
          
		}
		arrmin[i] = min;
	}
	for(i = 1; i< n; i++)
	printf("%d",arrmin[i]);

    for(i = 1 ;i < n; i++)
    {
    	sum =sum + arrmin[i]; 
	}
	printf("%ld",sum);
	
	
	return 0;
}
