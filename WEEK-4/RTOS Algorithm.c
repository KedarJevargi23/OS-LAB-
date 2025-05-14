#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int period;
    int burst_time;
    int deadline;
} Task;

int main() {
    int n, choice;
    printf("Choose Scheduling Algorithm:\n");
    printf("1. Rate-Monotonic Scheduling\n");
    printf("2. Earliest-Deadline-First Scheduling\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the number of PIDs: ");
    scanf("%d", &n);

    Task tasks[n];
    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        if (choice == 1) {
            printf("Enter period and burst time for PID %d: ", tasks[i].id);
            scanf("%d %d", &tasks[i].period, &tasks[i].burst_time);
        } else if (choice == 2) {
            printf("Enter deadline, period and burst time for PID %d: ", tasks[i].id);
            scanf("%d %d %d", &tasks[i].deadline, &tasks[i].period, &tasks[i].burst_time);
        }
    }

    if (choice == 1) {
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (tasks[i].period > tasks[j].period) {
                    Task temp = tasks[i];
                    tasks[i] = tasks[j];
                    tasks[j] = temp;
                }
            }
        }
        printf("\nRate-Monotonic Scheduling Gantt Chart:\n");
    } else if (choice == 2) {
     
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (tasks[i].deadline > tasks[j].deadline) {
                    Task temp = tasks[i];
                    tasks[i] = tasks[j];
                    tasks[j] = temp;
                }
            }
        }
        printf("\nEarliest-Deadline-First Scheduling Gantt Chart:\n");
    } else {
        printf("Invalid choice!\n");
        return 0;
    }

    int time = 0;
    printf("\n| Time  | Task Execution       |\n");
    printf("--------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("| %2d - %2d | PID %d (Period: %d) |\n", time, time + tasks[i].burst_time, tasks[i].id, tasks[i].period);
        time += tasks[i].burst_time;
    }
    printf("--------------------------------\n");

    return 0;
}
