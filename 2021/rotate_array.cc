class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    k = k % nums.size();

    swap(nums, 0, nums.size() - 1);
    swap(nums, 0, k - 1);
    swap(nums, k, nums.size() - 1);
  }

  void swap(vector<int>& nums, int start, int end) {
    while (start < end) {
      int temp = nums[start];
      nums[start] = nums[end];
      nums[end] = temp;

      ++start;
      --end;
    }
  }
};