#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    set<string> words_in_s2;
    set<string> printed; 
    stringstream ss2(s2);
    string word;

  
    while (ss2 >> word) {
        words_in_s2.insert(word);
    }

    stringstream ss1(s1);
    while (ss1 >> word) {
        if (words_in_s2.count(word) && !printed.count(word)) {
            cout << word << " ";
            printed.insert(word);
        }
    }

    return 0;
}

