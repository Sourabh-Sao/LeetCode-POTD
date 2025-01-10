#include <bits/stdc++.h>
using namespace std;

vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{
    array<int, 26> max_freq = {0};

    // Calculate max frequencies for words2
    for (const string &b : words2)
    {
        array<int, 26> freq = {0};
        for (char c : b)
        {
            freq[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i)
        {
            max_freq[i] = max(max_freq[i], freq[i]);
        }
    }

    vector<string> result;
    result.reserve(words1.size()); // Reserve space to avoid reallocations

    for (const string &a : words1)
    {
        array<int, 26> freq_a = {0};
        for (char c : a)
        {
            freq_a[c - 'a']++;
        }

        bool universal = true;
        for (int i = 0; i < 26; ++i)
        {
            if (freq_a[i] < max_freq[i])
            {
                universal = false;
                break;
            }
        }
        if (universal)
        {
            result.push_back(a);
        }
    }

    return result;
}

int main()
{
    vector<string> words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    vector<string> words2 = {"e", "o"};
    vector<string> result = wordSubsets(words1, words2);
    for (const string &s : result)
    {
        cout << s << " ";
    }
    cout << endl;

    words1 = {"amazon", "apple", "facebook", "google", "leetcode"};
    words2 = {"l", "e"};
    result = wordSubsets(words1, words2);
    for (const string &s : result)
    {
        cout << s << " ";
    }
    cout << endl;

    words1 = {"bella", "label", "roller"};
    words2 = {"la", "label"};
    result = wordSubsets(words1, words2);
    for (const string &s : result)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}