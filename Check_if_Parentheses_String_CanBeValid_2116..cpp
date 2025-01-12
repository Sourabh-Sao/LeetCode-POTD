#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool canBeValid(string s, string locked) {
    int n = s.length();
    if (n % 2 != 0) {
        return false;
    }

    int balance = 0;
    int changeable = 0;

    for (int i = 0; i < n; ++i) {
        if (locked[i] == '1') {
            if (s[i] == '(') {
                balance++;
            } else {
                balance--;
            }
        } else {
            changeable++;
        }

        if (balance + changeable < 0) {
            return false;
        }
    }

    balance = 0;
    changeable = 0;

    for (int i = n - 1; i >= 0; --i) {
        if (locked[i] == '1') {
            if (s[i] == ')') {
                balance++;
            } else {
                balance--;
            }
        } else {
            changeable++;
        }

        if (balance + changeable < 0) {
            return false;
        }
    }

    return true;
}

int main() {
    // Test cases
    string s1 = "))()))";
    string locked1 = "010100";
    cout << "Test Case 1: " << canBeValid(s1, locked1) << endl; // Output: true

    string s2 = "()()";
    string locked2 = "0000";
    cout << "Test Case 2: " << canBeValid(s2, locked2) << endl; // Output: true

    string s3 = ")";
    string locked3 = "0";
    cout << "Test Case 3: " << canBeValid(s3, locked3) << endl; // Output: false

    string s4 = "((()))";
    string locked4 = "111111";
    cout << "Test Case 4: " << canBeValid(s4, locked4) << endl; // Output: true
    
    string s5 = "()";
    string locked5 = "10";
    cout << "Test Case 5: " << canBeValid(s5, locked5) << endl; // Output: true

     string s6 = ")(()))";
    string locked6 = "011110";
    cout << "Test Case 6: " << canBeValid(s6, locked6) << endl; // Output: true

    return 0;
}