#include <stdio.h>

// Structure to represent a process
struct Process {
    int processID;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

// Function to calculate completion, turnaround, and waiting times
void calculateTimes(struct Process processes[], int n) {
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        // Set completion time
        processes[i].completionTime = currentTime + processes[i].burstTime;

        // Set turnaround time
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;

        // Set waiting time
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;

        // Update current time
        currentTime = processes[i].completionTime;
    }
}

// Function to display the process details and average times
void displayResults(struct Process processes[], int n) {
    float totalTurnaroundTime = 0, totalWaitingTime = 0;

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",
               processes[i].processID, processes[i].arrivalTime,
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
        processes[i].arrivalTime = 0; // Assume arrival time is 0 for simplicity
        printf("Enter burst time for Process %d: ", processes[i].processID);
        scanf("%d", &processes[i].burstTime);
    }

    // Calculate completion, turnaround, and waiting times
    calculateTimes(processes, n);

    // Display process details and average times
    displayResults(processes, n);

    return 0;
}