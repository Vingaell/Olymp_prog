#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <math.h>

using namespace std;


bool isPrime(int n)
{
    if (n == 1)
        return false; 

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

int main() {

    int t;

    cin >> t;
    
    vector<int> v1(t), v2(t);

    for (int i = 0; i < t; ++i) {
        cin >> v1[i] >> v2[i];
    }

    for (int i = 0; i < t; ++i) {
        if (v1[i] != (v2[i] - 2)) cout << "N\n";
        else if (isPrime(v1[i]) && isPrime(v2[i])) cout << "Y\n";
        else cout << "N\n";
    }

    return 0;

}
