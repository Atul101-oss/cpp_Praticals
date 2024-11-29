// Write a program to sort the elements of an array using Randomized Quick Sort (the
// program should report the number of comparisons).

#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <sstream>
#include <chrono>
#include <vector>
#include <numeric>
using namespace std;
void display(vector<int> arr);


int partition(vector<int>& arr, int low, int high, int& comparisons) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            comparisons++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    comparisons++;
    return i + 1;
}

// Function to randomize pivot and partition the array
int randomizedPartition(vector<int>& arr, int low, int high, int& comparisons) {
    int randomPivotIndex = low + rand() % (high - low + 1);
    swap(arr[randomPivotIndex], arr[high]);
    return partition(arr, low, high, comparisons);
}

int randomizedQuickSort(vector<int>& arr, int low, int high, int& comparisons) {
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
    for (int i = 0; i < arr.size()-1; i++){
        cout << arr[i] << ",";
    }
    cout <<arr[arr.size()-1]<< endl;
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
    vector<int> QS_time;
    vector<int> RQS_comp;
    vector<int> RQS_time;
    vector<vector<int>> arrays(n,vector<int>(m));
    array_Generation(arrays, n, m);

    for (int i=0; i<n; i++){
        vector<int> QS_arr = arrays[i];
        vector<int> RQSarr = arrays[i];

        auto start_qs = std::chrono::high_resolution_clock::now();
        int qs = 0;
        qs = QuickSort(QS_arr, 0, QS_arr.size()-1, qs);
        auto end_qs = chrono::high_resolution_clock::now();
        chrono::duration<double, micro> duration_qs = end_qs-start_qs;
        QS_comp.push_back(qs);
        QS_time.push_back(duration_qs.count());


        auto start_rqs = std::chrono::high_resolution_clock::now();
        int rqs = 0;
        rqs = randomizedQuickSort(QS_arr, 0, QS_arr.size()-1, rqs);
        auto end_rqs = chrono::high_resolution_clock::now();
        chrono::duration<double, micro> duration_rqs = end_rqs-start_rqs;
        RQS_comp.push_back(rqs); 
        RQS_time.push_back(duration_rqs.count());
    }

    cout << "\nAvg swap count and time for a quickSort and RQS:\n";
    cout << "Quick sort swaps count & time taken : "<< static_cast<double>(accumulate(QS_comp.begin(), QS_comp.end(), 0)) / QS_comp.size();
    cout << "  " << static_cast<double>(accumulate(QS_time.begin(), QS_time.end(), 0)) / QS_time.size() <<endl;
    cout << "Ramdomized Quick sort swaps count & time taken : " << static_cast<double>(accumulate(RQS_comp.begin(), RQS_comp.end(), 0)) / RQS_comp.size();
    cout << "  " << static_cast<double>(accumulate(RQS_time.begin(), RQS_time.end(), 0)) / RQS_time.size() <<endl;
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
    int comparisons=0;

    cout << "Array before Sorting: "; display(array);
    comparisons = randomizedQuickSort(array, 0, array.size()-1, comparisons);
    cout << "Array after Sorting: ";  display(array);
    cout << "Total comparisions in RQS: " << comparisons <<endl;
    
    cout << "\nHere we're comparing QuickSort and RandomizedQuickSort\n";
    speedCheck();

    return 0;
}