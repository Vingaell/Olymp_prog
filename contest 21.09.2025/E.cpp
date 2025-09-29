#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {

    int  m, n;
    int d1, d2;

    std::cin >> n >> m;
    int bob = (n*(n-1))/2;
    // std::cout << bob << "\n";
    if (m > bob) {
        std::cout << "-1";
        return 0;
    }

    d1 = n - m;
    if (d1 < 1) d1 = 1;

    double popa = (1 + sqrt(1+8.0*m))/2;
    int popa1 = ceil(popa); 
    // std::cout << popa1;
    d2 = n + 1 - popa1;

    std::cout << d1 << " " << d2;
    return 0;
}