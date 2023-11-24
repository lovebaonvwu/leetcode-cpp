class Solution {
  struct Cmp {
    bool operator()(pair<string, int>& a, pair<string, int>& b) {
      if (a.first == b.first) {
        return a.second < b.second;
      } else {
        return a.first < b.first;
      }
    }
  } cmp;

 public:
  vector<int> smallestTrimmedNumbers(vector<string>& nums,
                                     vector<vector<int>>& queries) {
    vector<int> ans(queries.size());

    unordered_map<int, vector<pair<string, int>>> trimmed;

    for (int i = 0; i < queries.size(); ++i) {
      if (trimmed.find(queries[i][1]) == trimmed.end()) {
        for (int j = 0; j < nums.size(); ++j) {
          auto p = make_pair(nums[j].substr(nums[j].size() - queries[i][1]), j);
          trimmed[queries[i][1]].push_back(p);
        }

        sort(trimmed[queries[i][1]].begin(), trimmed[queries[i][1]].end(), cmp);
      }

      ans[i] = trimmed[queries[i][1]][queries[i][0] - 1].second;
    }

    return ans;
  }
};
// Runtime: 1687 ms, faster than 11.11%
// Memory Usage: 337 MB, less than 11.11%
// 2022.7.20 at 奥盛大厦