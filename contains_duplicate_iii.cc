class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int n = nums.size();

    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j <= i + k && j < n; ++j) {
        if (abs((long)nums[i] - nums[j]) <= t) {
          return true;
        }
      }
    }

    return false;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<long> st;

    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      if (i > k) {
        st.erase(nums[i - k - 1]);
      }

      auto pos = st.lower_bound((long)nums[i] - t);

      if (pos != st.end() && *pos <= (long)nums[i] + t) {
        return true;
      }

      st.insert(nums[i]);
    }

    return false;
  }
};
// Runtime: 36 ms, faster than 54.55%
// Memory Usage: 11.4 MB, less than 34.90%