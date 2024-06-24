#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int H, M;
    cout << "Enter current hour: ";
    cin >> H;
    cout << "Enter current minutes: ";
    cin >> M;
    
    // Constants for a 24-hour journey
    const int journeyHours = 24;
    const int journeyMinutes = 0;

    if (H < 24 || (H == 24 && M == 0)) {
        // Calculate remaining time
        int remainingHours = journeyHours - H;
        int remainingMinutes = journeyMinutes - M;
        
        // Adjust minutes and hours if needed
        if (remainingMinutes < 0) {
            remainingMinutes += 60;
            remainingHours -= 1;
        }

        // Format the output with leading zeros
        cout << setfill('0') << setw(2) << remainingHours << "::"
             << setfill('0') << setw(2) << remainingMinutes << endl;
    } else {
        // Calculate exceeded time
        int exceededHours = H - journeyHours;
        int exceededMinutes = M - journeyMinutes;

        // Adjust minutes and hours if needed
        if (exceededMinutes >= 60) {
            exceededMinutes -= 60;
            exceededHours += 1;
        } else if (exceededMinutes < 0) {
            exceededMinutes += 60;
            exceededHours -= 1;
        }

        // Format the output with leading zeros
        cout << "-" << setfill('0') << setw(2) << exceededHours << "::"
             << setfill('0') << setw(2) << exceededMinutes << endl;
    }

    return 0;
}
