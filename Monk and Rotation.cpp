#include <iostream>
using namespace std;

int main() {
	// Initialising Variables
	int T,N,K,_;
	// Getting the number of test case
	cin >> T;
	// For each test case
	for (_ = 0; _<T; _++) {
		// N - Number of elements in Array
		// K - Number of steps of rotations
		cin >> N >> K;
		// Initialising Array of size N
		int arr[N];
		// Filling Array
		for (_=0;_<N;_++) {
			cin >>arr[_];
		}
		// Simplifying K
	  while (K>=N) {
			K-=N;
		}
		// Print elements from N-K  to N indices
		for (_=N-K; _<N;_++) {
			cout << arr[_] << " ";
		}
		// Print elements from 0 to N-K indices
		for (_=0; _< N-K; _++) {
			cout << arr[_] << " ";
		}
		cout << endl;
	}
	return 0;
}
