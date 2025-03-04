#include <iostream>
#include <vector>
 
int main() {
    std::vector<int> v1;
    int input;
    bool op = false;
    bool oil = false;
    int popa = 0;
    for (int i = 0; i < 5; ++i) {
        std::cin >> input;
        v1.push_back(input);
    }
 
    for (int j = 0; j < 5; ++j) {
        v1[j] = v1[j] + 1;
        for (int k = 0; k < 5; ++k) {
            v1[k] = v1[k] + 1;
            if (v1[k] == 4) {
                oil = true;
            }
            else if (v1[k] == 5) {
                op = true;
            }
            for (int q = 0; q < 5; ++q) {
                  if (v1[q] > 0) {
                    popa = popa + 1;
                  }  
                  if (popa == 4) {
                    oil = true;
                  }
                  if (popa == 5) {
                    op = true;
                  }
                  if (v1[q] == 0) {
                    popa = 0;
                  }  
                }
            v1[k] = v1[k] - 1;
            popa = 0;
        }
        v1[j] = v1[j] - 1;
    }
 
    if (op == true ) {
        std::cout << "op";
    }
    else if (oil == true) {
        std::cout << "add oil";
    }
    else {
        std::cout << "gg";
    }
return 0;
}