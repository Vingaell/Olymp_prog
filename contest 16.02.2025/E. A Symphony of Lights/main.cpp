#include <iostream>
#include <vector>

int main() {
    int N, X, Y, Z;
bool q = false;
std::cin >> N >> X >> Y;
std::vector<int> v1, v2(N);
Z = N - Y + 1;
for (int i = 0; i < N; ++i) {
    v1.push_back(i + 1);
}
if (Y >= X || Z >= X) {
    q = true;
}
 // std::cout << N << " " << X << " " << Y << " " << Z;
 if (q == false) {
    std::cout << "No" << "\n";
 }
 else { std::cout << "Yes" << "\n"; 
    if (Y >=X) {
        for (int i = 0; i < N; ++i) {
            if (Y - X + i < N) { 
                v2[i] = Y - X + 1 + i;
            }
            else {
              v2[i] = N - i;  
            }
        }
    }
    else {
        for (int i = 0; i < N; ++i) {
           if ( Y + X - i > 1 ) {
            v2[i] = Y + X - 1 - i;
           }
           else { 
            v2[i] = i + 1;
           }
        }
    }
}
if (q == true) {
for (int i = 0; i < N-1; ++i) {
    std::cout << v2[i] << " ";
}
std::cout << v2[N-1];
    return 0;
}
}