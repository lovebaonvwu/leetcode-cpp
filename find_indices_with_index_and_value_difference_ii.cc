class Solution {
 public:
  vector<int> findIndices(vector<int>& nums,
                          int indexDifference,
                          int valueDifference) {
    int n = nums.size();
    int maxi = 0, mini = 0;
    for (int i = indexDifference; i < n; ++i) {
      if (nums[i - indexDifference] > nums[maxi]) {
        maxi = i - indexDifference;
      }
      if (nums[i - indexDifference] < nums[mini]) {
        mini = i - indexDifference;
      }

      if (abs(nums[i] - nums[maxi]) >= valueDifference) {
        return {maxi, i};
      }

      if (abs(nums[i] - nums[mini]) >= valueDifference) {
        return {mini, i};
      }
    }

    return {-1, -1};
  }
};
// 109ms
// 79.82MB