int fact[N], inv[N], finv[N];

void Init(int x) {
  fact[0] = fact[1] = 1;
  inv[0] = inv[1] = 1;
  finv[0] = finv[1] = 1;
  for (int i = 2; i <= x; i++) {
    fact[i] = 1ll * fact[i - 1] * i % Mod;
    inv[i] = 1ll * (Mod - Mod / i) * inv[Mod % i] % Mod;
    finv[i] = 1ll * finv[i - 1] * inv[i] % Mod;
  }
}

int C(int x, int y) {
  if (y > x) return 0;
  return 1ll * fact[x] * finv[y] % Mod * finv[x - y] % Mod;
}