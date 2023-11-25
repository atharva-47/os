#include <stdio.h>
#include <limits.h>

void sjf(int n) {
    int arrival[n], burst[n], wait = 0, turn = 0, remaining[n];

    printf("Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Arrival Time for P%d: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Burst Time for P%d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
    }

    printf("\nGantt Chart:\n");
    while (turn < INT_MAX) {
        int shortest = INT_MAX, idx = -1;
        for (int i = 0; i < n; i++) {
            if (arrival[i] <= turn && remaining[i] < shortest && remaining[i] > 0) {
                shortest = remaining[i];
                idx = i;
            }
        }

        if (idx == -1) break;

        printf("| P%d ", idx + 1);
        turn += remaining[idx];
        remaining[idx] = 0;

        wait += turn - arrival[idx] - burst[idx];
    }

    printf("|\n\nProcess\t Turnaround\t Waiting\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t %d\t\t %d\n", i + 1, turn - arrival[i], turn - arrival[i] - burst[i]);

    float avg_turn = (float)turn / n, avg_wait = (float)wait / n;
    printf("\nAvg Turnaround: %.2f\nAvg Waiting: %.2f\n", avg_turn, avg_wait);
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    sjf(num_processes);
    return 0;
}

