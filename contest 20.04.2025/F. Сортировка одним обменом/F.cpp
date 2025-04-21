#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    int q = 0;
    int a, b, c, d;
    c = 0;
    bool a1, b1 = true;
    cin >> n;
    vector<int> v1(n), v2(n);

    for (int i = 1; i <= n; ++i) {
        v1[i-1] = i;
    }

    for (int i = 0; i < n; ++i) {
        cin >> v2[i];
    }

    for (int i = 1; i < n; ++i) {
        if (v2[i] - v2[i - 1] != 1) {
            if (q == 0) {
                a = i;
            }
            if (q == 1) {
                b = i;
            }
            if (q == 2) {
                c = i;
            }
            if (q == 3) {
                d = i;
            }
            q++;
        }
    }
    // || q == 3 && c != 0
    if (q == 2 || q == 3 ) {
        if (v2[0] != 1) q++;
    }

    // cout << q << "\n";

    if ( q !=1 && q !=2 && q !=3 && q !=4) {
        cout << "-1";
        return 0;
    }

    if (q == 1) {
        cout << "1 " << a << "\n";
        cout << a + 1 << " " << n - a; 
    }

    if (q == 2) {
        cout << a + 1 << " " << b - a << "\n";
        cout << b + 1 << " " << n - b;
    }

    if (v1[0] != 1 && q == 3) {
        if (v2[c] > v2[b] && v2[b] > v2[a]) {
            cout << "-1";
            return 0;
        }
    }

    if (q == 3) {
        if (v2[0] == 1) {
            if (v2[n-1] == n) {
                cout << a + 1 << " " << b - a << "\n";
                cout << b + 1 << " " << c - b; 
            }
            else {
                cout << a + 1 << " " << b - a << "\n";
                cout << c + 1 << " " << n - c;  
            }
        }
        else {
            if (v2[n-1] == n) {
                cout << "1 " << a << "\n";
                cout << a + 1 << " " << b - a; 
            }
            else {
                cout << "1 " << a << "\n";
                cout << b + 1 << " " << n - b; 
            }
        }
    }

    if (q == 4) {
        if (v2[0] == 1) {
            if (v2[a] > v2[b] && v2[b] > v2[c] && v2[d] > v2[a]) {
                cout << a + 1 << " " << b - a << "\n";
                cout << c + 1 << " " << d - c;  
            }
            else {
                cout << "-1";
                return 0; 
            }
        }
        else if (v2[0] > v2[a] && v2[a] > v2[b] && v2[c] > v2[0]) {
            cout << "1" << " " << a << "\n";
            cout << b + 1 << " " << c - b;
        }
        else {
            // cout << v2[0] << " " << v2[a] << " " <<  v2[b] << " " << v2[c];
            cout << "-1";
            return 0; 
        }
    }

    return 0;
}