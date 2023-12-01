#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure to represent a memory block
struct MemoryBlock {
    int processID;
    int size;
    int allocated;
};

// Function to display the memory status
void displayMemory(struct MemoryBlock memory[], int numBlocks) {
    printf("\nMemory Status:\n");
    printf("Block\tProcess ID\tSize\tAllocated\n");

    for (int i = 0; i < numBlocks; i++) {
        printf("%d\t", i + 1);
        if (memory[i].allocated) {
            printf("%d\t\t%d\tYes\n", memory[i].processID, memory[i].size);
        } else {
            printf("-\t\t%d\tNo\n", memory[i].size);
        }
    }
}

// Function to allocate memory using First-Fit strategy
void firstFit(struct MemoryBlock memory[], int numBlocks, int processID, int size) {
    for (int i = 0; i < numBlocks; i++) {
        if (!memory[i].allocated && memory[i].size >= size) {
            memory[i].allocated = 1;
            memory[i].processID = processID;
            break;
        }
    }
}

// Function to allocate memory using Best-Fit strategy
void bestFit(struct MemoryBlock memory[], int numBlocks, int processID, int size) {
    int bestFitIndex = -1;
    int bestFitSize = INT_MAX;

    for (int i = 0; i < numBlocks; i++) {
        if (!memory[i].allocated && memory[i].size >= size) {
            if (memory[i].size < bestFitSize) {
                bestFitSize = memory[i].size;
                bestFitIndex = i;
            }
        }
    }

    if (bestFitIndex != -1) {
        memory[bestFitIndex].allocated = 1;
        memory[bestFitIndex].processID = processID;
    }
}

// Function to allocate memory using Worst-Fit strategy
void worstFit(struct MemoryBlock memory[], int numBlocks, int processID, int size) {
    int worstFitIndex = -1;
    int worstFitSize = -1;

    for (int i = 0; i < numBlocks; i++) {
        if (!memory[i].allocated && memory[i].size >= size) {
            if (memory[i].size > worstFitSize) {
                worstFitSize = memory[i].size;
                worstFitIndex = i;
            }
        }
    }

    if (worstFitIndex != -1) {
        memory[worstFitIndex].allocated = 1;
        memory[worstFitIndex].processID = processID;
    }
}

int main() {
    int numBlocks;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &numBlocks);

    struct MemoryBlock memory[numBlocks];

    // Initialize memory blocks
    for (int i = 0; i < numBlocks; i++) {
        memory[i].processID = -1;
        memory[i].allocated = 0;

        printf("Enter size for Memory Block %d: ", i + 1);
        scanf("%d", &memory[i].size);
    }

    int numProcesses;

    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    for (int i = 0; i < numProcesses; i++) {
        int processID, size;
        printf("\nEnter details for Process %d:\n", i + 1);
        printf("Enter Process ID: ");
        scanf("%d", &processID);
        printf("Enter Size: ");
        scanf("%d", &size);

        // First-Fit
        firstFit(memory, numBlocks, processID, size);
        displayMemory(memory, numBlocks);

        // Best-Fit
        bestFit(memory, numBlocks, processID, size);
        displayMemory(memory, numBlocks);

        // Worst-Fit
        worstFit(memory, numBlocks, processID, size);
        displayMemory(memory, numBlocks);
    }

    return 0;
}
