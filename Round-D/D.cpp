/**
 *  author: chaitanya
 *  created: 11:23:32 AM, 12 July 2020
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
    int n, q;
    cin >> n >> q;
    vi d(n - 1);
    trav(it, d) cin >> it;
    int s, k;
    while (q--) {
      cin >> s >> k;
      s--, k--;
      int now = s;
      debug(s);
      int left = s-1;
      int right = s;
      while (k--) {
        // int right = n, left = -1;
        // rep(i, s, n - 1) {
        //   if (!open[i]) {
        //     right = i;
        //     break;
        //   }
        // }
        // for (int i = (s - 1); i >= 0; i--) {
        //   if (!open[i]) {
        //     left = i;
        //     break;
        //   }
        // }
        if (left == -1) {
          s = right + 1;
          right++;
        } else if (right == (n-1)) {
          s = left;
          left--;
        } else if (d[right] > d[left]) {
          s = left;
          left--;
        } else {
          s = right + 1;
          right++;
        }
        debug(s);
      }
      cout << s + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}