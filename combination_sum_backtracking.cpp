#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findCombinations(vector<int>& candidates, int target, vector<int>& combination, vector<vector<int>>& result, int start) {
    if (target == 0) {
        result.push_back(combination);
        return;
    }
    
    for (int i = start; i < candidates.size(); i++) {
        if (candidates[i] > target) continue; // No need to proceed if the candidate is greater than the remaining target
        combination.push_back(candidates[i]);
        findCombinations(candidates, target - candidates[i], combination, result, i); // Not i + 1 because we can reuse the same element
        combination.pop_back(); // backtrack
    }
}

int main() {
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> candidates(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<vector<int>> result;
    vector<int> combination;

    findCombinations(candidates, target, combination, result, 0);

    // Sort the combinations to ensure the output order is lexicographically sorted
    sort(result.begin(), result.end());

    cout << "Unique combinations that sum to " << target << " are: " << endl;
    for (auto& comb : result) {
        for (auto& num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}