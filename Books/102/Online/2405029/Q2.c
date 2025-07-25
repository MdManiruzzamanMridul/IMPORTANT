//Print Butterfly Pattern
#include <stdio.h>
int main()
{
    int a, n, i, j;
    scanf("%d", &n);
    // rows
    for (i = 1; i <= n; i++)
    // coloumns
    {
        for (j = 1; j <= i; j++)
        {
            printf("%d", j);
        }
        for (j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for (j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
            for (j = i; j > 0; j--)
            {
                printf("%d", j);
            }
        printf("\n");
    }
    return 0;
}