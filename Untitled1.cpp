#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    unordered_set<string> seen;
    vector<string> result;
    string word;

    stringstream ss1(s1);
    while (ss1 >> word) {
        if (!seen.count(word)) {
            seen.insert(word);
            result.push_back(word);
        }
    }

    stringstream ss2(s2);
    while (ss2 >> word) {
        if (!seen.count(word)) {
            seen.insert(word);
            result.push_back(word);
        }
    }

    for (const string& w : result) {
        cout << w << " ";
    }

    return 0;
}

