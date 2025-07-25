// CSE102 Offline-1, Energy of Powercells
#include <stdio.h>
int main()
{
    int i, i1, i2, n, k, sum, elements, Z = 0;
    // rows
    scanf(" %d", &n);
    if (n > 1 && n < 11)
    {
        for (i1 = 1; i1 <= n; i1++)
        {
            int count = 0, sum = 0, reverse = 0, evensum = 0, oddsum = 0, altsum = 0, prime = 0, pallindrome = 0, balanced = 0, harmonic = 0, energy = 0;
            // coloumn
            scanf(" %d", &k);
            if (k <= 15)
            {
                for (i2 = 1; i2 <= k; i2++)
                {
                    // sum = 0;
                    scanf("%d", &elements);
                    sum += elements;

                    if (i2 % 2 == 0)
                        evensum = evensum + elements;
                    else
                        oddsum = oddsum + elements;
                    altsum = oddsum - evensum;

                    /* another way of getting altsum
                    altsum=-altsum+elements;
                    if(k%2==0)
                    altsum=-altsum;*/
                    // for odd int the altsum will be right, but not for the even, so a minus sign.
                }

                // prime
                count = 0;
                for (i = 1; i <= sum; i++)
                {
                    if (sum % i == 0)
                        count++;
                }

                if (count <= 2 && sum != 1)
                    prime = 1;
                else
                    prime = 0;

                // pallindrome
                reverse = 0;
                int r = sum;
                while (r != 0)
                {
                    reverse = reverse * 10 + r % 10;
                    r /= 10;
                }
                if (reverse == sum)
                    pallindrome = 1;

                // harmonic
                harmonic = 0;
                if (altsum % 7 == 0)
                    harmonic = 1;

                // balanced
                balanced = 0;
                if (oddsum == evensum)
                    balanced = 1;

                // printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", sum,pallindrome,prime,altsum,oddsum,evensum,harmonic,balanced);
                if (prime == 1)
                    energy = energy + 5;
                if (pallindrome == 1)
                    energy = energy + 3;
                if (harmonic == 1)
                    energy = energy + 4;
                if (balanced == 1)
                    energy = energy + 2;
            }
            Z = Z + energy;
            if (k == 0)
                printf("Row %d: INACTIVE - Energy Level 0\n", i1);
            else if (energy == 14)
                printf("Row %d: ULTRA - Energy Level %d\n", i1, energy);
            else if (energy == 12 || energy == 9 || energy == 11)
                printf("Row %d: HIGH - Energy Level %d\n", i1, energy);
            else if (energy == 8 || energy == 9 || energy == 7 || energy == 6 || energy == 5)
                printf("Row %d: MEDIUM - Energy Level %d\n", i1, energy);
            else if (energy == 2 || energy == 3 || energy == 4 || energy == 5)
                printf("Row %d: LOW - Energy Level %d\n", i1, energy);
            else
                printf("Row %d: INACTIVE - Energy Level %d\n", i1, energy);
        }
    }
    if (k == 0)
        printf("Total Energy: 0\n");
    else
        printf("Total Energy: %d\n", Z);
}