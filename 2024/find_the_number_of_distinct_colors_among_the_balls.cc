class Solution {
 public:
  vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    unordered_map<int, int> color;
    unordered_map<int, int> mp;
    vector<int> ans;

    for (auto& q : queries) {
      int ball = q[0];
      int c = q[1];

      if (mp.find(ball) != mp.end()) {
        if (mp[ball] != c) {
          --color[mp[ball]];
          if (color[mp[ball]] == 0) {
            color.erase(mp[ball]);
          }
          mp[ball] = c;
          ++color[c];
        }
      } else {
        mp[ball] = c;
        ++color[c];
      }

      ans.push_back(color.size());
    }

    return ans;
  }
};
// 366 ms
// 157.02 MB