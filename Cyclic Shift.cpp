#include <iostream>
#include <cmath>

using namespace std;


bool isLarger(char arr[], char max[], int n) {
    bool larger = false;
    for (int _=0;_<n;_++) {
        if (arr[_]!=max[_]){
            if (arr[_] == '1') larger = true;
            break;
        }
    }
    return larger;
}

// Check if two arrays are the same
bool compare(char arr[], char max[], int n) {
    bool matches = true;
    for (int _=0;_<n;_++) {
        if (arr[_]!=max[_]) {
            matches = false;
            break;
        }
    }
    return matches;
}


int main() {
    // Initialising the number of test cases
    int t;
    cin >> t;
    // For each test case
    while (t--) {
        // Initialising N, the size of the string, and K
        long long int n, k;
        cin >> n;
        // Initialising Array of chars of size N.
        char arr[n], max[n];

        cin >> k;


        // Filling Char Array
        for (int _=0;_<n;_++) {
    			cin >> arr[_];
    		}

        //long long int current_max = getValue(arr,n);
        copy(arr, arr + n, max);

        double repeats = 0;
        int counter = 0;
        char e;


        for (int i = n/2; i>=1; i--) {
            if (n%2 == 0) {
                int repeat = n/i;

            }
        }


        //n is also the number of possible shifts
        for (int i=0;i<n;i++) {
            // copy the first element
            e = arr[0];
            // Shift all elements to the left
            for (int j=0;j<n-1;j++) {
                arr[j] = arr[j+1];
            }
            // Replace the last element with the first element
            arr[n-1] = e;

            if (compare(arr,max, n)) {
                repeats++;
                continue;
            }

            // Check if the shifted sequence has a larger value
            if (isLarger(arr, max, n)) {
                // update max sequence
                copy(arr, arr + n, max);
                counter = i+1;
            }

        }

        long long int cycles = (k-1)*n;
        if (repeats > 0.0) {
            cycles =  ((k-1)/((repeats + 1)/n));
        }
        if (counter == 0) {
            cycles =  ((k-1)/((repeats)/n));
        }

        cout << counter + cycles << endl;

    }
}
