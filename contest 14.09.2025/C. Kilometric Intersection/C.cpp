#include <iostream>
#include <vector>
#include <algorithm> 
#include <utility>  
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;

    std::vector<std::pair<long long, long long>> v1(n);
    std::vector<std::pair<long long, long long>> v2(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> v1[i].first >> v1[i].second;
        std::cin >> v2[i].first >> v2[i].second;
        
        if (v2[i].first < v1[i].first) {
            std::swap(v1[i], v2[i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (v1[i].second <= v2[i].first ) {
            std::cout << "0";
        }
        else if (v2[i].second > v1[i].second ) {
            std::cout << std::abs(v2[i].first - v1[i].second);
        }
        else {
            std::cout << std::abs(v2[i].second - v2[i].first);
        }
        std::cout << "\n";
    }


/*
    for (int i = 0; i < n; ++i) {
        std::cout << v1[i].first << " " << v1[i].second << " ";
        std::cout << v2[i].first << " " << v2[i].second << std::endl;
    }

*/
    return 0;
}