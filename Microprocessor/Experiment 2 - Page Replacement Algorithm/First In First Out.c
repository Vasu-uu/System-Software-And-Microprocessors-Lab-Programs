#include <stdio.h>
#define MAX 100
void fifo(int pages[], int n, int capacity) {
    int frame[MAX], front = 0, rear = 0, count = 0, faults = 0, found;
    for (int i = 0; i < capacity; i++)
        frame[i] = -1;
    for (int i = 0; i < n; i++) {
        found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;}}
        if (!found) {
            frame[rear] = pages[i];
            rear = (rear + 1) % capacity;
            if (count < capacity) count++;
            faults++;}
        printf("Frame: ");
        for (int j = 0; j < count; j++)
            printf("%d ", frame[j]);
        printf("\n");}
    printf("\nTotal Page Faults (FIFO): %d\n", faults);}
int main() {
    int pages[MAX], n, capacity;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the page sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);}
    printf("Enter the frame capacity: ");
    scanf("%d", &capacity);
    fifo(pages, n, capacity);
    return 0;}
