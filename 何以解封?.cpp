#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    vector<int> a(n+1, 0);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    // 反向0-1背包问题
    int re_sum = sum - x;
    // 书本价值和 < re_sum即可
    vector<int> dp(re_sum+1, 0);
    for(int j = a[0]; j <= re_sum; j++) {
        dp[j] = a[0];
    }
    for(int i = 1; i < n; i++) {
        for(int j = re_sum; j >= a[i]; j--) {
            dp[j] = max(dp[j], dp[j-a[i]]+a[i]);
        }
    }
    cout << sum - dp[re_sum] << endl;
    return 0;
}