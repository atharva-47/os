#include <stdio.h>
#include <limits.h>

void preemptive_sjf(int n) {
    int arrival[n], burst[n], remaining[n], waiting[n], turnaround[n];
    int total_completion = 0, total_wait = 0, total_turnaround = 0;
    int time = 0, min_time = INT_MAX, current_process = -1;

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Arrival Time for Process %d: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Burst Time for Process %d: ", i + 1);
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
    }

    printf("\nGantt Chart:\n");
    while (total_completion < n) {
        for (int i = 0; i < n; i++) {
            if (arrival[i] <= time && remaining[i] < min_time && remaining[i] > 0) {
                min_time = remaining[i];
                current_process = i;
            }
        }

        if (current_process == -1) {
            time++;
            continue;
        }

        printf("| P%d ", current_process + 1);
        remaining[current_process]--;
        time++;

        if (remaining[current_process] == 0) {
            total_completion++;
            waiting[current_process] = time - arrival[current_process] - burst[current_process];
            turnaround[current_process] = time - arrival[current_process];
            total_wait += waiting[current_process];
            total_turnaround += turnaround[current_process];
            min_time = INT_MAX;
            current_process = -1;
        }
    }

    printf("|\n\nProcess\t Turnaround\t Waiting\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t %d\t\t %d\n", i + 1, turnaround[i], waiting[i]);

    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround / n);
    printf("Average Waiting Time: %.2f\n", (float)total_wait / n);
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    preemptive_sjf(num_processes);

    return 0;
}

