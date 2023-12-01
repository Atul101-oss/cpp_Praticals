#include <stdio.h>

// Structure to represent a process
struct Process {
    int processID;
    int priority;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

// Function to sort processes based on priority (and process ID for tie-breaking)
void sortProcesses(struct Process processes[], int n) {
    struct Process temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority < processes[j + 1].priority ||
                (processes[j].priority == processes[j + 1].priority &&
                 processes[j].processID > processes[j + 1].processID)) {
                // Swap processes
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Function to calculate completion, turnaround, and waiting times
void calculateTimes(struct Process processes[], int n) {
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        // Set completion time
        processes[i].completionTime = currentTime + processes[i].burstTime;

        // Set turnaround time
        processes[i].turnaroundTime = processes[i].completionTime;

        // Set waiting time
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;

        // Update current time
        currentTime = processes[i].completionTime;
    }
}

// Function to display the process details and average times
void displayResults(struct Process processes[], int n) {
    float totalTurnaroundTime = 0, totalWaitingTime = 0;

    printf("\nProcess\tPriority\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",
               processes[i].processID, processes[i].priority,
               processes[i].burstTime, processes[i].completionTime,
               processes[i].turnaroundTime, processes[i].waitingTime);

        // Calculate total turnaround and waiting times for averages
        totalTurnaroundTime += processes[i].turnaroundTime;
        totalWaitingTime += processes[i].waitingTime;
    }

    // Display average turnaround and waiting times
    printf("\nAverage Turnaround Time: %.2f\n", totalTurnaroundTime / n);
    printf("Average Waiting Time: %.2f\n", totalWaitingTime / n);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        processes[i].processID = i + 1;
        printf("Enter priority for Process %d: ", processes[i].processID);
        scanf("%d", &processes[i].priority);
        printf("Enter burst time for Process %d: ", processes[i].processID);
        scanf("%d", &processes[i].burstTime);
    }

    // Sort processes based on priority (and process ID for tie-breaking)
    sortProcesses(processes, n);

    // Calculate completion, turnaround, and waiting times
    calculateTimes(processes, n);

    // Display process details and average times
    displayResults(processes, n);

    return 0;
}
