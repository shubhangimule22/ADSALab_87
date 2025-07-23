//Title: Implement a problem of no. of zeros.
//statement : Given arrays of 1's and 0's ,which has all 1's followed by 0's . find no. of zeros and give the count of 0's in given array.
//Input: 1 1 1 1 0 0 0
//Output: 3

#include<iostream>
using namespace std;

int main() {
    int a[10], n, high = 0, low = 0, mid = 0;
    
    cout << "\nEnter size of array:\t";
    cin >> n;

    high = n - 1;

    cout << "\nEnter elements in 1's followed by 0's:\n";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    mid = (high + low) / 2;

    cout << "Count of 0's:\n";

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == 1) {
                      if (mid + 1 < n && a[mid + 1] == 0) {
                cout << n - (mid + 1) << endl;
                break;
            } else {
                low = mid + 1;
            }
        } else if (a[mid] == 0) {
            if (mid == 0 || a[mid - 1] == 1) {
                cout << n - mid << endl;
                break;
            } else {
                high = mid - 1;
            }
        }
    }

    return 0;
}
