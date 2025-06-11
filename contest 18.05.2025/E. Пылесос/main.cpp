#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n = 99;
    vector<vector<int>> a(n, vector<int>(n, 1));

    int i = 49, j = 49; 
    a[i][j] = 0; 

    stack<char> backtrack;


    const char directions[] = {'U', 'D', 'L', 'R'};
    const int di[] = {-1, 1, 0, 0};
    const int dj[] = {0, 0, -1, 1};
    const char opposite[] = {'D', 'U', 'R', 'L'}; 

    while (true) {
        bool moved = false;

        for (int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];

            if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

            if (a[ni][nj] == 1) {
                cout << directions[d] << endl;
                cout.flush();

                int res;
                cin >> res;
                if (res == 1) {

                    i = ni;
                    j = nj;
                    a[i][j] = 0; 
                    backtrack.push(opposite[d]);
                    moved = true;
                    break;
                } else {

                    a[ni][nj] = -1;
                }
            }
        }

        if (!moved) {
            if (backtrack.empty()) {
                cout << "!" << endl;
                cout.flush();
                return 0; 
            }
            char back_step = backtrack.top();
            backtrack.pop();

            cout << back_step << endl;
            cout.flush();

            int res;
            cin >> res;

            int idx = -1;
            for (int d = 0; d < 4; d++) {
                if (directions[d] == back_step) {
                    idx = d;
                    break;
                }
            }
            if (idx != -1) {
                i += di[idx];
                j += dj[idx];
            }
        }
    }

    return 0;
}
