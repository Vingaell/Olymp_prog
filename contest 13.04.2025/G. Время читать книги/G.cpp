#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<tuple<long long, long long, long long>> books(n); 

    for (long long i = 0; i < n; ++i) {
        long long t, d;
        cin >> t >> d;
        books[i] = {t, d, i + 1};
    }

    long long left = 1;
    long long right = 0; 

    for (auto &[t, d, id] : books) right += t;

    long long ans = -1;

    while (left <= right) {
        long long mid = (left + right) / 2;

        long long i = 0, day = 1;
        while (day <= m && i < n) {
            long long timeLeft = mid;
            while (i < n && get<1>(books[i]) >= day && get<0>(books[i]) <= timeLeft) {
                timeLeft -= get<0>(books[i]);
                i++;
            }
            day++;
        }

        if (i == n) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";

    vector<long long> result(m, 0);
    long long i = 0;
    for (long long day = 0; day < m; ++day) {
        long long timeLeft = ans;
        long long lastBook = 0;
        while (i < n && get<1>(books[i]) >= day + 1 && get<0>(books[i]) <= timeLeft) {
            timeLeft -= get<0>(books[i]);
            lastBook = get<2>(books[i]);
            i++;
        }
        result[day] = lastBook;
    }

    for (long long x : result) cout << x << "\n";

    return 0;
}






