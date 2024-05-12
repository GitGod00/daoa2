#include <stdio.h>
#include <math.h>
int a[30], count = 0;
int place(int pos)
{
    for (int i = 1; i < pos; i++)
        if (a[i] == a[pos] || abs(a[i] - a[pos]) == abs(i - pos))
            return 0;
    return 1;
}
void print_sol(int n)
{
    count++;
    printf("\n\nSolution #%d:\n", count);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%s\t", a[i] == j ? "Q" : "*");
        printf("\n");
    }
}
void queen(int n, int k)
{
    if (k > n)
        return print_sol(n);
    for (a[k] = 1; a[k] <= n; a[k]++)
        if (place(k))
            queen(n, k + 1);
}
int main()
{
    int n;
    printf("N_Queen\n\n");
    printf("Enter the number of Queens: ");
    scanf("%d", &n);
    queen(n, 1);
    printf("\nTotal Solutions=%d", count);
    return 0;
}