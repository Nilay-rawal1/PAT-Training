#include<bits/stdc++.h>
using namespace std;

/*josephus problem*/

int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    else
    
        return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << josephus(n, k);

    return 0;
}

