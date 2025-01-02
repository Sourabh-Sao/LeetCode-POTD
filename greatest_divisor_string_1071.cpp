// greatest common divisor of strings
#include<bits/stdc++.h>

using namespace std;

 string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
        return ""; // No common divisor if concatenations are different
    }


    int len1 = str1.length();
    int len2 = str2.length();
    // gcd is the greatest common divisor of len1 and len2 
    // what gcd does is it finds the greatest common divisor of two numbers
    int gcdLen = __gcd(len1, len2); 
    

    // int gcdLen = gcd(len1, len2); 

    return str1.substr(0, gcdLen);
    }

int main(){
    string str1="ABCABC",str2="ABC";
    cout<<gcdOfStrings(str1,str2);
    return 0;
}