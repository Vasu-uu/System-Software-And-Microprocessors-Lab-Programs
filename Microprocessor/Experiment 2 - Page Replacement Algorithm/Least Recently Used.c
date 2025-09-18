#include <stdio.h>
#define MAX 100
void lru(int pages[], int n, int capacity) {
    int frame[MAX], time[MAX];
    int faults = 0, count = 0;
    for (int i = 0; i < capacity; i++) {
        frame[i] = -1;
        time[i] = 0;}
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                time[j] = i; 
                break;}}
        if (!found) {
            int pos = 0;
            if (count < capacity) {
                pos = count;
                count++;
            } else {
                int lru_time = time[0];
                for (int j = 1; j < capacity; j++) {
                    if (time[j] < lru_time) {
                        lru_time = time[j];
                        pos = j;}}}
            frame[pos] = pages[i];
            time[pos] = i;
            faults++;}
        printf("Frame: ");
        for (int j = 0; j < count; j++)
            printf("%d ", frame[j]);
        printf("\n");}
    printf("\nTotal Page Faults (LRU): %d\n", faults);}
int main() {
    int pages[MAX], n, capacity;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the page sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);}
    printf("Enter the frame capacity: ");
    scanf("%d", &capacity);
    lru(pages, n, capacity);
    return 0;}

