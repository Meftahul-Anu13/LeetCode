#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int mirrorScore(const string& s) {
    unordered_map<char, char> mirror;
    for (char c = 'a'; c <= 'z'; ++c) {
        mirror[c] = 'z' - (c - 'a');
    }

    int score = 0;
    vector<bool> marked(s.length(), false);

    for (int i = 0; i < s.length(); ++i) {
        if (marked[i]) continue;
        for (int j = i - 1; j >= 0; --j) {
            if (!marked[j] && s[j] == mirror[s[i]]) {
                marked[i] = marked[j] = true;
                score += i - j;
                break;
            }
        }
    }

    return score;
}

int main() {
    string s1 = "aczzx";
    string s2 = "abcdef";

    cout << "Score for s1: " << mirrorScore(s1) << endl; // Output: 5
    cout << "Score for s2: " << mirrorScore(s2) << endl; // Output: 0

    return 0;
}