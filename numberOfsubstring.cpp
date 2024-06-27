#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int countSubstringsWithAllABC(const string& s) {
    int n = s.length();
    int count = 0;
    unordered_map<char, int> charCount;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        charCount[s[right]]++;

        while (charCount['a'] > 0 && charCount['b'] > 0 && charCount['c'] > 0) {
            count += (n - right);
            charCount[s[left]]--;
            left++;
        }
    }

    return count;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int result = countSubstringsWithAllABC(s);
    cout << "The number of substrings containing at least one occurrence of a, b, and c is: " << result << endl;

    return 0;
}
