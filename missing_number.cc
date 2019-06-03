class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int sum = nums.size();

    for (int i = 0; i < nums.size(); ++i) {
      sum ^= i;
      sum ^= nums[i];
    }

    return sum;
  }
};  // 24ms

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != i) {
        return i;
      }
    }

    return nums.size();
  }
};  // 32ms