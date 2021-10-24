// Program to find GCD of positive integers
#include <stdio.h>

int main()
{
    int n1, n2;
    
    printf("Enter two positive integers: ");
    scanf("%d %d",&n1,&n2);
    
    if(n1 < 0 || n2 < 0)
    {
        printf("One of the number is negative. Please try again with positive integers.");
        return 0;
    }
    
    while(n1!=n2)
    {
        if(n1 > n2)
            n1 -= n2;
        else
            n2 -= n1;
    }
    
    if(n1 == 0 && n2 == 0)
    {
        printf("GCD = undefined");
    } else {
        printf("GCD = %d",n1);
    }
    
    return 0;
}