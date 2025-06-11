#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <algorithm>
 
long long const bob = 1000000007;
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
 
    long long t, s;
    int colvo = 0;
 
    std::cin >> t >> s;
    std::vector<long long> v1;
 
    for (long long i = 1; i * i <= s; ++i) {
        if (s % i == 0) {
            long long j = s / i;
            if (i <= j) { 
                v1.push_back(i);
                v1.push_back(j);
                colvo++;
                if (i != j) {
                    v1.push_back(j);
                    v1.push_back(i);
                    colvo++;
                }
            }
        }
    }
 
    std::vector<long long> a(t*2);
 
    for (int i = 0; i < t*2; i +=2) {
        std::cin >> a[i] >> a[i+1];
    }
 
    /*
    for (int i = 0; i < colvo; ++i) {
        cout << v1[i] << " " << v2[i] << "\n";
    }
    */
 
    for (int i = 0; i < t*2; i +=2) {
        long long popa = 0;
        for (int k = 0; k < colvo*2; k+=2) {
            long long q1 = a[i] - 1 - v1[k];
            long long q2 = a[i + 1] - 1 - v1[k + 1];
            // cout << q1 << " //////// " << q2 << "\n";
            if (q1 > 0 && q2 > 0) {
                popa = (popa + q1 * q2) % bob;
            }
            else continue;
        }
        std::cout << popa << "\n";
    }
    return 0;
}


// Не прошло по времени на 10 тесте, но я решил все равно загрузить.