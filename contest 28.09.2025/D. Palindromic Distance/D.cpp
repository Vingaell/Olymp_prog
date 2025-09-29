#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    vector<string> bob(t);
    
    for (int i = 0; i < t; i++) {
        cin >> bob[i];
    }
    
    for (int idx = 0; idx < t; idx++) {
        string s = bob[idx];
        int n = s.length();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                if (s[i] == s[j]) {
                    if (len == 2) {
                        dp[i][j] = 0;  
                    } else {
                        dp[i][j] = dp[i+1][j-1];  
                    }
                } else {
                    int delete_left = dp[i+1][j] + 1;
                    int delete_right = dp[i][j-1] + 1;
                    int replace = dp[i+1][j-1] + 1;
                    dp[i][j] = min({delete_left, delete_right, replace});
                }
            }
        }
        
        cout << dp[0][n-1] << "\n";
    }
    
    return 0;
}