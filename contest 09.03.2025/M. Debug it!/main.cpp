#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, count, q, bob, r, value, k, k3, value3;
    int bob2, value2, count2;
    vector<int> v1, v2;
    cin >> n;
    string str;
    cin >> str;
    // cout << str[4];
    count = q = bob = value = r = value3 = 0;
    bob2 = value2 = k = count2 = k3 = 0;
    v1.push_back(0);
    v2.push_back(0);

    for ( int i = 0; i < n; i++) {
        if (str[i] == 'F') {
            count++;
        }
        else {
            q = i;
            break;
        }
        q = i;
    }

    if (q == n - 1) {
        cout << count;
        return 0;
    }

    for ( int i = n - 1; i > 0; i--) {
        if (str[i] == 'F') {
            count2++;
            r++;
        }
        else {
            break;
        }
    } 

    for ( int i = q; i < n - r ; i++) {
        if ( str[i] =='F') {
            // cout << "пушка - " << i << "\n";
            while (str[i] == 'F') {
                bob +=2;
                i++;
            }
            int p = i - q;
            if (p > bob) {
                // cout << p << " //////// " << bob << "\n";
                value = bob;
            }
            else {
                value = p;
                bob = p;
            }
            k++;
            // cout << "пушка - " << i << " " << k << "\n";
            v1.push_back(value);
        }
    }  

    int k2 = k;

     for (int i = n - 1 - r; i >= q; i--) {
        if (str[i] == 'F') {
            while (str[i] == 'F') {
                bob2 += 2;
                i--;
            }
            int p2 = n - 1 - r - i;
            if (p2 > bob2) {
                value2 = bob2;
            }
            else {
            value2 = p2;
            bob2 = p2;
            }
            v2.push_back(value2);
            k3++;
            /* if (v1[k] - v1[k-1] >= v2[k3] - v2[k3 - 1]) {
                k--;
                value = v1[k];
                value3 = v2[k3];
            }
            else {
                break;
            } */
        }
    } 

int net = value;
int k4 = k3;
for (int i = 0; i <= k; i++) {
    int tik = v1[i] + v2[k4];
    k4--;
   if ( tik < net ) {
    net = tik;
   }
}


     // cout << value << " " << value3 << " " << count2 << " " << count << "\n";
    count += net + count2;
    cout << count;


   /* cout << "\n";
    cout << k3 << " adf" << "\n";
    for (int i = 0; i <= k2; i++ ) {
        cout << " " << v1[i];
    }
    cout << "\n";
    for (int i = 0; i <= k3; i++ ) {
        cout << " " << v2[i]; 
    } */
    

return 0;
}