/**
 *  author: chaitanya
 *  created: 10:25:36 AM, 12 July 2020
 **/
#include <bits/stdc++.h>
using namespace std;

#define intll 1
#define interactive 0

#ifdef chaitanya
#include "/home/chaitanya/.templates/header.h"
#else
#define debug(x...)
#endif

#if !interactive
#define IOS                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);                      \
  cin.exceptions(cin.failbit);
#define endl "\n"
#else
#define IOS
#endif

#if intll
#define int long long int
#endif

#define ll long long
#define sz(a) (int)((a).size())
#define all(a) a.begin(), a.end()
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define F first
#define S second

const int N = 300009;
const int mod = 1000000007;

void pre() {}

int32_t main() {
  IOS;
  pre();
  int t = 1;
  cin >> t;
  rep(T, 1, t + 1) {
    cout << "Case #" << T << ": ";
    int n;
    cin >> n;
    vi v(n);
    trav(it, v) { cin >> it; }
    v.push_back(-1);
    int maxi = -1;
    int ans = 0;
    rep(i, 0, n) {
      if (v[i] > maxi and ((i == (n - 1)) || v[i] > v[i + 1])) {
        ans++;
      }
      maxi = max(maxi, v[i]);
    }
    cout << ans << endl;
  }
  return 0;
}