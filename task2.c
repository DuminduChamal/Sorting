#include <stdio.h>

void merge(int array[], int left, int middle, int right)
{
	int x = middle-left+1;
	int y = right-middle;
	int temp1[x],temp2[y];
//	printf("%d %d\n",x,y);
	int i,j,k;
	for(i=0;i<x;i++)
	{
		temp1[i]=array[left+i];
//		printf("%d \n",temp1[i]);
	}
//	printf("\n",temp1[i]);
	for(j=0;j<y;j++)
	{
		temp2[j]=array[middle+1+j];
//		printf("%d \n",temp2[j]);
	}
	i=0;
	j=0;
	for(k=left; i<x && j<y; k++)
	{
		if(temp1[i]<=temp2[j])
		{
			array[k]=temp1[i];
			i++;
		}
		else
		{
			array[k]=temp2[j];
			j++;
		}
	}
//	for(i=0;i<9;i++)
//	{
//		printf("%d ",array[i]);
//	}
	while(i<x)
	{
		array[k]=temp1[i];
		k++;
		i++;
	}
	while(j<y)
	{
		array[k]=temp2[j];
		k++;
		j++;
	}
//	for(i=0;i<9;i++)
//	{
//		printf("%d ",array[i]);
//	}
	return;
}

void mergeSort(int array[],int left, int right)
{
//	int size = sizeof(array);
//	printf("%d\n",size);
	if(left==right)
	{
		return;
	}
	else
	{
		int m = (left+right)/2;
		//printf("%d\n",m);
		mergeSort(array,left,m);
		mergeSort(array,m+1,right);
		merge(array,left,m,right);
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
	mergeSort(array,0,size-1);
	for(i=0;i<size;i++)
	{
		printf("%d ",array[i]);
	}
	return 0;
}
