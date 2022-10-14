struct DSU {
  vector<int> p;
  DSU(int n = 0) : p(n + 2, -1) {};
  int Root(int x) { return p[x] < 0 ? x : p[x] = Root(p[x]); }
  bool Unite(int u, int v) {
    u = Root(u); v = Root(v);
    if (u == v) return 0;
    if (p[u] > p[v]) swap(u, v);
    p[u] += p[v];
    p[v] = u;
    return 1;
  }
};