class Solution {
 public:
  int countDistinct(vector<int>& nums, int k, int p) {
    set<vector<int>> st;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int cnt = 0;
      vector<int> v;
      for (int j = i; j < n; ++j) {
        v.push_back(nums[j]);
        cnt += nums[j] % p == 0;
        if (cnt > k)
          break;
        st.insert(v);
      }
    }

    return st.size();
  }
};
// 880 ms
// 234.57 MB