#include<bits/stdc++.h>
using namespace std;

bool canReturnExactChange(int change, unordered_map<int, int>& denominations) {
    // Try to return the exact change using available denominations
    unordered_map<int, int> usedDenominations;
    for (auto it = denominations.rbegin(); it != denominations.rend(); ++it) {
        int denom = it->first;
        while (change >= denom && it->second > 0) {
            change -= denom;
            it->second--;
            usedDenominations[denom]++;
        }
    }

    if (change != 0) {
        // If exact change can't be given, revert the changes in denominations map
        for (auto it = usedDenominations.begin(); it != usedDenominations.end(); ++it) {
            denominations[it->first] += it->second;
        }
        return false;
    }

    return true;
}

int main() {
    int N;
    cin >> N;

    vector<int> transactions(N);
    for (int i = 0; i < N; ++i) {
        cin >> transactions[i];
    }

    unordered_map<int, int> denominations = {{30, 0}, {60, 0}, {120, 0}};

    bool possible = true;
    for (int i = 0; i < N; ++i) {
        int amount = transactions[i];
        int cost = 130;
        int change = amount - cost;

        if (change == 0) {
            denominations[130]++;
        } else if (change > 0) {
            if (canReturnExactChange(change, denominations)) {
                denominations[amount]++;
            } else {
                possible = false;
                break;
            }
        } else {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
