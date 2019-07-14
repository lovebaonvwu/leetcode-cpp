class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int ans;
    int min = INT_MAX;

    sort(nums.begin(), nums.end());

    int n = nums.size();

    for (int i = 0; i < n - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      for (int j = i + 1; j < n - 1; ++j) {
        if (j > i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }

        for (int k = j + 1; k < n; ++k) {
          if (k > j + 1 && nums[k] == nums[k - 1]) {
            continue;
          }

          int sum = nums[i] + nums[j] + nums[k];

          int sub = abs(sum - target);

          if (sub < min) {
            min = sub;
            ans = sum;
          }
        }
      }
    }

    return ans;
  }
};  // 204ms