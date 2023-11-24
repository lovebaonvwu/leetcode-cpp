class Solution {
 public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    set<int> st;

    for (int j = 0, n = nums.size(); j < n; ++j) {
      if (nums[j] != key) {
        continue;
      }

      for (int i = max(0, j - k); i <= min(n - 1, j + k); ++i) {
        st.insert(i);
      }
    }

    return vector<int>(st.begin(), st.end());
  }
};
// Runtime: 728 ms, faster than 10.00%
// Memory Usage: 11.9 MB, less than 30.00%
// 2022.3.13 at 茗筑美嘉

class Solution {
 public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    vector<int> ans;

    for (int j = 0, n = nums.size(); j < n; ++j) {
      if (nums[j] != key) {
        continue;
      }

      int start = max(ans.empty() ? 0 : ans.back() + 1, j - k);
      for (int i = start; i <= min(n - 1, j + k); ++i) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 11 ms, faster than 80.00%
// Memory Usage: 10.5 MB, less than 30.00%
// 2022.3.13 at 茗筑美嘉