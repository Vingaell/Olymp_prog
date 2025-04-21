#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, string>> v1;
    vector<string> originals;

    for (int i = 0; i < n; ++i) {
        string second;
        cin >> second;
        v1.emplace_back(i, second); 
    }

    sort(v1.begin(), v1.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.second < b.second;
    });

    for (int i = 0; i < n; ++i) {
        originals.push_back(v1[i].second);
    }

    /*
    for (const auto& p : v1) {
        cout << p.first << " " << p.second << "\n"; 
    }
    cout  << "\n"; 
    */

    int z = 1;

        for (int q = 0; q < k; ++q) {
            if (originals[0][q] != originals[1][q]) {
                v1[0].second = originals[0].substr(0, q + 1);
                break;
            }
        }

    
    for (int i = z; i < n; ++i) {
        if (i < n - 1) {
            int cnt = 2;
            bool skip_prev = false, skip_next = false;
            for (int q = 0; q < k; ++q) {
                if (!skip_prev && originals[i][q] != originals[i - 1][q]) {
                    --cnt;
                    skip_prev = true;
                }
                if (!skip_next && originals[i][q] != originals[i + 1][q]) {
                    --cnt;
                    skip_next = true;
                }
                if (cnt == 0) {
                    v1[i].second = originals[i].substr(0, q + 1);
                    break;
                }
            }
        }
        else {
            for (int q = 0; q < k; ++q) {
                if (originals[i][q] != originals[i - 1][q]) {
                    v1[i].second = originals[i].substr(0, q + 1);
                    break;
                }
            }
            break;
        }
    }

    sort(v1.begin(), v1.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
        return a.first < b.first;
    });

    for (const auto& p : v1) {
        cout << p.second << "\n"; 
    }
    return 0;
}
