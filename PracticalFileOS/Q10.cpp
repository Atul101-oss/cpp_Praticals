#include <stdio.h>
#include <limits.h>

// Structure to represent a process
struct Process {
    int processID;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

// Function to find the process with the shortest remaining time
int findShortestRemainingTime(struct Process processes[], int n, int currentTime) {
    int shortest = INT_MAX;
    int shortestIndex = -1;

    for (int i = 0; i < n; i++) {
        if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime < shortest && processes[i].remainingTime > 0) {
            shortest = processes[i].remainingTime;
            shortestIndex = i;
        }
    }

    return shortestIndex;
}

// Function to calculate completion, turnaround, and waiting times
void calculateTimes(struct Process processes[], int n) {
    int currentTime = 0;
    int remainingProcesses = n;

    while (remainingProcesses > 0) {
        int shortestIndex = findShortestRemainingTime(processes, n, currentTime);

        if (shortestIndex == -1) {
            currentTime++;
        } else {
            // Update remaining time for the selected process
            processes[shortestIndex].remainingTime--;

            // If the process is completed
            if (processes[shortestIndex].remainingTime == 0) {
                remainingProcesses--;

                // Set completion time
                processes[shortestIndex].completionTime = currentTime + 1;

                // Set turnaround time
                processes[shortestIndex].turnaroundTime = processes[shortestIndex].completionTime - processes[shortestIndex].arrivalTime;

                // Set waiting time
                processes[shortestIndex].waitingTime = processes[shortestIndex].turnaroundTime - processes[shortestIndex].burstTime;
            }

            currentTime++;
        }
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
        printf("Enter arrival time for Process %d: ", processes[i].processID);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time for Process %d: ", processes[i].processID);
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
    }

    // Calculate completion, turnaround, and waiting times
    calculateTimes(processes, n);

    // Display process details and average times
    displayResults(processes, n);

    return 0;
}
