#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v1(n), v3(n);

    for (int i = 0; i < n; ++i) {
        cin >> v1[i];
    }

    for (int i = 0; i < n; ++i) {
        vector<int> v2(n, 0); 
        int a = i; 
        while (true) {
            if (v2[a] > 0) { 
                v3[i] = a + 1; 
                break;
            }
            v2[a]++;
            a = v1[a] - 1; 
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << v3[i] << " ";
    }

    return 0;
}