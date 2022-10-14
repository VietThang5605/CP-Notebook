#include <bits/stdc++.h>

using namespace std;

template<class T1, class T2> bool minimize(T1 &x, T2 y) { return (x > y ? x = y, 1 : 0); }
template<class T1, class T2> bool maximize(T1 &x, T2 y) { return (x < y ? x = y, 1 : 0); }

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

using II = pair<int, int>;
using III = tuple<int, int, int>;

#define sz(a) (int)a.size()
#define all(a) (a).begin(), (a).end()

#define ft first
#define sd second
#define mp make_pair
#define mt make_tuple

void solve() {

}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
  #endif
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int tc = 1;
  // cin >> tc; cin.ignore();
  while (tc--)
    solve();
  return 0;
}
