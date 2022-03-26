#include<bits/stdc++.h>
using namespace std;

void InPlaceMergeShellSort(int arr[], int start, int mid, int end) {
    int len = end - start + 1; // len is the length of the combined list 
    int h = ceil(len / 2.0); // h is the interval length for which we will sort the list   

    while(h >= 1) {
        int idx = start;
        while(idx + h <= end) {
            if(arr[idx] > arr[idx + h]) {
                swap(arr[idx], arr[idx + h]);
            }
            idx = idx + 1;
        }
        if(h == 1) {
            break;
        }
        h = ceil(h / 2.0);
    }
}

void InPlaceMergeSort(int arr[], int low, int high) {
	// checking if the size of array is 1.if the size is 1 then the array is already sortedand we need not do anything
    if(low == high) {
        return;
    }
    /*
    we need to divide the array into two almost equal halves
    in case of an odd length array, the size of the halves will differ   by 1
    we divide the array [low, high] into [low, mid] and [mid + 1, high]
    mid is the midpoint of the range [low, high]
    */
    int mid = (low + high) / 2;
    InPlaceMergeSort(arr, low, mid); // recursive call to sort arr[low, mid]
    InPlaceMergeSort(arr, mid + 1, high);// recursive call to sort arr[mid + 1, high]
    InPlaceMergeShellSort(arr, low, mid, high);  // merging both sorted subarrays arr[low, mid] and arr[mid + 1, high] to form sorted array[low, high]

}

void InPlaceMergeSort(int arr[], int n) {
    InPlaceMergeSort(arr, 0, n - 1);
}

int main() {   
    int arr[] = {2, 5, 7, 10, 3, 6, 8, 11};
    int n = sizeof(arr) / sizeof(int);
    cout << "Array before sorting : \n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
    InPlaceMergeSort(arr, n);
    cout << "Array after sorting : \n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

