#include <iostream>
#include <algorithm>

using namespace std;

class Solution {

    /*
        Case Analysis:

        [1, 2, 3] -> [1, 3, 2]

        1. Place the first item
        [1,_, _]

        2. Can put either 2 or 3
        [1, 2, _]

        3. Can only place 3
        [1, 2, 3]

        4. What is the next permutation?
            - exploring 1, 2....
            - put 3 back into the decision space
            - all possibilities of 1, 2 explored
            - put 2 back into the decision space
            - [1,_,_] <-- explore possibilities
            - [1,3,_] <-- 2 was already picked so pick 3
            - [1,3,2] is the next permutation

        5. And the next permutation?
            - [2, _, _]
            - [2, 1, 3] is the next permutation following the above steps

        6. Strictly Decreasing Permutation
            -is on its last permuation.
            -Example: [6, 2, 1, 5, 4, 3, 0]
            - [5, 4, 3, 0] <- scrictly decreasing permuation

            - [6, 2, 3, 5, 4, 1, 0] - swap 1 with 3
            - [6, 2, 3, 0, 1, 4, 5] - Suffix is minimised


        n is the length of start string
        Time: o(n) - using local variables
        Space: o(1) - swapping is linear

    */
public:


    void nextPermutation(vector<int>& nums) {
        int i, j, n = nums.size();
        // Starting from the right, check if the num to the left is smaller
        for (i = n-1; i>0; i--) {
            if (nums[i] > nums[i-1]) break;
        }
        // Reverse the array since its already sorted in Decreasing Order.
        if (i==0) {
            sort(nums.begin(), nums.end());
            return; // stop execution
        }
        // Get value to be swapped
        int num = nums[i-1], min = i;

        // Find the next smallest number in the sublist to swap
        for (j=i; j<n; j++) {
            if (nums[j] > num && nums[j] < nums[min]) {
                min = j;
            }
        }
        // Swap positions
        iter_swap(nums.begin()+(i-1), nums.begin() + min);
        // Sort sublist
        sort(nums.begin()+i,nums.end());
        return;
    }

};
