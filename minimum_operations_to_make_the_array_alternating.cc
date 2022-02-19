class Solution {
  array<int, 3> topfreq(vector<int>& nums, int start) {
    int first = 0, second = 0, cnt[100001] = {0};

    for (int i = start; i < nums.size(); i += 2) {
      cnt[nums[i]]++;

      if (cnt[nums[i]] >= cnt[first]) {
        if (nums[i] != first) {
          second = first;
        }
        first = nums[i];
      } else if (cnt[nums[i]] > cnt[second]) {
        second = nums[i];
      }
    }

    return {first, cnt[first], cnt[second]};
  }

 public:
  int minimumOperations(vector<int>& nums) {
    auto even = topfreq(nums, 0), odd = topfreq(nums, 1);

    return nums.size() - (even[0] == odd[0]
                              ? max(even[1] + odd[2], even[2] + odd[1])
                              : (even[1] + odd[1]));
  }
};
// Runtime: 238 ms, faster than 94.68%
// Memory Usage: 103.3 MB, less than 96.49%
// 2022.2.19 at 茗筑美嘉