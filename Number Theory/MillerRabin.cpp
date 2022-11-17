using u64 = uint64_t;
using u128 = __uint128_t;

vector<int> Prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

u64 pw2(u64 x, u64 y, u64 Mod) {
  if (y == 0) return 1;
  u64 t = pw2(x, y / 2, Mod);
  t = (u128) t * t % Mod;
  if (y & 1) t = (u128) t * x % Mod;
  return t;
}

bool isComposite(u64 n, u64 a, u64 d, int s) {
  u64 x = pw2(a, d, n);
  if (x == 1 || x == n - 1) return 0;
  for (int r = 1; r < s; r++) {
    x = (u128) x * x % n;
    if (x == n - 1) return 0;
  }
  return 1;
}

bool MillerRabin(u64 n) {
  if (n <= 4) return (n == 2 || n == 3);
  u64 d = n - 1;
  int s = 0;
  while (d % 2 == 0) {
    s++;
    d /= 2;
  }
  for (int a : Prime) if (n != a && n % a == 0) return 0;
  for (int a : Prime) {
    if (a >= n - 2) break;
    if (isComposite(n, a, d, s)) return 0;
  }
  return 1;
}