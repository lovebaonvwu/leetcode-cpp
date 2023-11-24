class Solution {
 public:
  int dominantIndex(vector<int>& nums) {
    if (nums.size() == 1) {
      return 0;
    }

    int first = 0;
    int second = -1;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[first]) {
        second = first;
        first = i;
      } else if (second < 0 || nums[i] > nums[second]) {
        second = i;
      }
    }

    return (nums[first] >> 1) >= nums[second] ? first : -1;
  }
};