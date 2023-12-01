#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_NUMBERS 1000

// Structure to pass arguments to the thread function
struct ThreadArgs {
    int* numbers;
    int start;
    int end;
};

// Function to calculate the sum of a sublist
void* calculateSum(void* args) {
    struct ThreadArgs* threadArgs = (struct ThreadArgs*)args;
    int* numbers = threadArgs->numbers;
    int start = threadArgs->start;
    int end = threadArgs->end;

    int sum = 0;
    for (int i = start; i < end; i++) {
        sum += numbers[i];
    }

    // Allocate memory to store the result
    int* result = (int*)malloc(sizeof(int));
    *result = sum;

    pthread_exit(result);
}

int main() {
    int n;

    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_NUMBERS) {
        printf("Invalid number of elements. Please enter a value between 1 and %d.\n", MAX_NUMBERS);
        return 1;
    }

    int numbers[MAX_NUMBERS];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    // Create two threads
    pthread_t thread1, thread2;

    // Divide the array into two halves
    int mid = n / 2;

    // Arguments for the first thread
    struct ThreadArgs args1 = {numbers, 0, mid};

    // Arguments for the second thread
    struct ThreadArgs args2 = {numbers, mid, n};

    // Variables to store thread results
    int* result1;
    int* result2;

    // Create the first thread
    if (pthread_create(&thread1, NULL, calculateSum, (void*)&args1) != 0) {
        fprintf(stderr, "Error creating thread 1.\n");
        return 1;
    }

    // Create the second thread
    if (pthread_create(&thread2, NULL, calculateSum, (void*)&args2) != 0) {
        fprintf(stderr, "Error creating thread 2.\n");
        return 1;
    }

    // Wait for the first thread to finish
    if (pthread_join(thread1, (void**)&result1) != 0) {
        fprintf(stderr, "Error joining thread 1.\n");
        return 1;
    }

    // Wait for the second thread to finish
    if (pthread_join(thread2, (void**)&result2) != 0) {
        fprintf(stderr, "Error joining thread 2.\n");
        return 1;
    }

    // Calculate the final sum
    int finalSum = *result1 + *result2;

    // Display the result
    printf("Sum of the numbers: %d\n", finalSum);

    // Free allocated memory
    free(result1);
    free(result2);

    return 0;
}
