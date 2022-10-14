struct Trie {
  Trie *child[26];
  int numStop;
  Trie() {
    for (int i = 0; i < 26; i++) child[i] = NULL;
    numStop = 0;
  }
} *root = new Trie();

void Insert(const string &s) {
  Trie *cur = root;
  for (int i = 0; i < (int)s.size(); i++) {
    int x = s[i] - 'a';
    if (cur->child[x] == NULL)
      cur->child[x] = new Trie();
    cur = cur->child[x];
  }
  cur->numStop++;
}

bool Search(const string &s) {
  Trie *cur = root;
  for (int i = 0; i < (int)s.size(); i++) {
    int x = s[i] - 'a';
    if (cur->child[x] == NULL) return 0;
    cur = cur->child[x];
  }
  return 1;
}