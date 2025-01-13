#include<bits/stdc++.h>
using namespace std;

int minimumLength(string s) {
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        int minus = 0;
        for (auto& entry : count) {
            while (entry.second >= 3) {
                minus += 2;
                entry.second -= 2;
            }
        }
        return s.length() - minus;
    }

int main(){
    cout << minimumLength("abcabc") << endl; 

    return 0;
}