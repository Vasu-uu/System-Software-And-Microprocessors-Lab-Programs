#include <stdio.h>

struct Process {
    int id;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void sortByArrival(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    float totalWT = 0, totalTAT = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", p[i].id);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    sortByArrival(p, n);

    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at)
            currentTime = p[i].at;

        p[i].ct = currentTime + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        totalWT += p[i].wt;
        totalTAT += p[i].tat;

        currentTime = p[i].ct;
    }

    printf("\nPROCESS\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time: %.2f", totalWT / n);
    printf("\nAverage Turnaround Time: %.2f\n", totalTAT / n);

    printf("\nGantt Chart:\n");

    currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at)
            currentTime = p[i].at;
        printf(" _______");
        currentTime = currentTime + p[i].bt;
    }
    printf("\n");

    currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at)
            currentTime = p[i].at;
        printf("|  P%d   ", p[i].id);
        currentTime = currentTime + p[i].bt;
    }
    printf("|\n");

    currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at)
            currentTime = p[i].at;
        printf(" ‾‾‾‾‾‾‾");
        currentTime = currentTime + p[i].bt;
    }
    printf("\n");

    currentTime = 0;
    printf("%d", currentTime);
    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at)
            currentTime = p[i].at;
        int end = currentTime + p[i].bt;
        printf("      %d", end);
        currentTime = end;
    }
    printf("\n");

    return 0;
}
