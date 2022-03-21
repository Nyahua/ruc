#include <stdio.h>
#include <stdlib.h>

void mySort( int *ary, int left, int right)
{
	int flag;
	
	if(left==right)
	{
		return;
	}
	
	int i,j,k;
	int low=left;
	int high=right;
	int guard=ary[left];
	do
	{
	    while(low<high&&ary[high]>guard)
		high--;
		if(low<high)
		{
			ary[low]=ary[high];
			low++;
		}
		while(low<high&&ary[low]<guard)
		low++;
		if(low<high)
		{
			ary[high]=ary[low];
			high--;
		}
		
	}while(low!=high);
	mySort(ary,left,low-1);
    mySort(ary,low+1,right);
}

int main()  
{  
    int array[100], i, n;
    
    scanf("%d",&n);

    for ( i = 0; i < n; i ++ ){
        scanf("%d", &array[i]);
    }

    mySort(array, 0, n - 1);

    for ( i = 0; i < n; i ++ ){
        printf("%d ", array[i]);
    }
    printf("\n");  
    return 0;  
}  