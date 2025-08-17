#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, seek = 0;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nFCFS Order: %d", head);
    for (int i = 0; i < n; i++) {
        seek += abs(requests[i] - head);
        head = requests[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time (FCFS): %d\n", seek);

    return 0;
}