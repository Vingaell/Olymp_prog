#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
 
    int money = 210;
    int loss = 0;
    int n, b, c, a;

    while(money <= 1000) {
        if (loss == 3) {
            cout << money << " R" << endl;
            cout.flush();
            cin >> n;
            money *=2;
            loss = 0;
            continue;
        }
        if (loss == 0) {
            b = money / 15;
            cout << b << " R" << endl;
            cout.flush();
            cin >> n;
            if (n == 1) {
                money += b;
                continue;
            }
            else {
                money -= b;
                loss ++;
                continue;
            }
        }
        if (loss == 1) {
            b = 2 * (money / 15);
            cout << b << " R" << endl;
            cout.flush();
            cin >> n;
            if (n == 1) {
                money += b;
                loss = 0;
                continue;
            }
            else {
                money -= b;
                loss ++;
                continue;
            }
        }
        if (loss == 2) {
            int c = 2 * b;
            cout << c << " R" << endl;
            cout.flush();
            cin >> n;
            if (n == 1) {
                money += c;
                loss = 0;
                continue;
            }
            else {
                money -= c;
                loss ++;
                continue;
            }
        }
    }

    return 0;
}




















































// Каждый лудоман останавливается перед самым главным выигрышем в своей жизни. На подумать. Деп. Деп. Деп. Додеп