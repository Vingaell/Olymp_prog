#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int k;
    cin >> k;

    vector<int> x1(k), y1(k), x2(k), y2(k);
    vector<int> x3(k), y3(k), x4(k), y4(k);
    
    for (int i = 0; i < k; ++i) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        cin >> x3[i] >> y3[i] >> x4[i] >> y4[i];
        if (x1[i] > x2[i]) {
            swap(x1[i], x2[i]);
        }
        if (x3[i] > x4[i]) {
            swap(x3[i], x4[i]);
            swap(y3[i], y4[i]);
        }
        if (y1[i] > y2[i]) {
            swap(y1[i], y2[i]);
        }
    }

    for (int i = 0; i < k; ++i) {

        double q1 = 0, q2 = 0, q3 = 0, q4 = 0;
        bool popa = true;

        // Случай когда степлер находится полностью внутри екрана
        if (x3[i] >= x1[i] && x4[i] <= x2[i] && max(y3[i], y4[i]) <= y2[i] && min(y3[i], y4[i]) >= y1[i]) popa = false;

        // точка
        if (x3[i] == x4[i] && y3[i] == y4[i]) {
            if (x3[i] >= x1[i] && x3[i] <= x2[i] && y3[i] >= y1[i] && y3[i] <= y2[i]) {
                popa = false; 
            }
        }

        // Вертикальный отрезок
        else if (x3[i] == x4[i]) {
            if (x3[i] >= x1[i] && x3[i] <= x2[i]) {
                if (max(y1[i], min(y3[i], y4[i])) <= min(y2[i], max(y3[i], y4[i]))) {
                    popa = false;
                }
            }
        }
        // Горизонтальный отрезок  
        else if (y3[i] == y4[i]) {
            if (y3[i] >= y1[i] && y3[i] <= y2[i]) {
                if (max(x1[i], min(x3[i], x4[i])) <= min(x2[i], max(x3[i], x4[i]))) {
                    popa = false;
                }
            }
        }

        else {
            
            q1 = y3[i] + (double)(y4[i] - y3[i]) * (x1[i] - x3[i]) / (x4[i] - x3[i]); 
            q2 = y3[i] + (double)(y4[i] - y3[i]) * (x2[i] - x3[i]) / (x4[i] - x3[i]); 
            
            if (q1 >= y1[i] && q1 <= y2[i]) {
                double t = (double)(x1[i] - x3[i]) / (x4[i] - x3[i]);
                if (t >= 0 && t <= 1) popa = false;
            }
            if (q2 >= y1[i] && q2 <= y2[i]) {
                double t = (double)(x2[i] - x3[i]) / (x4[i] - x3[i]);
                if (t >= 0 && t <= 1) popa = false;
            }

            q3 = x3[i] + (double)(x4[i] - x3[i]) * (y1[i] - y3[i]) / (y4[i] - y3[i]); 
            q4 = x3[i] + (double)(x4[i] - x3[i]) * (y2[i] - y3[i]) / (y4[i] - y3[i]); 
            
            if (q3 >= x1[i] && q3 <= x2[i]) {
                double t = (double)(y1[i] - y3[i]) / (y4[i] - y3[i]);
                if (t >= 0 && t <= 1) popa = false;
            }
            if (q4 >= x1[i] && q4 <= x2[i]) {
                double t = (double)(y2[i] - y3[i]) / (y4[i] - y3[i]);
                if (t >= 0 && t <= 1) popa = false;
            }
        }

        if (popa == true) cout << "OK\n";
        else cout << "STOP\n";
    }
    return 0;
}