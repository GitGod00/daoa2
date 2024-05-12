#include <stdio.h>
#include <string.h>

void swap(double a[], double b[])
{
    double temp[4];
    memcpy(temp, a, sizeof(double) * 3);
    memcpy(a, b, sizeof(double) * 3);
    memcpy(b, temp, sizeof(double) * 3);
}
void main()
{
    
    double arr[][4] = {{100, 20, 0.0, 0}, {60, 10, 0.0, 1}, {120, 30, 0.0, 2}};
    int weight = 50;
    int n = sizeof(arr) / sizeof(arr[0]);
    float sol[n];
    char solc[n];
    int i, j, temp;
    float profit = 0;
    float frac = 0.0;
    for (int i = 0; i < n; i++)
    {
        solc[i] = 'x';
        sol[i] = 1.0;
    }
    
    for (i = 0; i < n; i++)
    {
        arr[i][2] = arr[i][0] / arr[i][1];
    }
    
    for (i = 0; i < n; i++)
    {
        for (j = i; j < n; j++)
        {
            if (arr[i][2] <= arr[j][2])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i][1] <= weight)
        {
            sol[i] = 1.0;                          
            solc[i] = (char)((int)arr[i][3] + 65);
            profit = profit + arr[i][0];           
            weight = weight - arr[i][1];           
        }
        else
        {
            frac = weight / arr[i][1];             
            sol[i] = frac;                         
            solc[i] = (char)((int)arr[i][3] + 65); 
            profit = profit + arr[i][0] * frac;    
            break;                                
        }
    }
    
    for (i = 0; i < n; i++)
    {
        printf("[%c %.2f] ", solc[i], sol[i]);
    }
    printf("\nProfit: %.2f", profit);
}