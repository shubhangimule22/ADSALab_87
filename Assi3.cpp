//Title : Implement a problem of smallest number with at least no trailing zeros in factorial .
//Statement : Given a number n , the task is to find smallest number whose factorial contains at least n trailing zeros.
//Input : 2
//Output : 10 .

#include <iostream>
using namespace std;

// Function to count trailing zeros in x!
int countTrailingZeros(int x) {
    int count = 0;
    while (x >= 5) {
        count += x / 5;
        x /= 5;
    }
    return count;
}

// Function to find the smallest number with at least n trailing zeros in its factorial
int smallestNumberWithTrailingZeros(int n) {
    int low = 0, high = 5 * n, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int zeros = countTrailingZeros(mid);

        if (zeros >= n) {
            result = mid;     // potential answer
            high = mid - 1;   // look for a smaller one
        } else {
            low = mid + 1;    // need more zeros
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the number of trailing zeros required: ";
    cin >> n;

    int result = smallestNumberWithTrailingZeros(n);
    cout << "Smallest number whose factorial has at least " << n << " trailing zeros is: " << result << endl;

    return 0;
}
