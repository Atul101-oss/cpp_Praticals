// Write a program to search a pattern in a given text using the KMP algorithm.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void computeLPSArray(const string &pattern, vector<int> &lps) {
    int length = 0;
    lps[0] = 0;  // lps[0] is always 0

    int i = 1;
    while (i < pattern.length()) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPsearch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps(m);
    computeLPSArray(pattern, lps);

    int i = 0;  // index for text
    int j = 0;  // index for pattern
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text;
    string pattern;
    cout << "Enter a text or doc: "; getline(cin,text);
    cout << "Enter a pattern to find in text: "; cin>>pattern;

    KMPsearch(text, pattern);

    return 0;
}
