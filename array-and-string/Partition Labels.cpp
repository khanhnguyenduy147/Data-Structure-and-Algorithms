/*
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.



Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]


Constraints:

1 <= s.length <= 500
s consists of lowercase English letters.
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOccurrence(26, -1); // Store the last occurrence index of each character
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            lastOccurrence[s[i] - 'a'] = i;
        }

        vector<int> partitions;
        int start = 0, end = 0;
        for (int i = 0; i < n; ++i) {
            end = max(end, lastOccurrence[s[i] - 'a']); // Update end index of current partition
            if (i == end) { // If we reach the end of current partition
                partitions.push_back(end - start + 1); // Push partition size into result
                start = i + 1; // Update start index for next partition
            }
        }

        return partitions;
    }
};

int main() {
    Solution solution;
    string s = "ababcbacadefegdehijhklij";
    vector<int> result = solution.partitionLabels(s);
    cout << "Partition sizes:";
    for (int size : result) {
        cout << " " << size;
    }
    cout << endl;
    return 0;
}

