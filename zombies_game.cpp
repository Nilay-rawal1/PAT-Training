#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int B, N;
    cout << "Enter Bob's energy and number of zombies: ";
    cin >> B >> N;
    
    vector<int> zombies(N);
    cout << "Enter the energies of the zombies: ";
    for (int i = 0; i < N; ++i) {
        cin >> zombies[i];
    }

    // Sort the zombies by their energy in ascending order
    sort(zombies.begin(), zombies.end());

    // Simulate the fights
    for (int i = 0; i < N; ++i) {
        int Zi = zombies[i];
        if (B >= Zi) {
            B -= (Zi % 2) + (Zi / 2);
        } else {
            cout << "Bob dies" << endl;
            return 0;
        }
    }

    cout << "Bob wins" << endl;
    return 0;
}
