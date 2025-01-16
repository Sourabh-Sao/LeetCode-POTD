#include<bits/stdc++.h>
using namespace std;

// one liner
// int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
//         return ((nums2.size()&1)?accumulate(nums1.begin(), nums1.end(), 0, bit_xor<>{}):0)^((nums1.size()&1)?accumulate(nums2.begin(), nums2.end(), 0, bit_xor<>{}):0);
//     }

int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int c1 = nums1.size();
        int c2 = nums2.size();
        int x1 = 0, x2 = 0;
        
        if (c1 % 2 != 0) {
            for (int num : nums2) {
                x2 ^= num;
            }
        }
        if (c2 % 2 != 0) {
            for (int num : nums1) {
                x1 ^= num;
            }
        }
        return x1 ^ x2;
    }

int main(){
    vector<int>A={2,1,3};
    vector<int>B={10,2,5,0};
    cout<<xorAllNums(A,B);
    return 0;
}
