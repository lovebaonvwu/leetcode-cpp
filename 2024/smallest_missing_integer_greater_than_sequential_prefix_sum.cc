class Solution {
 public:
  int missingInteger(vector<int>& nums) {
    int sum = nums[0];
    for (int i = 1; i < nums.size() && nums[i] == nums[i - 1] + 1; ++i) {
      sum += nums[i];
    }

    unordered_set<int> st(begin(nums), end(nums));
    while (st.find(sum) != st.end()) {
      ++sum;
    }

    return sum;
  }
};
// 4ms
// 19.43MB