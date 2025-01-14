#include<bits/stdc++.h>
using namespace std;

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> C(n);
    unordered_set<int> seen;
    int commonCount = 0;

    for (int i = 0; i < n; ++i) {
        if (seen.count(A[i])) {
            commonCount++;
        } else {
            seen.insert(A[i]);
        }

        if (seen.count(B[i])) {
            commonCount++;
        } else {
            seen.insert(B[i]);
        }
        C[i] = commonCount;
    }

    return C;
}

int main() {
    // Example usage (you can test with different inputs)
    vector<int> A1 = {1, 3, 2, 4};
    vector<int> B1 = {3, 1, 2, 4};
    vector<int> C1 = findThePrefixCommonArray(A1, B1);
    for (int x : C1) cout << x << " ";
    cout << endl; // Output: 0 2 3 4

    vector<int> A2 = {2, 3, 1};
    vector<int> B2 = {3, 1, 2};
    vector<int> C2 = findThePrefixCommonArray(A2, B2);
    for (int x : C2) cout << x << " ";
    cout << endl; // Output: 0 1 3

        vector<int> A3 = {1,2};
    vector<int> B3 = {2,1};
    vector<int> C3 = findThePrefixCommonArray(A3, B3);
    for (int x : C3) cout << x << " ";
    cout << endl; // Output: 0 2

    return 0;
}