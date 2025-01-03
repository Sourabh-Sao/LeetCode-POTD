#include<bits/stdc++.h>
using namespace std;

int waysToSplitArray(vector<int>& nums) {
     int n = nums.size();
    if (n <= 1) return 0;

    long long left_sum = 0;
    long long right_sum = std::accumulate(nums.begin(), nums.end(), 0LL); 

    int valid_splits = 0;
    for (int i = 0; i < n - 1; ++i) {
        left_sum += nums[i];
        right_sum -= nums[i];
        if (left_sum >= right_sum) {
            ++valid_splits;
        }
    }

    return valid_splits;
    }

int main(){
    vector<int>arr={10,4,-8,7};
    cout<<waysToSplitArray(arr);

    return 0;
}