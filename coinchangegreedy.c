#include <stdio.h>
void main()
{
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 200, 2000};
    int value = 93;
    int n = sizeof(arr) / sizeof(arr[0]);
    int sol[n];
    int i;
    
    for (int i = 0; i < n; i++)
    {
        sol[i] = 0;
    }
    for (i = n - 1; i >= 0; i--)
    {
        while (arr[i] <= value)
        {
            sol[i] += 1;
            value = value - arr[i];
        }
    }
    
    for (i = 0; i < n; i++)
    {
        printf("%d ", sol[i]);
    }
}