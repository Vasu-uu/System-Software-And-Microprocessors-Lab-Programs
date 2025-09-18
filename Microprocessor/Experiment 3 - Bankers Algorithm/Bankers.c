#include <stdio.h>

int main() {
    int n, m, i, j, k, y, ind = 0;
    int alloc[20][20], max[20][20], avail[20], need[20][20];
    int finish[20], safesequence[20], work[20];

    // Input number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    // Input Allocation Matrix
    printf("Enter the Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    // Input Maximum Matrix
    printf("Enter the Max Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    // Input Available Resources
    printf("Enter the Available Resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    // Calculate Need Matrix = Max - Allocation
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Display Need Matrix
    printf("\nNeed Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    // Initialize work = avail and finish = 0
    for (i = 0; i < m; i++)
        work[i] = avail[i];
    for (i = 0; i < n; i++)
        finish[i] = 0;

    // Find safe sequence
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    for (y = 0; y < m; y++)
                        work[y] += alloc[i][y];
                    safesequence[ind++] = i;
                    finish[i] = 1;
                }
            }
        }
    }

    // Check if system is in a safe state
    int isSafe = 1;
    for (i = 0; i < n; i++) {
        if (finish[i] == 0) {
            isSafe = 0;
            break;
        }
    }

    if (isSafe) {
        printf("\nFollowing is the SAFE Sequence:\n");
        for (i = 0; i < n; i++)
            printf("P%d ", safesequence[i]);
        printf("\n");
    } else {
        printf("\nSystem is NOT in a safe state.\n");
    }

    return 0;
}