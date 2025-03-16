#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v1(5), v2(5, 0);
    
    for (int i = 0; i < 5; ++i) {
        cin >> v1[i];
    }
    // cout << " FSDFSF";

    // sort(begin(v1), end(v1));

for (int i = 0; i < 5; i++) {
    for (int k = 0; k < 5; k++) {
        for (int i3 = 0; i3 < 5; i3++) {
            for (int i4 = 0; i4 < 5; i4++) {
                for (int i5 = 0; i5 < 5; i5++) {
                    if ( i != k && i != i3 && i != i4 && i != i5 && k != i3 && k != i4 && k != i5 && i3 != i4 && i3 != i5 && i5 != i4) {
                        if (v1[i] == v1[k] + v1[i3] + v1[i4]) {
                            if (v1[i5] == v1[k] * 3 + v1[i3]) {
                                cout << v1[i] << " " << v1[k] << " " << v1[i3] << " " << v1[i4] << " " << v1[i5];
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
}


return 0;
}