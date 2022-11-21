int szM;

struct Matrix {
  vector<vector<int>> v;

  Matrix(int k, int l) {
    szM = k;
    v.resize(k);
    for (int i = 0; i < k; i++) {
      v[i].resize(k);
      v[i][i] = l;
    }
  }
};

Matrix operator *(Matrix x, Matrix y) {
  assert(szM == (int)x.v.size());
  assert(szM == (int)y.v.size());
  Matrix res(6, 0);
  for (int i = 0; i < szM; i++) {
    for (int j = 0; j < szM; j++) {
      for (int k = 0; k < szM; k++) {
        res.v[i][j] = (res.v[i][j] + 1ll * x.v[i][k] * y.v[k][j] % Mod) % Mod;
      }
    }
  }
  return res;
}

Matrix pw(Matrix x, long long y) {
  if (y == 1) return x;
  Matrix t = pw(x, y / 2);
  t = t * t;
  if (y & 1) t = t * x;
  return t;
}