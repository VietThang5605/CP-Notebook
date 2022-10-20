struct Dinic {
  const long long flow_inf = 1e18;
  vector<FlowEdge> edges;
  vector<vector<int>> adj;
  vector<int> level, ptr;
  int n, m = 0, s, t;

  Dinic() {}
  Dinic(int _n) {
    n = _n;
    adj.resize(n + 3);
    ptr.resize(n + 3);
    level.resize(n + 3);
  }

  void add_edge(int u, int v, long long cap) {
    edges.push_back(FlowEdge(u, v, cap));
    edges.push_back(FlowEdge(v, u, 0));
    adj[u].push_back(m);
    adj[v].push_back(m + 1);
    m += 2;
  }

  bool bfs() {
    for (int i = 1; i <= n; i++) level[i] = -1;
    queue<int> qe;
    qe.push(s);
    level[s] = 0;
    while (!qe.empty()) {
      int u = qe.front();
      qe.pop();
      for (int id : adj[u]) {
        int v = edges[id].v;
        if (level[v] == -1 && edges[id].cap - edges[id].flow > 0) {
          level[v] = level[u] + 1;
          qe.push(v);
        }
      }
    }
    return (level[t] >= 0);
  }

  long long dfs(int u, long long pushed) {
    if (pushed == 0) return 0;
    if (u == t) return pushed;
    for (int &cur = ptr[u]; cur < sz(adj[u]); cur++) {
      int id = adj[u][cur], v = edges[id].v;
      if (level[u] + 1 != level[v] | edges[id].cap - edges[id].flow < 1)
        continue;
      long long tr = dfs(v, min(pushed, edges[id].cap - edges[id].flow));
      if (tr == 0) continue;
      edges[id].flow += tr;
      edges[id ^ 1].flow -= tr;
      return tr;
    }
    return 0;
  }

  long long maxFlow(int _s, int _t) {
    s = _s; t = _t;
    for (FlowEdge &e : edges) e.flow = 0;
    long long res = 0;
    while (bfs()) {
      for (int i = 1; i <= n; i++) ptr[i] = 0;
      while (long long pushed = dfs(s, flow_inf))
        res += pushed;
    }
    return res;
  }
};