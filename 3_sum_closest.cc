class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int ans;
    int min = INT_MAX;

    int n = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int j = i + 1;
      int k = n - 1;

      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        int sub = abs(sum - target);

        if (sub < min) {
          min = sub;
          ans = sum;
        }

        if (sum < target) {
          do {
            ++j;
          } while (j < k && nums[j] == nums[j - 1]);
        } else if (sum > target) {
          do {
            --k;
          } while (j < k && nums[k] == nums[k + 1]);
        } else {
          return ans;
        }
      }
    }

    return ans;
  }
};  // 12ms

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