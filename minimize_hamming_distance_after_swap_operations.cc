class Solution {
  int parents[100001];

  int find(int x) {
    if (parents[x] != x) {
      parents[x] = find(parents[x]);
    }

    return parents[x];
  }

  void _union(int x, int y) {
    if (x < y) {
      parents[y] = x;
    } else {
      parents[x] = y;
    }
  }

 public:
  int minimumHammingDistance(vector<int>& source,
                             vector<int>& target,
                             vector<vector<int>>& allowedSwaps) {
    int n = source.size();

    for (int i = 0; i < n; ++i) {
      parents[i] = i;
    }

    for (auto& a : allowedSwaps) {
      int px = find(a[0]);
      int py = find(a[1]);

      if (px != py) {
        _union(px, py);
      }
    }

    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n; ++i) {
      mp[find(parents[i])].push_back(i);
    }

    int ans = 0;
    for (auto& [k, v] : mp) {
      multiset<int> st;
      for (auto i : v) {
        st.insert(source[i]);
      }

      for (auto i : v) {
        if (st.find(target[i]) != st.end()) {
          st.erase(st.lower_bound(target[i]));
        }
      }

      ans += st.size();
    }

    return ans;
  }
};
// Runtime: 398 ms, faster than 87.96%
// Memory Usage: 126.9 MB, less than 87.04%
// 2022.4.27 at 奥盛大厦