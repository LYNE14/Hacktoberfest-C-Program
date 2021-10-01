/*creating array */
#include<stdio.h>
int main()
{
	int i,j,size;
	float avg;
	printf("Enter the size of arraay");
	scanf("%d\n",&size);
	int a[size];
	printf("Enter the value of the array:\n");
	for(i=0;i<size;i++)
	{
		scanf("%d\n",&a[i]);
	}
	printf("find the avrage:\n");
	for(j=0;j<size;j++)
	{
		avg= avg+a[i];
	}
	printf("Avrage Marks: %f",avg);
	

return 0;
}	


