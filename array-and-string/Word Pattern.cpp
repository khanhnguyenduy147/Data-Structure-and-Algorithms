/*
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.



Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false


Constraints:

1 <= pattern.length <= 300
pattern contains only lower-case English letters.
1 <= s.length <= 3000
s contains only lowercase English letters and spaces ' '.
s does not contain any leading or trailing spaces.
All the words in s are separated by a single space.
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        istringstream ss(s);
        string word;
        int i = 0;

        while (getline(ss, word, ' ')) {
            if(i >= pattern.length()){
                return false;
            }
            char c = pattern[i];
            if(charToWord.find(c) == charToWord.end() && wordToChar.find(word) == wordToChar.end()) {
                charToWord[c] = word;
                wordToChar[word] = c;
            } else {
                if(charToWord[c] != word || wordToChar[word] != c){
                    return false;
                }
            }
            i++;
        }
        return i == pattern.length();
    }
};

int main(){
    Solution solution;

    //Test case
    string pattern1 = "abba";
    string s1 = "dog cat cat dog";
    cout << "Example 1: " << solution.wordPattern(pattern1, s1) << endl;

    string pattern2 = "abba";
    string s2 = "dog cat cat fish";
    cout << "Example 2: " << solution.wordPattern(pattern2, s2) << endl;

    string pattern3 = "aaaa";
    string s3 = "dog cat cat dog";
    cout << "Example 3: " << solution.wordPattern(pattern3, s3) << endl;

    return 0;
}
