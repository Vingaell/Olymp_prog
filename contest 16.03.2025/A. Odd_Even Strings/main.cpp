#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    string str;
    cin >> str;

    int q = size(str);
    vector<int> v1(30, 0), v2(2, 0);
    // cout << size(v1);
    int p = 0;
    sort(begin(str), end(str));

    // cout << str;
    if (q == 1) {
        cout << "1";
        return 0;
    }

    for (int i = 1; i < q; i++) {
        if (str[i] == str[i-1]) {
            v1[p]++;
        }
        else {
            v1[p]++;
            p++;
        }
    }
    v1[p]++;

    for (int i = 0; i <= p; i++) {
        if (v1[i] % 2 == 0) {
            v2[0]++;
        }
        else { v2[1]++; }
    }

    if (v2[0] == 0) {
        cout << "1";
    }
    else if (v2[1] == 0) {
        cout << "0";
    }
    else { cout << "0/1"; }

    /* cout << "\n";
    for (int i = 0; i <= p; i++) {
        cout << v1[i] << " ";
    }
    cout << "\n";
    cout << v2[0] << " " << v2[1]; */

return 0;
}