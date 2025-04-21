#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int a = 1; a <= 1000; ++a) {
        long long popa = (long long)(n - 1) * a * a;
        for (int c = 1; c <= 1000; ++c) {
            long long total = popa + (long long)c * c;
            long long b = sqrt((double)total);
            if (b * b == total) {
                for (int i = 0; i < n - 1; ++i) {
                    cout << a << " ";
                }
                cout << c << " " << b;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}