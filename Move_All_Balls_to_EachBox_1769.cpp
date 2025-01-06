#include<bits/stdc++.h>
using namespace std;

 
 
 vector<int> minOperations(string boxes) {
      int n = boxes.length();
    vector<int> answer(n, 0);
    vector<int> left(n, 0);
    vector<int> right(n, 0);

    int count = 0;
    for (int i = 1; i < n; ++i) {
        if (boxes[i - 1] == '1') {
            count++;
        }
        left[i] = left[i - 1] + count;
    }

    count = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (boxes[i + 1] == '1') {
            count++;
        }
        right[i] = right[i + 1] + count;
    }

    for (int i = 0; i < n; ++i) {
        answer[i] = left[i] + right[i];
    }

    return answer;
    }
int main(){
    string boxes = "110";
    vector<int>ans=minOperations(boxes);
    for(auto val:ans){
        cout<<val<<" ";
    }
    return 0;
}