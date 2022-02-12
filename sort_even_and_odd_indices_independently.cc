class Solution {
 public:
  vector<int> sortEvenOdd(vector<int>& nums) {
    vector<int> odd, even;

    for (int i = 0; i < nums.size(); ++i) {
      if (i & 1) {
        odd.push_back(nums[i]);
      } else {
        even.push_back(nums[i]);
      }
    }

    sort(odd.rbegin(), odd.rend());
    sort(even.begin(), even.end());

    for (int k = 0, i = 0, j = 0; k < nums.size(); ++k) {
      if (k & 1) {
        nums[k] = odd[i++];
      } else {
        nums[k] = even[j++];
      }
    }

    return nums;
  }
};
// Runtime: 15 ms, faster than 31.74%
// Memory Usage: 12.3 MB, less than 43.77%
// 2022.2.12 at 茗筑美嘉