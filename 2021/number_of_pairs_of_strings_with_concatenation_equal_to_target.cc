class Solution {
 public:
  int numOfPairs(vector<string>& nums, string target) {
    int ans = 0;

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[i] + nums[j] == target) {
          ++ans;
        }

        if (nums[j] + nums[i] == target) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Runtime: 197 ms, faster than 16.24%
// Memory Usage: 67.2 MB, less than 59.13%
// 2021.10.6 at 茗筑美嘉

class Solution {
 public:
  int numOfPairs(vector<string>& nums, string target) {
    int ans = 0;

    unordered_map<string, int> mp;

    for (int i = 0; i < nums.size(); ++i) {
      string tail = target.substr(max((int)(target.size() - nums[i].size()), 0),
                                  nums[i].size());

      if (tail == nums[i]) {
        string prefix =
            target.substr(0, max((int)(target.size() - nums[i].size()), 0));

        if (mp.find(prefix) != mp.end()) {
          ans += mp[prefix];
        }
      }

      string head = target.substr(0, nums[i].size());

      if (head == nums[i]) {
        string suffix = target.substr(nums[i].size());
        if (mp.find(suffix) != mp.end()) {
          ans += mp[suffix];
        }
      }

      ++mp[nums[i]];
    }

    return ans;
  }
};
// Runtime: 24 ms, faster than 86.73%
// Memory Usage: 11.1 MB, less than 90.35%
// 2021.10.6 at 茗筑美嘉