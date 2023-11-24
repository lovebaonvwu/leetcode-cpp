class Solution {
 public:
  vector<vector<string>> mostPopularCreator(vector<string>& creators,
                                            vector<string>& ids,
                                            vector<int>& views) {
    int n = creators.size();

    unordered_map<string, int> cur;
    unordered_map<string, int> sum;
    for (int i = 0; i < n; ++i) {
      auto& creator = creators[i];
      auto& id = ids[i];
      auto& view = views[i];

      sum[creator] += view;
      if (cur.find(creator) != cur.end()) {
        if (view > views[cur[creator]] ||
            (view == views[cur[creator]] && id < ids[cur[creator]])) {
          cur[creator] = i;
        }
      } else {
        cur[creator] = i;
      }
    }

    vector<pair<int, string>> p;
    for (auto& s : sum) {
      p.push_back({s.second, s.first});
    }

    sort(p.rbegin(), p.rend());

    vector<vector<string>> ans;
    auto& creator = p[0].second;
    ans.push_back({creator, ids[cur[creator]]});
    for (int i = 1; i < p.size() && p[i].first == p[i - 1].first; ++i) {
      auto& creator = p[i].second;
      ans.push_back({creator, ids[cur[creator]]});
    }

    return ans;
  }
};
// Runtime: 737 ms, faster than 92.37%
// Memory Usage: 125.7 MB, less than 99.07%
// 2022.11.3 at 奥盛大厦