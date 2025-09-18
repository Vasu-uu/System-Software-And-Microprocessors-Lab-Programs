#include <stdio.h>

struct Process {
    int id;
    int at;  
    int bt;  
    int ct;  
    int tat; 
    int wt;  
    int isCompleted; 
};

int main() {
    int n, completed = 0, currentTime = 0;
    float totalWT = 0, totalTAT = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", p[i].id);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].isCompleted = 0;
    }

    while (completed < n) {
        int minIndex = -1;

        for (int i = 0; i < n; i++) {
            if (!p[i].isCompleted && p[i].at <= currentTime) {
                if (minIndex == -1 || p[i].bt < p[minIndex].bt) {
                    minIndex = i;
                }
            }
        }

        if (minIndex == -1) {
            currentTime++;
        } else {
            p[minIndex].ct = currentTime + p[minIndex].bt;
            p[minIndex].tat = p[minIndex].ct - p[minIndex].at; 
            p[minIndex].wt = p[minIndex].tat - p[minIndex].bt; 
            totalWT += p[minIndex].wt;
            totalTAT += p[minIndex].tat;
            p[minIndex].isCompleted = 1; 
            completed++; 
            currentTime = p[minIndex].ct; 
        }
    }
    printf("\nPROCESS\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("\nAverage Waiting Time: %.2f", totalWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);
    return 0;
}
