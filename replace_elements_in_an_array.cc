class Solution {
 public:
  vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); ++i) {
      mp[nums[i]] = i;
    }

    for (auto& op : operations) {
      int src = op[0];
      int dst = op[1];

      int index = mp[src];
      mp[dst] = index;
      nums[index] = dst;
      mp.erase(src);
    }

    return nums;
  }
};
// Runtime: 800 ms, faster than 14.29%
// Memory Usage: 129.4 MB, less than 71.43%
// 2022.6.5 at 茗筑美嘉