#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
 
int main() 
{

    int n, k;

    cin >> n >> k;

    k--;
    int y = n;
    int x = 1 + k*(n-1);

    double q = x*1.0 / y*1.0;

    cout << fixed << setprecision(6) << q;
    
    return 0;

}