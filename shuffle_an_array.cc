class Solution {
  vector<int> nums_;
  vector<int> ans;

 public:
  Solution(vector<int>& nums) { ans = nums_ = nums; }

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() { return nums_; }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    for (int i = ans.size() - 1; i > 0; --i) {
      int j = rand() % (i + 1);
      swap(ans[i], ans[j]);
    }

    return ans;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// Runtime: 100 ms, faster than 62.28%
// Memory Usage: 90.1 MB, less than 89.94%
// 2021.7.20 at 奥盛大厦