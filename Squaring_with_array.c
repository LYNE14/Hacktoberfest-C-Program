//coded by Subhadeep Mandal
#include <stdio.h>
 
int main() 
{
	int i=0,sq;
	int a[5];
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<5;i++)
	{
		sq=a[i]*a[i];
		printf("The square of the value is %d\n",sq);
	}
	return 0;
}
