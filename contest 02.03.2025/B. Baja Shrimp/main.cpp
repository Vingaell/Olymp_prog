#include <iostream>
#include <vector>
#include <algorithm>
 
int main() {
    int N, MIN, MAX, MAX_index, MIN_index;
    long long SUM, MAX_SC;
    MAX = 0;
    bool q = true;
    SUM = 0;
    std::cin >> N;
    std::vector<int> S, C;
 
    S.resize(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> S[i];
    }
 
    C.resize(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> C[i];
    }
 
    MIN = S[0]; 
    MIN_index = 0;
 
    if (N == 1) {
        if (S[0] < C[0]) {
            q = false;
        }
    }
    if (N > 1) {
        for (int i = 0; i < N; ++i) {
            SUM = SUM + S[i] - C[i];
            if (SUM < 0) {
                MAX_SC = -1;
                MAX = -1;
 
                for (int k = i + 1; k < N; ++k) {
                    long long diff = S[k] - C[k];
                    if (diff > MAX_SC || (diff == MAX_SC && S[k] > MAX)) {
                        MAX_SC = diff;
                        MAX = S[k];
                        MAX_index = k;
                    }
                }
 
                for (int k = 0; k <= i; ++k) {
                    if (S[k] < MIN) {
                        MIN = S[k];
                        MIN_index = k;
                    }
                }
 
                S[MAX_index] = MIN;
                S[MIN_index] = MAX;
                break;
            }
        }
    }
 
    SUM = 0;
    for (int i = 0; i < N; ++i) {
        SUM = SUM + S[i] - C[i];
        if (SUM < 0) {
            q = false;
            break;
        }
    }
 
    if (q == false) {
        std::cout << "No";
    } else if (q == true) {
        std::cout << "Yes";
    }
 
    return 0;
}