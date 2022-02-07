class Solution {
 public:
  vector<int> pivotArray(vector<int>& nums, int pivot) {
    int n = nums.size();

    vector<int> ans(n);

    int less = 0, greater = 0, equal = 0;

    for (auto n : nums) {
      if (n < pivot) {
        ++less;
      } else if (n > pivot) {
        ++greater;
      } else {
        ++equal;
      }
    }

    int i = 0, j = less, k = less + equal;
    for (auto n : nums) {
      if (n < pivot) {
        ans[i++] = n;
      } else if (n > pivot) {
        ans[k++] = n;
      } else {
        ans[j++] = n;
      }
    }

    return ans;
  }
};
// Runtime: 377 ms, faster than 35.71%
// Memory Usage: 123.4 MB, less than 42.86%
// 2022.2.7 at 奥盛大厦