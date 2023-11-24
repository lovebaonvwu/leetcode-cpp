class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    vector<int> presum(nums.size() + 1);

    for (int i = 1; i < presum.size(); ++i) {
      presum[i] = presum[i - 1] + nums[i - 1];
    }

    double ans = INT_MIN;
    for (int i = presum.size() - 1; i >= k; --i) {
      ans = max(ans, (presum[i] - presum[i - k]) / static_cast<double>(k));
    }

    return ans;
  }
};
// Runtime: 176 ms, faster than 59.27%
// Memory Usage: 18 MB, less than 33.33%

class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    int sum = 0;
    for (int i = 0; i < k; ++i) {
      sum += nums[i];
    }

    double ans = sum / static_cast<double>(k);
    for (int i = 1; i < nums.size() - k + 1; ++i) {
      sum -= nums[i - 1];
      sum += nums[i + k - 1];
      ans = max(ans, sum / static_cast<double>(k));
    }

    return ans;
  }
};
// Runtime: 180 ms, faster than 34.50%
// Memory Usage: 14.6 MB, less than 100.00%