class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int v_size = nums.size();

    if (v_size <= 2) {
      return v_size;
    }

    int slow = 0;
    for (int fast = 2; fast < v_size; ++fast) {
      if (nums[slow] != nums[fast]) {
        nums[slow + 2] = nums[fast];
        ++slow;
      }
    }

    return slow + 2;
  }
};  // 12ms