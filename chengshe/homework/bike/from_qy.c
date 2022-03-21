#include <stdio.h>
#include <math.h>
int main()
{
	int i, j, k,n;
	scanf("%d", &n);
	int arr[4][n];
	for(i =0; i<4;i++)
	{
		for(j = 0;j<n;j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int b[n];
	for(i = 0; i < n;i++)
	{
		b[i]=arr[1][i]+(arr[2][i]*(arr[3][i]/10));
//		printf("%d  ",b[i]);
	}
	int c=0,d=0;
	int as[n];
	k =0;
	int flag = 0;
    for(i = 0;i<n;i++)
    {
    	if(b[i]>0)
    	{
    		as[k]=i;
//    		printf("%d ", as[k]);
    		k++;
    		flag = 1;	
		}	
	}
	int t;
	if(flag==0)
	{
		return 0;
	}
	c = arr[1][as[0]];
	
	for(i=0;i<k;i++)
	{
		if(arr[1][as[i]]<=c)
		{
			c=arr[1][as[i]];
			t =as[i]+1;
		}
		
	}
		printf("%d ", t);
//	printf("%d",round(24351.8));
	return 0;
 } 
