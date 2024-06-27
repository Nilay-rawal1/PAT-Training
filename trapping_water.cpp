#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int trapWater(vector<int>& height) {
    int n = height.size();
    if (n <= 2) return 0;

    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int water_trapped = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= left_max) {
                left_max = height[left];
            } else {
                water_trapped += left_max - height[left];
            }
            ++left;
        } else {
            if (height[right] >= right_max) {
                right_max = height[right];
            } else {
                water_trapped += right_max - height[right];
            }
            --right;
        }
    }

    return water_trapped;
}

int main() {
    int N;
    cout << "Enter the total width of the map: ";
    cin >> N;

    vector<int> heights(N);
    cout << "Enter the heights of the bars: ";
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    int result = trapWater(heights);
    cout << "Total amount of water trapped: " << result << endl;

    return 0;
}
