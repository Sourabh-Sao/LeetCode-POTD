// string 

#include<bits./stdc++.h>
using namespace std;

int maxScore(string s) {
        int n = s.size();
    int left_zeros = 0, right_ones = 0;

    for (char c : s) {
        if (c == '1') {
            right_ones++;
        }
    }

    int max_score = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '0') {
            left_zeros++;
        } else {
            right_ones--;
        }
        max_score = max(max_score, left_zeros + right_ones);
    }

    return max_score;
}

int main(){
    string s="011101";
    cout<<maxScore(s);

    return 0;
}