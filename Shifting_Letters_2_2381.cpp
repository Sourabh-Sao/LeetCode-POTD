#include <bits/stdc++.h>
using namespace std;

string shiftingLetters(string s, vector<vector<int>> &shifts)
{
    int n = s.length();
    vector<int> prefix_shifts(n + 1, 0); // Use prefix sums for efficiency

    // Calculate net shifts for each position
    for (const auto &shift : shifts)
    {
        int start = shift[0];
        int end = shift[1];
        int dir = shift[2];
        int val = (dir == 1) ? 1 : -1;

        prefix_shifts[start] += val;
        prefix_shifts[end + 1] -= val; // Important for prefix sum calculation
    }

    // Apply prefix sums to get actual shifts at each index
    for (int i = 1; i <= n; ++i)
    {
        prefix_shifts[i] += prefix_shifts[i - 1];
    }

    // Apply the shifts to the string
    for (int i = 0; i < n; ++i)
    {
        int shift_val = prefix_shifts[i];
        int shifted_char = (s[i] - 'a' + shift_val) % 26;
        if (shifted_char < 0)
        {
            shifted_char += 26; // Handle negative modulo
        }
        s[i] = 'a' + shifted_char;
    }

    return s;
}

int main(){
    string s = "abc";
    vector<vector<int>>shift =  {{0, 1, 0}, {1, 2, 1}};
    string shifted_string = shiftingLetters(s, shift);
    cout << shifted_string << endl;
    return 0;
}