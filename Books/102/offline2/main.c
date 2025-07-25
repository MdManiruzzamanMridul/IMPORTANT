#include <stdio.h>
#include <math.h>
#include <string.h>
#include "utils.c"
#define MAX_SIZE 1000000
#define MAX_BINS 1000
#define MAX_STARS 50
double array[MAX_SIZE];

// size
int size_array()
{
    int size;
    size = sizeof(array) / sizeof(array[0]);
    return size;
}

// set command
void set()
{
    int size;

    // element input
    printf("Enter number of elements (<= 100000): ");
    scanf("%d", &size);
    printf("\n");
    while (size > MAX_SIZE)
    {
        printf("Enter number of elements (<= 100000): ");
        scanf("%d", &size);
        printf("\n");
    }

    // seed input
    unsigned int seed;
    printf("Enter seed: ");
    scanf("%u", &seed);
    printf("\n");

    // distribution
    char distribution[10];
    printf("Distribution? (uniform/gaussian): ");
    scanf("%s", distribution);

    // checking distribution

    // uniform
    if (strcmp(distribution, "uniform") == 0)
    {
        float min_u, max_u;
        printf("Enter min and max: ");
        scanf("%f %f", &min_u, &max_u);
        populate_array_uniform(array, size, min_u, max_u, seed);
        printf("Array initialized with uniform distribution.");
    }

    // gaussian
    else if (strcmp(distribution, "gaussian") == 0)
    {
        float mean, stddev;
        printf("Enter mean and stddev:");
        scanf("%f %f", &mean, &stddev);
        populate_array_gaussian(array, size, mean, stddev, seed);
        printf("Array initialized with gaussian distribution.");
    }

    // invalid
    else
    {
        printf("Invalid distribution\n");
    }
}

// min
double min()
{
    int size = size_array();
    double min = array[0];
    for (int i = 0; i < size; i++)
    {
        if (min > array[i])
            min = array[i];
    }
    printf("Min \t: %7.4f \n", min);
    return min;
}

// max
double max()
{
    int size = size_array();
    double max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (max < array[i])
            max = array[i];
    }
    printf("Max \t: %7.4f \n", max);
    return max;
}

// mean
void mean()
{
    int size = size_array();
    float sum = 0.00, mean = array[0];
    for (int i = 0; i < size; i++)
    {
        sum = sum + array[i];
    }
    mean = sum / size;
    printf("Mean \t: %7.4f \n", mean);
}

// stddev
void stddev()
{
    int size = size_array();
    float sum = 0.00, mean = array[0], differrence = 0, stddev;
    for (int i = 0; i < size; i++)
    {
        sum = sum + array[i];
    }
    mean = sum / size;
    for (int i = 0; i < size; i++)
    {
        differrence = differrence + ((mean - array[i]) * (mean - array[i]));
    }
    stddev = sqrt(differrence / size);
    printf("Std Dev : %7.4f \n", stddev);
}

// hist
void hist()
{

    int bins, size, i;
    float bin_width;
    size = size_array();
    int bin_counts[MAX_BINS] = {0};

    double x,y;
    x = max();
    y = min();

here:
    printf("Enter Number of bins:");
    scanf("%d", &bins);
    int bin_index[size];
    
    // checking range
    if (bins < 1 || bins > 1000)
    {
        printf("\nInvalid number of bins. Must be between 1 and 1000.\n");
        goto here;
    }
    else
    {
        bin_width = (x - y) / bins;
        for (i = 0; i < size; i++)
        {
            bin_index[i] = (int)((array[i] - y) / bin_width);
        }

        // stars
        for (i = 0; i < bins; i++)
        {
            printf("[%7.2f - %7.2f] : ", y + (i * bin_width), y + ((i + 1) * bin_width));
            for (int j = 0; j < size; j++)
            {
                if (bin_index[j] == i)
                    printf("*");
            }
            printf("\n");
        }
    }
    printf("\n");
}

// help command
void help()
{
    printf("Commands:\n");
    printf("set\t - Set array size, seed, and distribution (uniform or gaussian)\n");
    printf("min\t - Print minimum value\n");
    printf("max\t - Print maximum value\n");
    printf("mean\t - Print mean value\n");
    printf("median\t - Print median value\n");
    printf("stddev\t - Print standard deviation\n");
    printf("hist\t - Plot histogram\n");
    printf("summary\t - Print min, max, mean, stddev\n");
    printf("help\t - Show this help message\n");
    printf("exit\t - Exit the program\n");
}

// median
void median()
{
    int size = size_array();

    // sorting
    int i, t, j;
    float median;
    int a[size];

    //printf("working\n");
    // copy array
    for (int i = 0; i < size; i++)
        a[i] = array[i];

    //printf("working\n");
    for (i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (j = i + 1; j < size; j++)
        {
            if (a[min_index] > a[j])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            t = a[i];
            a[i] = a[min_index];
            a[min_index] = t;
        }
    }

    // median part
    if (size % 2 == 0)
        median = (a[size / 2] + a[(size / 2) - 1]) / 2.0;
    else
        median = a[(size / 2)];

    //    printf("%d\n", size);
    printf("%.2f \n", median);
}

// for no set command
void no_initialization()
{
    printf("Array not initialized. Use 'set' command first.\n");
}

int main()
{
    int initiator = 0, logic = 1;
    char command[10];
    help();

    char help_c[] = "help";
    char set_c[] = "set";
    char min_c[] = "min";
    char max_c[] = "max";
    char mean_c[] = "mean";
    char stddev_c[] = "stddev";
    char summary_c[] = "summary";
    char exit_c[] = "exit";
    char hist_c[] = "hist";
    char median_c[] = "median";

    while (logic)
    {
        printf("\nEnter Command: ");
        scanf("%s", command);

        // initializing the array
        if (strcmp(command, set_c) == 0)
        {
            set();
            initiator = 1;
        }

        // min
        else if (strcmp(command, min_c) == 0)
        {
            if (initiator == 1)
                min();
            else
            {
                no_initialization();
                continue;
            }
        }

        // max
        else if (strcmp(command, max_c) == 0)
        {
            if (initiator == 1)
                max();
            else
            {
                no_initialization();
                continue;
            }
        }

        // mean
        else if (strcmp(command, mean_c) == 0)
        {
            if (initiator == 1)
                mean();
            else
            {
                no_initialization();
                continue;
            }
        }

        // stddev
        else if (strcmp(command, stddev_c) == 0)
        {
            if (initiator == 1)
                stddev();
            else
            {
                no_initialization();
                continue;
            }
        }
        //median
        else if (strcmp(command, median_c) == 0)
        {
            if (initiator == 1)
                median();
            else
            {
                no_initialization();
                continue;
            }
        }

        // summary
        else if (strcmp(command, summary_c) == 0)
        {
            if (initiator == 1)
            {
                min();
                max();
                mean();
                stddev();
            }
            else
            {
                no_initialization();
                continue;
            }
        }

        // hist
        else if (strcmp(command, hist_c) == 0)
        {
            if (initiator == 1)
                hist();
            else
            {
                no_initialization();
                continue;
            }
        }

        // for help command
        else if (strcmp(command, help_c) == 0)
            help();

        // for exit command
        else if (strcmp(command, exit_c) == 0)
            goto finish;

        // handling wrong commands by dumbheads
        else
        {
            printf("\nUnknown command. Type 'help' for list of commands.\n");
            // goto finish;
        }
    }
finish:
    printf("\n");
}