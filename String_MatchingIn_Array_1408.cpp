#include <bits/stdc++.h>
using namespace std;

bool isSubstring(const string &s1, const string &s2)
{
    return s2.find(s1) != string::npos;
}
vector<string> stringMatching(vector<string> &words)
{
    int n = words.size();
    vector<string> result;
    unordered_set<string> seen;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i != j && !seen.count(words[j]) && isSubstring(words[j], words[i]))
            {
                result.push_back(words[j]);
                seen.insert(words[j]);
            }
        }
    }

    return result;
}

int main()
{
    vector<string> words = {"mass", "as", "hero", "superhero"};
    vector<string>ans=stringMatching(words);

     for (auto val:ans) {
        cout << val << " ";
    }

    return 0;
}