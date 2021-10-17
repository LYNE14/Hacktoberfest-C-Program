#include <stdio.h>

void main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int i, c = 0, n;
        int a = 0;
        int b = 1;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {
            printf("%d ", c);
            a = b;
            b = c;
            c = a + b;
        }
        printf("\n");
    }
}
