#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long  tututu(long long q, long long k) {
    if (k > q) return 0;
    long long res = 1;
    for (int i = 0; i < k; i++) {
        res = res * (q - i) / (i + 1);
    }
    return res;
}

int main() {
    int n, p, t, n2;
    int j = 0;

    cin >> n >> p;
    vector<int> v1(p, 0);

    if (p == 1) {
        cout << n - 1;
        return 0;
    }
    if ( n == 1) {
        cout << "0";
        return 0;
    }

    /* for ( int i = 1; i <= p; ++i) {
        v1[i] = pow(2, i - 1);
        if (v1[i] * 2 >= n ) {
            t = v1[i - 1];
            j = i - 1;
            if ( t * 2  < n) {
                j++;
            }
            cout << j;
            return 0;
        }
        else {
             t = v1[i];
            j++; 
        } 
    } */
    // j--;

    while (true) {
        int z = 0;
        for (int i = 0; i <= p; i++) {
            z += tututu(j, i);
        }
        if (z >= n) {
            cout << j;
            return 0;
        }
        j++;
    }
}