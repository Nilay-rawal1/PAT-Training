#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, L;
    cout<<"Enter the number of patients: ";
    cin >> N;
    cout<<"Enter the ages of the patients: ";
    vector<int> ages(N);
    for (int i = 0; i < N; ++i) {
        cin >> ages[i];
    }
    cout<<"Enter the number of nano-capsule: ";
    cin >> L;

    int highRisk = 0, nonHighRisk = 0;
    for (int age : ages) {
        if ((age >= 0 && age <= 10) || age >= 81) {
            highRisk++;
        } else {
            nonHighRisk++;
        }
    }

    // Calculate the days needed for high risk and non-high risk groups
    int daysForHighRisk = (highRisk + L - 1) / L;  // Equivalent to ceil(highRisk / L)
    int daysForNonHighRisk = (nonHighRisk + L - 1) / L;  // Equivalent to ceil(nonHighRisk / L)

    int totalDays = daysForHighRisk + daysForNonHighRisk;

    cout << totalDays << " Days" << endl;

    return 0;
}
