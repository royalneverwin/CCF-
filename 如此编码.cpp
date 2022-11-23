#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
  ll n, m;
  scanf("%lld %lld", &n, &m);
  vector<ll> a(n+1, 0);
  for(int i = 1; i <= n; i++){
    scanf("%lld", &a[i]);
  }
  vector<ll> b(n+1, 0);
  vector<ll> c(n+1, 0);
  c[0] = 1;
  for(int i = 1; i <= n; i++){
    c[i] = c[i-1] * a[i];
  }
  ll preSum = 0;
  for(int i = 1; i <= n; i++){
    ll tmp = m % c[i];
    b[i] = (tmp - preSum) / c[i-1];
    preSum += c[i-1] * b[i];
  }
  for(int i = 1; i <= n; i++){
    cout << b[i] << ' ';
  }
  cout << endl;
  return 0;
}