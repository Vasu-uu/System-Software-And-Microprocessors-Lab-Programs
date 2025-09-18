#include <stdio.h>

struct Process {
    int id, at, bt, ct, tat, wt, pri;
};

int main() {
    int currenttime = 0, n;
    float totalwt = 0, totaltat = 0;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    struct Process p[n];  

    for(int i = 0; i < n; i++) {
        p[i].id = i + 1;
        printf("Enter arrival time and burst time for Process %d: ", p[i].id);
        scanf("%d %d", &p[i].at, &p[i].bt);
        printf("Enter priority: ");
        scanf("%d", &p[i].pri);
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(p[j].at > p[j + 1].at || (p[j].at == p[j + 1].at && p[j].pri > p[j + 1].pri)) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(currenttime < p[i].at)
            currenttime = p[i].at;

        p[i].ct = currenttime + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        totalwt += p[i].wt;
        totaltat += p[i].tat;
        currenttime = p[i].ct;
    }
    printf("\nProcess\tPri\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
               p[i].id, p[i].pri, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalwt / n);
    printf("Average Turnaround Time: %.2f\n", totaltat / n);

    return 0;
}

