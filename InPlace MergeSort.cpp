#include<bits/stdc++.h>
using namespace std;

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
    InPlaceMergeSort(arr, low, mid);// recursive call to sort arr[low, mid]
    InPlaceMergeSort(arr, mid + 1, high);// recursive call to sort arr[mid + 1, high]
    InPlaceMergeSort(arr, low,mid, high);  // merging both sorted subarrays arr[low, mid] and arr[mid + 1, high] to form sorted array[low, high]

}

void InPlaceMergeSort(int arr[], int n) {
    InPlaceMergeSort(arr, 0, n - 1);
}

int main() {

    int arr[] = {5, 4, 1, 6, 3, 2, 8, 7};

    int n = sizeof(arr) / sizeof(int);

    cout << "Array before sorting : \n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << endl;

    InPlaceMergeSort(arr, n);
   
    cout << "Array after sorting : \n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
