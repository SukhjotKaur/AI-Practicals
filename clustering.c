#include <stdio.h>
#include <stdlib.h>
float mean(float arr[], int n)
{
    int i,count=0;
    float mean, sum = 0;
    for (i = 0; i < n; i++)
    {
        if(arr[i]!=0){
        sum += arr[i];
            count++;
        }
    }
    mean = sum / count;
    return mean;
}
float small(float a, float b, float c, float d)
{
    if ((a < b) && (b < c) && (c < d))
    {
        return a;
    }
    else if ((d < c) && (c < b) && (b < a))
    {
        return d;
    }
    else if ((c < d || c < a) && (a < d || d < a) && (a < b || d < b))
    {
        return c;
    }
    else if ((b < a || b < d) && (a < d || d < a) && (d < c || a < c))
    {
        return b;
    }
}
int main()
{
    int n, a, b, c, d, o, i, j,lower,upper;
    printf("Enter the seed values: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    float hold1, hold2, hold3, hold4;
    hold1 = a, hold2 = b, hold3 = c, hold4 = d;
    printf("Enter the no of elemnts in the array: ");
    scanf("%d", &n);
    printf("Enter the upper and lower limit of the range: ");
    scanf("%d%d", &lower,&upper);
    // float g1 = a*1.0, g2 = b*1.0, g3 = c*1.0, g4 = d*1.0;
    int arr[n];
    float g1[n/2], g2[n/2], g3[n/2], g4[n/2];
    for (i = 0; i < n; i++)
    {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }
    for (j = 0; j < n / 2; j++)
    {
        float *s1 = (float *)malloc((2*n) * sizeof(float)), *s2 = (float *)malloc((2*n) * sizeof(float)), *s3 = (float *)malloc((2*n) * sizeof(float)), *s4 = (float *)malloc((2*n) * sizeof(float));
        for (o = 0; o < (2*n); o++)
        {
            s1[o] = 0.0;
            s2[o] = 0.0;
            s3[o] = 0.0;
            s4[o] = 0.0;
        }
        s1[0] = hold1, s2[0] = hold2, s3[0] = hold3, s4[0] = hold4;
        for (i = 0; i < n; i++)
        {
            float A, B, C, D, m, k;
            A = abs(a - arr[i]), B = abs(b - arr[i]), C = abs(c - arr[i]), D = abs(d - arr[i]);
            m = small(A, B, C, D);
            if (m == A)
            {
                s1[i + 1] = 1.0*arr[i];
                k = mean(s1, n);
                s1[0] = k;
            }
            else if (m == B)
            {
                s2[i + 1] = 1.0*arr[i];
                k = mean(s2, n);
                s2[0] = k;
            }
            else if (m == C)
            {
                s3[i + 1] = 1.0*arr[i];
                k = mean(s3, n);
                s3[0] = k;
            }
            else if (m == D)
            {
                s4[i + 1] = 1.0*arr[i];
                k = mean(s4, n);
                s4[0] = k;
            }
            // g1 = s1[0], g2 = s2[0], g3 = s3[0], g4 = s3[0];
        }
        hold1 = s1[0], hold2 = s2[0], hold3 = s3[0], hold4 = s4[0];

        g1[j] = s1[0];
        g2[j] = s2[0];
        g3[j] = s3[0];
        g4[j] = s4[0];
        if(g1[j-1]>=0.001*g1[j]||g2[j-1]>=0.001*g2[j]||g2[j-1]>=0.001*g2[j]||g2[j-1]>=0.001*g2[j]||g1[j-1]<=0.001*g1[j]||g2[j-1]<=0.001*g2[j]||g3[j-1]<=0.001*g3[j]||g4[j-1]<=0.001*g4[j])
        {
            break;
        }
        free(s1);
        free(s2);
        free(s3);
        free(s4);
    }
    printf("The means are : %f, %f, %f, %f",hold1,hold2,hold3,hold4);
}
