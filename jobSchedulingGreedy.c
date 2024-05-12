#include <stdio.h>
#include <stdlib.h>

#define MAX_JOBS 10

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

void jobScheduling(Job jobs[], int n);

int compare(const void *a, const void *b) {
    return (((Job *)b)->profit - ((Job *)a)->profit);
}

void jobScheduling(Job jobs[], int n) {
    int i, j, max_profit = 0;
    int slot[MAX_JOBS] = {0};

    qsort(jobs, n, sizeof(Job), compare);

    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = jobs[i].id;
                max_profit += jobs[i].profit;
                break;
            }
        }
    }

    printf("The sequence of jobs for maximum profit: ");
    for (i = 0; i < n; i++) {
        if (slot[i] != 0)
            printf("%d ", slot[i]);
    }
    printf("\nMaximum profit: %d\n", max_profit);
}

int main() {
    int n, i;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    Job jobs[n];
    printf("Enter the deadline and profit of each job:\n");
    for (i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
        jobs[i].id = i + 1;
    }

    jobScheduling(jobs, n);

    return 0;
}
