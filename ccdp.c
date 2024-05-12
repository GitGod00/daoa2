#include <stdio.h>
int main()
{
    int i, j;
    int n;
    int N;
    int d[10];
    int dp[10][10];
    int sol[10] = {0};
    int count = 0;
    printf("Enter the number of coins: ");
    scanf("%d", &n);
    printf("Enter the sum: ");
    scanf("%d", &N);
    printf("Enter the coin values:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }
    printf("\nTable : \n");
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= N; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (i == 1)
            {
                dp[i][j] = 1 + dp[i][j - d[i - 1]];
            }
            else if (j < d[i - 1])
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                if (dp[i - 1][j] < 1 + dp[i][j - d[i - 1]])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = 1 + dp[i][j - d[i - 1]];
                }
            }
        }
    }
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= N; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    i = n;
    j = N;
    printf("\nCoins Used : ");
    while (j > 0 && i > 0)
    {
        if (dp[i][j] == dp[i - 1][j])
        {
            i--;
        }
        else
        {
            sol[count] = d[i - 1];
            count++;
            printf("%d ", d[i - 1]);
            j = j - d[i - 1];
        }
    }
    return 0;
}
