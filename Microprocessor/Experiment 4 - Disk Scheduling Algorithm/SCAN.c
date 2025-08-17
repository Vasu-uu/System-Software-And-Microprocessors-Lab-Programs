#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

int main() {
    int n, head, disk_size, seek = 0;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the requests: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    int sorted[n];
    for (int i = 0; i < n; i++) sorted[i] = requests[i];
    sort(sorted, n);

    int pos = 0;
    while (pos < n && sorted[pos] < head) pos++;

    printf("\nSCAN Order: %d", head);

    // Moving right
    for (int i = pos; i < n; i++) {
        seek += abs(sorted[i] - head);
        head = sorted[i];
        printf(" -> %d", head);
    }

    // Go to end
    if (head != disk_size - 1) {
        seek += abs((disk_size - 1) - head);
        head = disk_size - 1;
        printf(" -> %d", head);
    }

    // Reverse to left
    for (int i = pos - 1; i >= 0; i--) {
        seek += abs(sorted[i] - head);
        head = sorted[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Seek Time (SCAN): %d\n", seek);
    return 0;
}