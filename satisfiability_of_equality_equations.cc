class Solution {
  int parent[26];
  int Find(int x) {
    if (parent[x] != x) {
      parent[x] = Find(parent[x]);
    }

    return parent[x];
  }

  void Union(int x, int y) {
    if (x != y) {
      parent[x] = y;
    }
  }

 public:
  bool equationsPossible(vector<string>& equations) {
    for (int i = 0; i < 26; ++i) {
      parent[i] = i;
    }

    for (auto& e : equations) {
      int a = e[0] - 'a';
      int b = e[3] - 'a';
      char mark = e[1];

      int pa = Find(a);
      int pb = Find(b);

      if (mark == '=') {
        Union(pa, pb);
      }
    }

    for (auto& e : equations) {
      int a = e[0] - 'a';
      int b = e[3] - 'a';
      char mark = e[1];

      int pa = Find(a);
      int pb = Find(b);

      if (mark == '!' && pa == pb) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 3 ms, faster than 96.94%
// Memory Usage: 11.3 MB, less than 70.01%
// 2022.9.26 at 奥盛大厦