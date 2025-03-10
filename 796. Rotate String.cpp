Approach 1
The approach involves checking all possible rotations of one string and comparing it with the other string. The rotation is performed using the modulo operator to handle circular rotation. If at any point, the rotated string matches the other string, then we return true. If none of the rotations match, we return false.

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false; 
        }

        for (int i = 0; i < goal.length(); i++) {
            bool rotationPossible = true;

            for (int j = 0; j < s.length(); j++) {
                // Use modulo operator to handle rotation
                if (goal[(i + j) % goal.length()] != s[j]) {
                    rotationPossible = false;
                    break;
                }
            }

            if (rotationPossible) {
                return true;
            }
        }

        return false;
    }
};


Approach
Length Check:

If the lengths of the two strings s and goal are different, return false since rotation is not possible.
Concatenate the String:

Create a new string concatenated by appending the goal string to itself.
Two Pointers Initialization:

Initialize two pointers, i and j, to 0.
i will be used to iterate through the concatenated string.
j will be used to iterate through the original string s.
Iteration through Concatenated String:

Use a while loop to iterate through the characters of the concatenated string.
Character Matching:

Check if the character at the current position in the concatenated string (concatenated[i]) matches the character in the original string (s[j]).
If there's a match:
Increment both pointers i and j.
If j reaches the length of the original string, return true as rotation is possible.
Mismatch Handling:

If a mismatch is found:
If j is not at the beginning, reset j to 0 (start over for matching).
If j is already at the beginning, increment i (move forward in the concatenated string).
Return Result:

If the loop completes without finding a rotation, return false.


class Solution {
public:
    bool rotateString(string s, string goal) {
        // If the lengths are different, return false
        if (s.size() != goal.size()) {
            return false;
        }

        string concatenated = goal + goal;
        int i = 0;
        int j = 0;
        int n = s.size();
        int m = concatenated.size();

        while (i < m) {
            if (concatenated[i] == s[j]) {
                j++;
                i++;
                if (j == n) {
                    return true;
                }
            } else {
                if (j != 0) {
                    i=i-j+1;
                    j = 0;
                } else {
                    i++;
                }
            }
        }

        return false;
    }
};

  3rd Approch 

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }

        string concatenated = goal + goal;

        return concatenated.find(s) != string::npos;
    }
};
