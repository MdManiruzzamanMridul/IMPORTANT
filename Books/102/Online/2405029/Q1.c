#include <stdio.h>
int main()
{
    int a, r1 = 0, n, i, p, x, r = 0;
    scanf("%d", &x);
    while (x != 0)
    {
        n = x % 100;
        while (n != 0)
        {
            r1 = n % 10 + r1 * 10;
            n /= 10;
        }

        r1 = r1 * 100 + r;
        r = r1/100;
        x /= 100;
    }
    r1=r1%10000;
    printf("%d", r1);
}
