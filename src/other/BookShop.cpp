#include <bits/stdc++.h>

using namespace std;

void printVec2(vector<vector<int>>& vec) {
    for (auto& a : vec) {
        for (auto x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> prices(n+1);
    vector<int> pages(n+1);
    for (int i = 1; i <= n; i++)
        cin >> prices[i];

    for (int i = 1; i <= n; i++)
        cin >> pages[i];

    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i-1][j];

            if (j - prices[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j-prices[i]] + pages[i]);          
        }
    }

    printVec2(dp);
    cout << dp[n][x] << '\n';
}