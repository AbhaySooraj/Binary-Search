/*To create a program to execute binary search*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void sort(int array[],int y)
{
	int c,d,swap;
	for (c = 0 ; c < y - 1; c++)
	{
    		for (d = 0 ; d < y - c - 1; d++)
    		{
      			if (array[d] > array[d+1])
      			{
        			swap       = array[d];
        			array[d]   = array[d+1];
        			array[d+1] = swap;
      			}
    		}
	}
}

void main()
{
	struct timeval t0;
   	struct timeval t1;
   	float elapsed;
	
	int x,num,i,j=0;
	
	printf("\n Enter no.of elements :");
	scanf("%d",&num);
	int arr[num];
	
	for(i=0;i<num;i++)
	{
		arr[i]=rand()%100;
	}
	
	sort(arr,num);
	
	printf("\n The elements are :");
	for(i=0;i<num;i++)
	{
		printf("%d \t",arr[i]);
	}
	printf("\n Enter value to be searched :");
	scanf("%d",&x);
	gettimeofday(&t0, NULL);
	
	int low=0,high=num,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]==x)
		{
			printf(" Element found at %d position",mid);
			break;
		}
		else if(arr[mid]>x)
		{
			high=mid-1;
		}
		else
		{
			low=mid+1;
		}
		
	}
	if(low>high)
	{
		printf("\n Element not found");
	} 
	gettimeofday(&t1, NULL);
	elapsed = timedifference_msec(t0, t1);
  	printf("\n Code executed in %f milliseconds.\n", elapsed);
	
}


