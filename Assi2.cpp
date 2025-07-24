//Title : Implement a program of moving all 0's at end of array.
//statement : Given an array of numbers push all the 0's at the end of given array.
//Input : 2 4 0 0 9 0
//Output : 2 4 9 0 0 0
#include <iostream>
using namespace std;

// Merge 
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // size of left 
    int n2 = right - mid;    // size of right 

    // temporary arrays
    int L[10], R[10]; 

    //  data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge temp arrays
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    // Copy elements
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

// Merge sort 
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Push 0s 
void pushZerosToEnd(int arr[], int size) {
    int index = 0;

    // non-zero elements forward
    for (int i = 0; i < size; i++) {
        if (arr[i] != 0)
            arr[index++] = arr[i];
    }

    // Fill remaining with 0
    while (index < size) {
        arr[index++] = 0;
    }
}

// Print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main function
int main() {
    int arr[10]; // max size
    int size;

    cout << "Enter the number of elements (max 10): ";
    cin >> size;

    if (size < 1 || size > 10) {
        cout << "Invalid size. Please enter a value between 1 and 10." << endl;
        return 1;
    }

    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr, size);

    // Sort array using merge sort
    mergeSort(arr, 0, size - 1);

    // Move 0s to end
    pushZerosToEnd(arr, size);

    cout << "Sorted array with 0's at the end: ";
    printArray(arr, size);

    return 0;
}
