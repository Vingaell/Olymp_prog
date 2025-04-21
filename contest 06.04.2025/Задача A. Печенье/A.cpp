#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <utility>
using namespace std;
 
int main() {
 
    long long n, a, b, c;
 
    cin >> n >> a >> b >> c;
 
    vector<int> v1(3);
    v1[0] = a;
    v1[1] = b;
    v1[2] = c;
     
    sort(v1.begin(), v1.end());
    if (v1[0] + v1[1] >= v1[2]) {
        long long q = a + b + c;
        cout << q;
        return 0;
    }
 
    else {
        if (v1[2] > v1[0] + v1[1] + 1) {
            int q = v1[0]*2 + v1[1]*2 + 1;
            v1[2] -= v1[0] + v1[1] + 1;
            if (v1[2] >= n - 1) {
                q += n - 1;
            }
            else {
                q += v1[2];
            }
            cout << q;
            return 0;
        }
        else {
            int q = a + b + c;
            cout << q;
            return 0;
        }
    }
 
     
 
return 0;
}