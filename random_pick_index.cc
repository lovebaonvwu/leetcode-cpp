class Solution {
  unordered_map<int, vector<int>> mp;

 public:
  Solution(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      mp[nums[i]].push_back(i);
    }
  }

  int pick(int target) {
    int select = rand() % mp[target].size();

    return mp[target][select];
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
// Runtime: 182 ms, faster than 13.01%
// Memory Usage: 51.8 MB, less than 40.83%
// 2022.1.6 at 奥盛大厦