class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    vector<int> sorted(nums);

    sort(sorted.begin(), sorted.end());

    int n = nums.size();

    for (int k = n - 1, i = 0, j = (n - 1) / 2 + 1; k >= 0; --k) {
      nums[k] = sorted[(k & 1) ? j++ : i++];
    }
  }
};
// Runtime: 20 ms, faster than 62.26%
// Memory Usage: 17.7 MB, less than 32.10%
// 2021.10.27 at 奥盛大厦