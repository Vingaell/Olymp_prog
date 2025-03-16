#include <iostream>
#include <vector>
#include <algorithm>
 
int main() {
    long long n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<long long> mag(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> mag[i];
    }
    // Очевидно
    if (n <= m) {
        std::cout << "lyw";
        return 0;
    }
    
    mag.push_back(m); // после добавления этой строчки программа стала ломаться на 16 тесте, а не 13
    
    // Проверка начальной позиции
    if (n % (m+1) == 0) {
        std::cout << "zyw";
        return 0;
    }
 
    int q = n / (m + 1);
    int n1 = q * (m + 1);
 
    // Проверка после хода первого игрока 
    for (int i = 0; i < k; ++i) {
        if (n1 % (mag[i] + 1) == 0) {
            std::cout << "zyw";
            return 0;
        }
        /* q = n1 / (mag[i] + 1);
        int n2 = q * (mag[i] + 1);
        for (int j = 0; j < k; ++j) {
            if (i != j) {
                if (n2 % (mag[j] + 1) == 0) {
                    std::cout << "zyw";
                    return 0;
                } 
            }
        } */
    }
 
    // mag.push_back(m); - если подключать эту штучку до всех действий, то программа падает на 14 тесте, а не на 13. На подумать.
    std::sort(begin(mag), end(mag));
 
    if ( k > 1) {
        // Если мы "успеваем" сделать две замены, то zyw побеждает гарантированно
        int popa = ((mag[0]+1)*(mag[1]+1));
        if (popa <= n1) {
            std::cout << "zyw";
            return 0;
        }
        // Если мы можем сделать две одинаковые замены, то мы так же побеждаем.
        for (int i = 0; mag[i] + 1 < n1; ++i) {
            if (mag[i] == mag[i+1]) {
                std::cout << "zyw";
                return 0;
            }
        }
    }
    
    std::cout << "lyw";
    return 0;
}