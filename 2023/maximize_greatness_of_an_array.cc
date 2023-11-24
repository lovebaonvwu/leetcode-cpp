class Solution {
 public:
  int maximizeGreatness(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int ans = 0;
    for (int i = 0, j = 0; i < nums.size(); ++i) {
      if (nums[i] > nums[ans]) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime 146 ms
// Memory 75.8 MB