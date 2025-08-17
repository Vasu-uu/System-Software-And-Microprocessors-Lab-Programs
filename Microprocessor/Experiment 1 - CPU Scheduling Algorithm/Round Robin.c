#include <stdio.h>

struct Process {
    int id;
    int at; 
    int bt; 
    int ct; 
    int tat; 
    int wt; 
    int remaining_bt; 
};

int main() {
    int n, timeQuantum, currentTime = 0, completed = 0;
    float totalWT = 0, totalTAT = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", p[i].id);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].remaining_bt = p[i].bt; 
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &timeQuantum);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    while (completed < n) {
        int executed = 0; 

        for (int i = 0; i < n; i++) {
            if (p[i].remaining_bt > 0 && p[i].at <= currentTime) {
                executed = 1;

                if (p[i].remaining_bt <= timeQuantum) {
                    currentTime += p[i].remaining_bt;
                    p[i].remaining_bt = 0;
                    p[i].ct = currentTime; 
                    p[i].tat = p[i].ct - p[i].at; 
                    p[i].wt = p[i].tat - p[i].bt;
                    totalWT += p[i].wt;
                    totalTAT += p[i].tat;
                    completed++;
                } else {
                    currentTime += timeQuantum;
                    p[i].remaining_bt -= timeQuantum;
                }
            }
        }
        if (!executed) {
            currentTime++;
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
