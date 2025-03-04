#include <iostream>
#include <vector>
#include <algorithm>
 
int main() {
long long N, L, Q, input;
std::vector<long long> v1; 
std::cin >> N >> L >> Q;
 
std::vector<long long> p(Q);
std::vector<long long> w(Q);
 
v1.resize(N);
for (int i = 0; i < N; ++i) {
    std::cin >> v1[i];
}
 
for (int i = 0; i < Q; ++i) {
    std::cin >> p[i] >> w[i];
}
 
for (int i = 0; i < Q; ++i) {
    long long target = v1[N - 1] * p[i];
    auto pos = std::upper_bound(v1.begin(), v1.end(), target / w[i]) - v1.begin();
    int popa = N - pos;
 
    std::cout << popa << "\n";
}
return 0;
}