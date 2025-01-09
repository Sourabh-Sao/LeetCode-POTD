#include<bits/stdc++.h>
using namespace std;


int prefixCount(vector<string>& words, string pref) {
    int count = 0;
    int prefLen = pref.length();

    if (prefLen == 0) {
        return words.size();
    }

    for (const string& word : words) {
        if (word.length() >= prefLen) {
            bool isPrefix = true;
            for (int i = 0; i < prefLen; ++i) {
                if (word[i] != pref[i]) {
                    isPrefix = false;
                    break;
                }
            }
            if (isPrefix) {
                count++;
            }
        }
    }

    return count;
}

int main() {

    vector<string> words = {"lcc","psl","bqybsg","rfzpp","bqynodm","bqyjn","ich","bqycn","ylkvdrh","irjg","bqyqwaxg","bqyuyw","bqyywgy","bqyqx","fshrgwj","bqyptjif","bqypg","bqyyfdm","bqyslg","mz"};
    string pref = "bqy";
    cout << prefixCount(words, pref) << endl; // Should output 12

    vector<string> words2 = {"leetcode","leet","lee","le"};
    string pref2 = "leet";
    cout << prefixCount(words2, pref2) << endl; // Should output 2

    return 0;
}