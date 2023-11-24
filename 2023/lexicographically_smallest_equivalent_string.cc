class Solution {
  int parent[26];

  int Find(int x) {
    if (parent[x] != x) {
      parent[x] = Find(parent[x]);
    }

    return parent[x];
  }

  void Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);

    if (px == py) {
      return;
    }

    if (px > py) {
      parent[px] = py;
    } else {
      parent[py] = px;
    }
  }

 public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    for (int i = 0; i < sizeof(parent) / sizeof(int); ++i) {
      parent[i] = i;
    }

    for (int i = 0; i < s1.size(); ++i) {
      Union(s1[i] - 'a', s2[i] - 'a');
    }

    string ans;
    for (auto c : baseStr) {
      ans.push_back(Find(c - 'a') + 'a');
    }

    return ans;
  }
};
// Runtime 0 ms
// Memory 6.4 MB
// 2023.1.14 at 茗筑美嘉