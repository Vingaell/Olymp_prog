#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int A, B, C, D, P, Q;
    cin >> A >> B >> P;
    cin >> C >> D >> Q;

    if (A * D == B * C) {
        if (A * Q == P * C && B * Q == P * D) {
            cout << "Ambiguity";
            return 0;
        }
        else {
            cout << "Contradiction";
            return 0;
        }
    }

    double det = A * D - B * C;
    double x = 100.0 * (P * D - B * Q) / det;
    double y = 100.0 * (A * Q - P * C) / det;

    if (x < 0 || y < 0) {
        cout << "Not positive";
        return 0;
    }

    cout << "Success\n";
    cout << x << " " << y;

    return 0;
}