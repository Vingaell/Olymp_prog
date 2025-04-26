#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t;
    vector<pair<string, string>> answer(t);

    for (int i = 0; i < t; ++i) {
        int n;
        int popa = -1;
        int bob = - 1;
        int max1, min1;
        bool obama = false;
        cin >> n;
        vector<pair<int, int>> cards(n);

        for (int k = 0; k < n; ++k) {
            cin >> cards[k].first >> cards[k].second;
        }

        sort(cards.begin(), cards.end(), 
    [](const pair<int, int>& a, const pair<int, int>& b) {
        return abs(a.first - a.second) < abs(b.first - b.second);
    });

        /*
        cout << "Отсортированные пары:\n";
        for (int k = 0; k < n; ++k) {
            cout << cards[k].first << " " << cards[k].second << "\n"; 
        }
        */


        for (int k = 0; k < n; ++k) {
            if (cards[k].first != 0 && cards[k].second != 0) {
                if (cards[k].first != cards[k].second) {
                    obama = true;
                    if (cards[k].first > cards[k].second) {
                        max1 = cards[k].first;
                        min1 = cards[k].second;
                    }
                    else {
                        min1 = cards[k].first;
                        max1 = cards[k].second;
                    }
                    answer[i].first += '0' + max1;
                    answer[i].second += '0' + min1;
                }
                else {
                    answer[i].first = to_string(cards[k].first);
                    answer[i].second = to_string(cards[k].second);
                }
                bob = k;
                break;
            }
        }



        if (obama == false) {
            // cout << "s";
            for (int k = 0; k < n; ++k) {
                if (k != bob) {
                    if (cards[k].first == cards[k].second) {
                        answer[i].first += '0' + cards[k].first;
                        answer[i].second += '0' + cards[k].second;
                        popa = k;
                    }
                    else {
                        // cout << "s";
                        if (cards[k].first > cards[k].second) {
                            max1 = cards[k].first;
                            min1 = cards[k].second;
                        }
                        else {
                            min1 = cards[k].first;
                            max1 = cards[k].second;
                        }
                        answer[i].first += '0' + max1;
                        answer[i].second += '0' + min1;
                        popa = k;
                        break;
                    }
                }
            }
        }

        for (int k = n - 1; k > popa; --k) {
            // cout << bob << "\n";
            if (k != bob) {
                // cout << "b";
                if (cards[k].first > cards[k].second) {
                    max1 = cards[k].first;
                    min1 = cards[k].second;
                }
                else {
                    min1 = cards[k].first;
                    max1 = cards[k].second;
                }
                answer[i].first += '0' + min1;
                answer[i].second += '0' + max1;
            }
        }
    }

    for (int i = 0; i < t; ++i) {
        cout << answer[i].first << "\n";
        cout << answer[i].second << "\n";
    }
    return 0;
}
