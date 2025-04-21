#include <iostream>

using namespace std;

const long long LIMIT = 1000000000000000LL;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (n < LIMIT) {
            cout << 0 << "\n";
            continue;
        }
        long long m = n / LIMIT;
        int count = 0;
        for (long long d = 1; d <= m; ++d) {
            if (n % d == 0) {
                ++count;
            }
        }
        cout << count << "\n";
    }
    return 0;
}


