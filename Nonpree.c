#include <stdio.h>
#include <limits.h>

void priority(int n) {
    int arrival[n], burst[n], priority[n], wait = 0, turn = 0;

    printf("Arrival Time, Burst Time, and Priority for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Arrival, Burst, Priority for P%d: ", i + 1);
        scanf("%d %d %d", &arrival[i], &burst[i], &priority[i]);
    }

    printf("\nGantt Chart:\n");
    while (turn < INT_MAX) {
        int min_priority = INT_MAX, min_index = -1;
        for (int i = 0; i < n; i++) {
            if (arrival[i] <= turn && priority[i] < min_priority && burst[i] > 0) {
                min_priority = priority[i];
                min_index = i;
            }
        }

        if (min_index == -1) break;

        printf("| P%d ", min_index + 1);
        turn += burst[min_index];
        wait += turn - arrival[min_index] - burst[min_index];
        burst[min_index] = 0;
    }

    printf("|\n\nProcess\t Turnaround\t Waiting\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t %d\t\t %d\n", i + 1, turn - arrival[i], turn - arrival[i] - burst[i]);

    printf("\nAvg Turnaround: %.2f\nAvg Waiting: %.2f\n", (float)turn / n, (float)wait / n);
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    priority(num_processes);
    return 0;
}

