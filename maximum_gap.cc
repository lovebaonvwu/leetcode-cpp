class Solution {
 public:
  int maximumGap(vector<int>& nums) {
    int n = nums.size();

    if (n < 2) {
      return 0;
    }

    auto min_max = minmax_element(nums.begin(), nums.end());

    int minNum = *min_max.first;
    int maxNum = *min_max.second;

    int gap = (maxNum - minNum) / (n - 1) + 1;
    vector<int> bucketMin(n, INT_MAX);
    vector<int> bucketMax(n, INT_MIN);

    for (auto n : nums) {
      int bucket = (n - minNum) / gap;
      bucketMin[bucket] = min(bucketMin[bucket], n);
      bucketMax[bucket] = max(bucketMax[bucket], n);
    }

    int ans = bucketMax[0] - bucketMin[0];
    int prevMax = bucketMax[0];

    for (int i = 1; i < n; ++i) {
      if (bucketMin[i] == INT_MAX) {
        continue;
      }

      ans = max(ans, bucketMin[i] - prevMax);
      prevMax = bucketMax[i];
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 96.56%
// Memory Usage: 9 MB, less than 26.42%