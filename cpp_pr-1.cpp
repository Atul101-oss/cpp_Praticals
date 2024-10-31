// Write a program to sort the elements of an array using Randomized Quick Sort (the
// program should report the number of comparisons).

#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <sstream>
#include <vector>
using namespace std;


int partition(vector<int>& arr, int low, int high, int& comparisons) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to randomize pivot and partition the array
int randomizedPartition(vector<int>& arr, int low, int high, int& comparisons) {
    int randomPivotIndex = low + rand() % (high - low + 1);
    swap(arr[randomPivotIndex], arr[high]);
    return partition(arr, low, high, comparisons);
}

int randomizedQuickSort(vector<int>& arr, int low, int high, int comparisons) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high, comparisons);
        randomizedQuickSort(arr, low, pi - 1, comparisons);
        randomizedQuickSort(arr, pi + 1, high, comparisons);
    }
    return comparisons;
}

int QuickSort(vector<int>& arr, int low, int high, int comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        randomizedQuickSort(arr, low, pi - 1, comparisons);
        randomizedQuickSort(arr, pi + 1, high, comparisons);
    }
    return comparisons;
}


void display(vector<int> arr){
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void array_Generation(vector<vector<int>>& arrays, int no_array, int array_legth){
    for (int arr=0; arr<no_array; arr++){
        for (int j=0; j<array_legth; j++){
            arrays[arr][j]=rand()%100;
        }
    }
}

void speedCheck(){
    int n,m;
    cout << "enter number of arrays: "; cin >> n;
    cout << "enter length of array : "; cin >> m;
    vector<int> QS_comp;
    vector<int> RQS_comp;
    vector<vector<int>> arrays(n,vector<int>(m));
    array_Generation(arrays, n, m);

    for (int i=0; i<n; i++){
        vector<int> QS_arr = arrays[i];
        vector<int> RQSarr = arrays[i];
        display(QS_arr);
        display(RQSarr);
        QS_comp.push_back(QuickSort(QS_arr, 0, QS_arr.size()-1, 0));
        RQS_comp.push_back(randomizedQuickSort(RQSarr, 0, RQSarr.size()-1, 0));
    }

    cout << "comparisons of QuickSort Algorithm: "; display(QS_comp);
    cout << "comparisons of RandomizedQuickSort: "; display(RQS_comp);
}

void arr_input(vector<int>& arr){
    string line;
    cout << "Enter array's elements (separated by spaces): ";
    getline(cin, line);  // Read entire line of input

    stringstream ss(line);  // Create a stringstream from the line
    int number;
    while (ss >> number) {  // Extract integers from the stringstream
        arr.push_back(number);
    }
}

int main() {
    vector<int> array;
    arr_input(array);

    cout << "Array before Sorting: "; display(array);
    int comparisons = randomizedQuickSort(array, 0, array.size(), 0);
    cout << "Array after Sorting: ";  display(array);
    cout << "Total comparisions in RQS: " << comparisons <<endl;
    
    cout << "\nHere we're comparing QuickSort and RandomizedQuickSort\n";
    speedCheck();

    return 0;
}