/*
Most Common Word
Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.

The words in paragraph are case-insensitive and the answer should be returned in lowercase.



Example 1:

Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
Output: "ball"
Explanation:
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph.
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"),
and that "hit" isn't the answer even though it occurs more because it is banned.
Example 2:

Input: paragraph = "a.", banned = []
Output: "a"
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        //convert paragraph to lowercase
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);
        //replace punctuation with space
        for(char& c : paragraph) {
            if(!isalpha(c)) {
                c = ' ';
            }
        }
        //parse words from the paragraph
        stringstream ss(paragraph);
        string word;
        unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> frequency;
        string mostCommon;
        int maxFreq = 0;

        while(ss >> word) {
            if(!bannedSet.count(word)) {
                frequency[word]++;
                if(frequency[word] > maxFreq) {
                    mostCommon = word;
                    maxFreq = frequency[word];
                }
            }
        }
        return mostCommon;
    }
};

int main() {
    Solution solution;

    // Example 1
    string paragraph1 = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> banned1 = {"hit"};
    cout << "Example 1 Output: " << solution.mostCommonWord(paragraph1, banned1) << endl;

    // Example 2
    string paragraph2 = "a.";
    vector<string> banned2 = {};
    cout << "Example 2 Output: " << solution.mostCommonWord(paragraph2, banned2) << endl;

    // Example 3
    string paragraph3 = "a, a, a, a, b,b,b,c, c";
    vector<string> banned3 = {"a"};
    cout << "Example 3 Output: " << solution.mostCommonWord(paragraph3, banned3) << endl;

    return 0;
}
