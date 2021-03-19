class Solution {
 public:
  int countMatches(vector<vector<string>>& items,
                   string ruleKey,
                   string ruleValue) {
    int ans = 0;

    for (auto& item : items) {
      if (ruleKey == "type" && item[0] == ruleValue) {
        ++ans;
      } else if (ruleKey == "color" && item[1] == ruleValue) {
        ++ans;
      } else if (ruleKey == "name" && item[2] == ruleValue) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 72 ms, faster than 100.00%
// Memory Usage: 30.7 MB, less than 100.00%