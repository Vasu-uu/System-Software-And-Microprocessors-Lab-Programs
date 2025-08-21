#include <stdio.h>

int main() {
    int m, n;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);
    int blockSize[m], blockAllocated[m];
    printf("Enter sizes of %d memory blocks: ", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
        blockAllocated[i] = 0; // initially free
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);
    int processSize[n], allocation[n];

    printf("Enter sizes of %d processes: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
        allocation[i] = -1; // initially not allocated
    }

    // Worst Fit logic
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockAllocated[j] == 0 && blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockAllocated[worstIdx] = 1; // mark block as used
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
