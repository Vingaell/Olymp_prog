#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> popa(n);
    for (int i = 0; i < n; i++) {
        std::cin >> popa[i];
    }
    
    long long total = 0;
    for (int i = 0; i < n; i++) {
        int index = i + 1; 
        total += popa[i] * index * (n - i);
    }
    
    std::cout << total;
    return 0;
}