#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define IO_WAITING_TIME 2

void preemptive_priority(int n) {
    int arrival[n], burst[n], priority[n], wait = 0, turn = 0, remaining[n];
    srand(time(NULL));

    printf("Arrival, Priority, and Burst for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Arrival, Priority, Burst for P%d: ", i + 1);
        scanf("%d %d %d", &arrival[i], &priority[i], &burst[i]);
        remaining[i] = burst[i];
    }

    printf("\nGantt Chart:\n");
    while (turn < INT_MAX) {
        int min_priority = INT_MAX, min_index = -1;
        for (int i = 0; i < n; i++) {
            if (arrival[i] <= turn && priority[i] < min_priority && remaining[i] > 0) {
                min_priority = priority[i];
                min_index = i;
            }
        }

        if (min_index == -1) break;

        printf("| P%d ", min_index + 1);
        int random_burst = rand() % 10 + 1;
        turn += (random_burst < remaining[min_index]) ? random_burst : remaining[min_index];
        remaining[min_index] -= (random_burst < remaining[min_index]) ? random_burst : remaining[min_index];

        wait += turn - arrival[min_index] - burst[min_index] - IO_WAITING_TIME;
    }

    printf("|\n\nProcess\t Turnaround\t Waiting\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t %d\t\t %d\n", i + 1, turn - arrival[i], turn - arrival[i] - burst[i] - IO_WAITING_TIME);

    printf("\nAvg Turnaround: %.2f\nAvg Waiting: %.2f\n", (float)turn / n, (float)wait / n);
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    preemptive_priority(num_processes);
    return 0;
}

