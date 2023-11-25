#include <stdio.h>

void fcfs(int n) {
    int arrival[n], burst[n], wait = 0, turn = 0;

    printf("Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d Arrival & Burst: ", i + 1);
        scanf("%d %d", &arrival[i], &burst[i]);
    }

    printf("\nGantt Chart:\n|");
    for (int i = 0; i < n; i++) {
        while (turn < arrival[i] && printf(" Idle |")) turn++;
        printf(" P%d |", i + 1);
        turn += burst[i], wait += turn - arrival[i] - burst[i];
    }

    printf("\n\nProcess\t Turnaround\t Waiting\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t %d\t\t %d\n", i + 1, turn - arrival[i], turn - arrival[i] - burst[i]);

    printf("\nAvg Turnaround: %.2f\nAvg Waiting: %.2f\n", (float)turn / n, (float)wait / n);
}

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    fcfs(num_processes);
    return 0;
}

