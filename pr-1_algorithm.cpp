#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()

using namespace std;

int comparisonCount = 0;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisonCount++;  // Increment comparison count
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int randomizedPartition(int arr[], int low, int high) {
    int randomPivotIndex = low + rand() % (high - low + 1);
    swap(arr[high], arr[randomPivotIndex]);
    return partition(arr, low, high);
}

void randomizedQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

int main() {
    srand(time(0));  // Seed for random number generation

    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    randomizedQuickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Total comparisons: " << comparisonCount << endl;

    return 0;
}
