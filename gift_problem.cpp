#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumGifts(vector<int>& ranks) {
    int n = ranks.size();
    vector<int> gifts(n, 1); // Step 1: Initialize gifts array with 1 gift for each employee

    // Step 2: Left to Right pass
    for (int i = 1; i < n; ++i) {
        if (ranks[i] > ranks[i - 1]) {
            gifts[i] = gifts[i - 1] + 1;
        }
    }

    // Step 3: Right to Left pass
    for (int i = n - 2; i >= 0; --i) {
        if (ranks[i] > ranks[i + 1]) {
            gifts[i] = max(gifts[i], gifts[i + 1] + 1);
        }
    }

    // Calculate the total number of gifts
    int totalGifts = 0;
    for (int gift : gifts) {
        totalGifts += gift;
    }

    return totalGifts;
}

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;

    vector<int> ranks(n);
    cout << "Enter the ranks of the employees: ";
    for (int i = 0; i < n; ++i) {
        cin >> ranks[i];
    }

    cout << "Minimum number of gifts required: " << minimumGifts(ranks) << endl;

    return 0;
}
