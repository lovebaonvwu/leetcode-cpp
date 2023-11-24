class UnionFindSet {
 public:
  UnionFindSet(int n) : parents(vector<int>(n)) {
    for (int i = 0; i < n; ++i) {
      parents[i] = i;
    }
  }

  int find(int x) {
    if (parents[x] != x) {
      parents[x] = find(parents[x]);
    }

    return parents[x];
  }

  void union_(int x, int y) { parents[find(x)] = parents[find(y)]; }

 private:
  vector<int> parents;
};

class Solution {
 public:
  int largestComponentSize(vector<int>& A) {
    int n = *max_element(A.begin(), A.end());

    UnionFindSet ufs(n + 1);

    for (auto a : A) {
      for (int i = 2; i <= sqrt(a); ++i) {
        if (a % i == 0) {
          ufs.union_(a, i);
          ufs.union_(a, a / i);
        }
      }
    }

    unordered_map<int, int> mp;

    int ans = 1;
    for (auto a : A) {
      ans = max(ans, ++mp[ufs.find(a)]);
    }

    return ans;
  }
};
// Runtime: 284 ms, faster than 78.06%
// Memory Usage: 40.6 MB, less than 59.35%