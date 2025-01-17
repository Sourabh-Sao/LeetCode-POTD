#include<bits/stdc++.h>
using namespace std;

bool doesValidArrayExist(vector<int>& derived) {
        int xr = 0;
        for (auto val : derived) {
            xr ^= val;
        }
        return xr == 0;
    }

int main(){
    vector<int>derived={1,1,0};
    cout<<doesValidArrayExist(derived);
}