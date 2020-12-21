#include <iostream>
using namespace std;

int main() {
	int T, N;
    // Gets the number of test cases
	cin >> T;
    // Goes through each test case
	while (T--) {
        // Gets size of matrix
		cin >> N;
        // Creating Matrix
        int matrix[N][N];
        // Filling Matrix
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                cin >> matrix[i][j];
            }
        }
        // Accumulator holds the number of inversins in the matrix
        int acc = 0;
        //Goes through each element in the matrix
        for (int i=0;i<N;i++) {
            for (int j=0; j<N; j++) {
                // Compares each element to the rest of the elements and increments counter accordingly
                for (int x=i;x<N;x++) {
                    for (int y=j;y<N;y++){
                        if (matrix[i][j] > matrix[x][y]) acc++;
                    }
                }
            }
        }
        cout << acc << endl;
	}
    return 0;
}
