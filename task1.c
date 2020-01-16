#include<stdio.h>
#include<stdlib.h>



int partition(int array[], int low, int high)
{
	int i;
	int temp;
	int pivot = array[low];
	//printf("%d",pivot);
	int flag = low;
	for(i=low+1;i<=high;i++)
	{
		if(array[i]<pivot)
		{
			flag++;
			temp=array[flag];
			array[flag]=array[i];
			array[i]=temp;
		}
	}
	temp=array[low];
	array[low]=array[flag];
	array[flag]=temp;
	return flag;
}

void quicksort(int array[], int low, int high)
{
	int loc;
	if(low<high)
	{
		loc = partition(array,low,high);
		quicksort(array,low,loc);
		quicksort(array,loc+1,high);
	}
}

int main()
{
	int array[]={2,34,27,59,16,20,45,48,26};
//	int array[]={5,4,3,2,1};
	int i;
	int size = sizeof(array)/sizeof(array[0]);
	printf("Array Before Sorting : \t");
	for(i=0;i<size;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\nArray After Sorting  : \t");
	//int pivot = array[size-1];
	quicksort(array,0,size-1);
	for(i=0;i<size;i++)
	{
		printf("%d ",array[i]);
	}
	return 0;
	
}



