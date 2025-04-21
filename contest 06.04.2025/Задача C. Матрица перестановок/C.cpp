#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
 
int main() {
    int n;
    long long U, D, L, R;
    cin >> n >> U >> D >> L >> R;
 
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--; 
    }
 
    vector<vector<int>> A(n);
    vector<bool> anapa2008(n, false);
    for (int i = 0; i < n; ++i) {
        if (!anapa2008[i]) {
            vector<int> cycle;
            int lol = i;
            while (!anapa2008[lol]) {
                anapa2008[lol] = true;
                cycle.push_back(lol);
                lol = p[lol];
            }
            for (int x : cycle) {
                A[x] = cycle;
            }
        }
    }
 
    vector<bool> anapa2009;
    int period = 1;
    for (int i = 0; i < n; ++i) {
        int lenght = A[i].size();
        period = lcm(period, lenght); 
    }
 
    for (int step = 0; step < period; ++step) {
        bool ok = true;
        for (int pos = L - 1; pos < R; ++pos) {
            const vector<int>& cyc = A[pos];
            int idx = 0;
            while (cyc[idx] != pos) idx++;
            int new_pos = cyc[(idx + step) % cyc.size()];
            if (new_pos != pos) {
                ok = false;
                break;
            }
        }
        anapa2009.push_back(ok);
    }
 
    long long count = 0;
    for (long long i = U; i <= D; ++i) {
        if (anapa2009[(i - 1) % period]) count++;
    }
 
    cout << count << '\n';
    return 0;
}