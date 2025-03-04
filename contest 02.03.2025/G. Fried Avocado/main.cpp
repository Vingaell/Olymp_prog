#include <iostream>
#include <vector>
#include <algorithm>
 
int main() {
    int N, P, SUM;
    std::cin >> N;
    std::vector<int> S(N), colvo(N);
    P = -1;
    SUM = 0;
    for (int i = 0; i < N; ++i) {
        std::cin >> S[i];
        S[i]--;
        colvo[i] = 0;
    }
 
    std::vector<bool> alive(N, true);
    std::vector<bool> clear_circle(N, true);
    std::vector<bool> high(N, false);
 
    for (int i = 0; i < N; ++i) {
        int b = i;
        if (alive[i] == true && i != S[i]) {
            while (colvo[b] != 2 && clear_circle[b] == true) {
                alive[b] = false;
                colvo[b]++;
                if (high[b] == true) {
                    colvo[b]--;
                    high[b] = false;
                }
                // b = S[b];
                if (colvo[b] == 1) {
                    SUM++;
                    // Проверка 4
                    // std::cout << b << " ";
                }
                b = S[b];
            }
 
            // Отступ 4 проверки
            // std::cout << "\n";
 
            b = i;
            if (colvo[b] == 1) {
                high[b] = true;
                SUM--;
                while (clear_circle[S[b]] == true) {
                    b = S[b];
                    // SUM++;
                    clear_circle[b] = false;
                }
            }
            if (colvo[b] == 2 ) {
                // SUM--;
            }
        }
        if (alive[i] == true && i == S[i]) {
            SUM++;
            clear_circle[i] = false;
            alive[i] = false;
        }
    }
    // Проверка 2
    // for (int t = 0; t < N; ++t) { if (clear_circle[t] == true) { std::cout << "1" << " ";} else {std::cout << "0" << " ";}} std::cout << "\n";
    
     for (int i = 0; i < N; ++i) {
        int b = i;
        if (colvo[i] == 2 && clear_circle[S[i]] == true) {
            SUM--;
            while (clear_circle[b] == true) {
                clear_circle[b] = false;
                b = S[b];
                // SUM++;
            }
        }
    } 
    
    //  Проверка 1
    // for (int t = 0; t < N; ++t) { std::cout << colvo[t] << " "; } std::cout << "\n";
 
    // Проверка 3
    // for (int t = 0; t < N; ++t) { if (clear_circle[t] == true) { std::cout << "1" << " ";} else {std::cout << "0" << " ";}} std::cout << "\n";
 
    std::cout << SUM;
 
    return 0;
}