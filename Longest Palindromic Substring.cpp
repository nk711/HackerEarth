#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // error handling
        if (s.empty() || s.size() < 1) return "";
        int L = s.size();
        // Start and end position of the longest palindrome
        int start = 0;
        int end = 0;
        // Go through each index
        for (int i=0; i<L); i++) {
            // Find the longest palindrome as position i as center
            // Find the longest palindrome as position i and i + 1 as center
            // Find the max length
            // set the start and end position of the max palindrome found.
            }
            int max_length = max(bubble(s, i,i),bubble(s, i,i+1));
            if (max_length > end - start) {
                start = i-((max_length-1)/2);
                end = i+(max_length/2);
            }
        }
        return s.substr(start, end-start+1);
    }

    int bubble(string s, int l, int r) {
        // Error handling
        if (s.empty() || l > r) return 0;
        // Check if palindrome, expand bubble and check
        while (l>=0 && r< s.size() && s[l]==s[r]) {
            l--;
            r++;
        }
        // Return the legnth fo the found palindrome
        return r-l-1;
    }
};
