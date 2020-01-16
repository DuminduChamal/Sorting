#include<stdio.h>

int power(int base,int exponent)
{
	if(exponent==0)
		return 1;
	else
		return base*(power(base,exponent-1));
}
int main()
{
	int x,y;
	printf("Enter value for base(x) : \n");
	scanf("%d",&x);
	printf("Enter value for exponent(y) : \n");
	scanf("%d",&y);
	if(y<0)
	{
		printf("Please enter a valid positive exponent!\n");
		return 0;
	}
	int result = power(x,y);
	printf("%d to the power %d is : %d\n",x,y,result);
	return 0;
}
