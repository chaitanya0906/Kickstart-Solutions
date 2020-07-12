/**
 *  author: chaitanya
 *  created: 10:46:57 AM, 12 July 2020
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

vector<int> twop;
int n, l, a, b;
vector<vector<int>> adj;
vector<vector<int>> up;
vector<int> depth;

// Binary Lifting
void dfs(int v, int p) {
  depth[v] = (depth[p] + 1);
  up[v][0] = p;
  for (int i = 1; i <= l; ++i)
    up[v][i] = up[up[v][i - 1]][i - 1];
  for (int u : adj[v])
    if (u != p)
      dfs(u, v);
}

void preprocess(int root) {
  l = ceil(log2(n));
  up.assign(n, vector<int>(l + 1));
  dfs(root, root);
}

int kthParent(int v, int plac) {
  if (plac == 0) {
    return v;
  }
  auto it = upper_bound(all(twop), plac);
  int x = it - twop.begin();
  x--;
  v = up[v][x];
  plac = plac - twop[x];
  return kthParent(v, plac);
}

void pre() {
  twop.push_back(1);
  for (int i = 0; i < 60; i++) {
    twop.push_back(twop.back() * 2);
  }
}
vector<double> A, B;

void dfs2(int x, int p) {
  trav(it, adj[x]) {
    if (it == p)
      continue;
    dfs2(it, x);
  }
  debug(depth[x]);
  if (depth[x] > a) {
    A[kthParent(x, a)] += A[x];
  }
}

void dfs3(int x, int p) {
  trav(it, adj[x]) {
    if (it == p)
      continue;
    dfs3(it, x);
  }
  debug(depth[x]);
  if (depth[x] > b) {
    // debug("HERE");
    B[kthParent(x, b)] += B[x];
  }
}

int32_t main() {
  // IOS;
  pre();
  int t = 1;
  cin >> t;
  rep(T, 1, t + 1) {
    cout << "Case #" << T << ": ";
    cin >> n >> a >> b;
    adj.assign(n, vi(0));
    A.assign(n, (double)1 / (double)n);
    B.assign(n, (double)1 / (double)n);
    depth.assign(n, 0);
    up = adj;
    int x, y;
    rep(i, 0, (n - 1)) {
      cin >> x;
      debug(x);
      x--;
      adj[i + 1].push_back(x);
      adj[x].push_back(i + 1);
    }
    preprocess(0);
    dfs2(0, 0);
    dfs3(0, 0);
    debug(A, B, depth);
    double ans = 0;
    rep(i, 0, n) { ans += A[i] + B[i] - (A[i] * B[i]); }
    cout << setprecision(10) << fixed << ans << endl;
  }
  return 0;
}