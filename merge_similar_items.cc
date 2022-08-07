class Solution {
 public:
  vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1,
                                        vector<vector<int>>& items2) {
    map<int, int> mp;

    for (auto& item : items1) {
      mp[item[0]] += item[1];
    }

    for (auto& item : items2) {
      mp[item[0]] += item[1];
    }

    vector<vector<int>> ans;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
      ans.push_back({it->first, it->second});
    }

    return ans;
  }
};
// Runtime: 64 ms, faster than 60.00%
// Memory Usage: 16.8 MB, less than 40.00%
// 2022.8.7 at 奥盛大厦