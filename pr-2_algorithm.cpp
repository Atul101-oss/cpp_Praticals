// Write a program to find the ith smallest element of an array using Randomized Select. 

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
void display(vector<int>& arr){
    for (int elem:arr){
        cout << elem << " ";
    }
    cout << endl;
}

int partition(vector<int>& arr, int p, int r){
    // cout << "good ";
    int i = p-1;
    for (int j=p; j<r; j++){
        if (arr[j]<arr[r]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    // cout << "p\n";
    return i+1;
}

int randomPartition(vector<int>& arr, int p, int r){
    // cout << "good ";
    int pi = p+(rand()%(r-p+1));
    swap(arr[pi],arr[r]);
    pi = partition(arr,p,r);
    // cout << "rp\n";
    return pi;
}

int quickSort(vector<int>& arr, int p, int r, int key){
    // cout << "good ";
    int pi = randomPartition(arr,p,r);
    if (key<pi){
        quickSort(arr,p,pi-1,key);
    }
    else if(key>pi){
        quickSort(arr,pi+1,r,key);
    }
    // cout << "quickSort";
    return arr[key-1];
}

int ith_element(vector<int> arr, int key){
    // cout << "Good-->";display(arr);
    return quickSort(arr,0,arr.size()-1, key);
}

vector<int> get_array(){
    vector<int> arr;
    string array;
    getline(cin,array);
    stringstream ss(array);
    int elem;
    while (ss >> elem){
        arr.push_back(elem);
    }
    return arr;
}

int main(){
    int key;

    cout << "Enter array(separated by space) : ";
    vector<int> arr = get_array();
    cout << "Enter ith position : "; cin>>key;

    cout << "ith smallest value --> "<< ith_element(arr,key)<<endl;
    return 0;
}