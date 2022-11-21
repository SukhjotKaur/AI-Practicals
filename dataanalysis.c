#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int mean(int n,int s[n])
{
    int i;
    float mean, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += s[i];
    }
    mean = (float)(sum / n);
    return mean;
}
int variance(int n,int a[n], int avg)
{
    int i;
    float var, sum = 0.0;
    for (i = 0; i < n; i++)
    {
        sum = sum + (float)(pow((a[i] - avg), 2));
    }
    var = (float) sum / n;
    return var;
}
int max(int n, int a[n])
{
    int m = a[0], i;
    for (i = 0; i < n; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
        }
    }
    return m;
}
int min(int n, int a[n])
{
    int m = a[0], i;
    for (i = 0; i < n; i++)
    {
        if (a[i] < m)
        {
            m = a[i];
        }
    }
    return m;
}
int main()
{
    int n, i;
//     printf("\n\nThe series is:\n");
    int series[] = {0, 2, 1, 22, 2, 1, 3, 5, 9, 15, 8, 10, 10, 11, 10, 14, 20, 25, 27, 58, 78, 69, 94, 74, 86, 73, 153, 136,
                    120, 187, 309, 424, 486, 560, 579, 609, 484, 573, 565, 813, 871, 854, 758, 1243, 1031, 886, 1061, 922, 1371,
                    1580, 1239, 1537, 1292, 1667, 1408, 1835, 1607, 1568, 1902, 1705, 1801, 2391};
    n = sizeof(series) / sizeof(series[0]);
    float avg = mean(n,series);
    float var = variance(n,series, avg);
    float dev = sqrt(var);
    printf("\n\nThe avg, variance and deviations are: %0.2f, %0.2f, %0.2f\n", avg, var, dev);
    int grad[n - 1], lap[n - 2];
    printf("\nThe gradient is: \n");
    for (i = 1; i < n; i++)
    {
        grad[i - 1] = series[i] - series[i - 1];
        printf("%d,\t", grad[i - 1]);
    }
    printf("\n\nThe laplacian is: \n");
    for (i = 1; i < n - 2; i++)
    {
        lap[i - 1] = grad[i] - grad[i - 1];
        printf("%d,\t", lap[i - 1]);
    }
    int filter[5] = {1, 1, 1, 1, 1};
    int sum = 0;
    for (i = 0; i < sizeof(filter) / sizeof(filter[1]); i++)
    {
        sum += filter[i];
    }
    printf("\n\nThe filtered array:\n");
    float filser[n];
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            filser[i] = (float)(series[i] * 3 + series[i + 1] + series[i + 2]) / sum;
        }
        else if (i == 1)
        {
            filser[i] = (float)(series[i - 1] * 2 + series[i] + series[i + 1] + series[i + 2]) / sum;
        }
        else if (i == n - 2)
        {
            filser[i] = (float)(series[i - 2] + series[i - 1] + series[i] + series[i + 1] * 2) / sum;
        }
        else if (i == n - 1)
        {
            filser[i] = (float)(series[i - 2] + series[i - 1] + series[i] * 3) / sum;
        }
        else
        {
            filser[i] = (float)(series[i - 2] + series[i - 1] + series[i] + series[i + 1] + series[i + 2]) / sum;
        }
        printf("%0.2f,\t", filser[i]);
    }
    float v[100], b;
    v[0] = 0.0;
    printf("\n\nThe Moving averages:\n");
    for (b = 0.1; b < 1.0; b += 0.1)
    {
        printf("\n\nThe value of beta is %0.2f\n", b);
        for (i = 1; i < n; i++)
        {
            v[i] = b * ((float)series[i]) + (1.0 - b) * v[i - 1];
            printf("%0.2f,\t", v[i]);
        }
    }
    float meanorm[n];
    int maxx = max(n, series);
    int minn = min(n, series);
    printf("\n\nThe mean score normalization is:\n");
    for (i = 0; i < n; i++)
    {
        meanorm[i] = (float)(abs((float)series[i] - avg)) / (maxx - minn);
        printf("%0.2f,\t", meanorm[i]);
    }
    float adam[100], a = 0.001;
    printf("\n\nThe Adam optimization series:\n");
    for (i = 0; i < n; i++)
    {
        // adam[i]=(float)((series[i]-a*abs(grad[i])/(sqrt(lap[i])+1.0)));
        adam[i] = (float)(series[i] - a * abs(grad[i]));
        printf("%0.2f,\t", adam[i]);
    }
    return 0;
}
