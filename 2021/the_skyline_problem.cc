class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    if (buildings.empty()) {
      return {};
    }

    long max_ri = 0;

    for (auto& b : buildings) {
      max_ri = max<long>(max_ri, b[1]);
    }

    vector<int> h(max_ri + 1);

    for (auto& b : buildings) {
      for (long i = b[0]; i <= b[1]; ++i) {
        h[i] = max(h[i], b[2]);
      }
    }

    vector<vector<int>> ans;
    if (h[0] > 0) {
      ans.push_back({0, h[0]});
    }

    for (int i = 1, prev = h[0]; i < h.size(); ++i) {
      if (h[i] > prev) {
        ans.push_back({i, h[i]});
        prev = h[i];
      } else if (h[i] < prev) {
        ans.push_back({i - 1, h[i]});
        prev = h[i];
      }
    }

    ans.push_back({(int)max_ri, 0});

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<pair<int, int>> h;

    for (auto& b : buildings) {
      h.push_back({b[0], -b[2]});
      h.push_back({b[1], b[2]});
    }

    sort(h.begin(), h.end());

    multiset<int> mset = {0};
    int prev = 0, cur = 0;

    vector<vector<int>> ans;
    for (auto& p : h) {
      if (p.second < 0) {
        mset.insert(-p.second);
      } else {
        mset.erase(mset.find(p.second));
      }

      cur = *mset.rbegin();
      if (cur != prev) {
        ans.push_back({p.first, cur});
        prev = cur;
      }
    }

    return ans;
  }
};
// Runtime: 60 ms, faster than 81.41%
// Memory Usage: 15.1 MB, less than 76.38%