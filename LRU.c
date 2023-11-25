#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 20
#define MAX_REFERENCES 50

int frames[MAX_FRAMES], ref[MAX_REFERENCES], faults = 0, m, n;

void accept() {
    printf("Enter no of frames:");
    scanf("%d", &n);
    printf("Enter no of references:");
    scanf("%d", &m);
    printf("Enter references string:\n");
    for (int i = 0; i < m; i++) {
        printf("[%d]=", i);
        scanf("%d", &ref[i]);
    }
}

int findLRU(int indexes[MAX_FRAMES], int n) {
    int minIndex = 0, minValue = indexes[0];
    for (int i = 1; i < n; i++) {
        if (indexes[i] < minValue) {
            minValue = indexes[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void LRU() {
    int indexes[MAX_FRAMES] = {0};
    for (int i = 0; i < m; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (frames[j] == ref[i]) {
                found = true;
                indexes[j] = i;
                break;
            }
        }
        if (!found) {
            faults++;
            int minIndex = findLRU(indexes, n);
            frames[minIndex] = ref[i];
            indexes[minIndex] = i;
        }
    }
}

int main() {
    accept();
    LRU();
    printf("\nTotal page faults:%d\n", faults);
    return 0;
}
   
     
