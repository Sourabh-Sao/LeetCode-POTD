#include<bits/stdc++.h>
using namespace std;

using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) return false; // Trivial case: more palindromes than characters

        int oddCount = 0;
        int charCount[26] = {0}; // Use a simple array for character counts

        for (char c : s) charCount[c - 'a']++; 

        for (int i = 0; i < 26; i++) 
            if (charCount[i] % 2) oddCount++; 

        return oddCount <= k; 
    }
};

int main() {
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Enter the number of palindromes: ";
    cin >> k;

    Solution solution;
    bool result = solution.canConstruct(s, k);

    if (result) {
        cout << "It is possible to construct " << k << " palindromes from the string." << endl;
    } else {
        cout << "It is not possible to construct " << k << " palindromes from the string." << endl;
    }

    return 0;
}