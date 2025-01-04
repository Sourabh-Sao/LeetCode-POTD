#include<bits/stdc++.h>
using namespace std;

int countPalindromicSubsequence(string s) {
        int n = s.length();
    if (n < 3) {
        return 0;
    }

    unordered_set<string> uniquePalindromes;

    for (char outerChar = 'a'; outerChar <= 'z'; ++outerChar) {
        // Find first and last occurrences of the outer character
        int firstOccurrence = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == outerChar) {
                firstOccurrence = i;
                break;
            }
        }
        if (firstOccurrence == -1) continue; // Outer char not found

        int lastOccurrence = -1;
        for (int i = n - 1; i > firstOccurrence; --i) {
            if (s[i] == outerChar) {
                lastOccurrence = i;
                break;
            }
        }
        if (lastOccurrence == -1) continue; // Only one occurrence of the outer char

        // Optimization: Precompute middle character occurrences between outer chars
        vector<bool> middleCharExists(26, false);
        for (int i = firstOccurrence + 1; i < lastOccurrence; ++i) {
            middleCharExists[s[i] - 'a'] = true;
        }

        for (int middleCharIndex = 0; middleCharIndex < 26; ++middleCharIndex) {
            if (middleCharExists[middleCharIndex]) {
                string target = "";
                target += outerChar;
                target += (char)('a' + middleCharIndex);
                target += outerChar;
                uniquePalindromes.insert(target);
            }
        }
    }

    return uniquePalindromes.size();
    }

int main(){
    string s="aabca";
    cout<<countPalindromicSubsequence(s);


    return 0;
}