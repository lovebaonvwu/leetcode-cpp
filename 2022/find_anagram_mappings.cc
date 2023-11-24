class Solution {
 public:
  vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (nums1[i] == nums2[j]) {
          ans[i] = j;
        }
      }
    }

    return ans;
  }
};
// Runtime 0 ms
// Memory 8.7 MB
// 2022.11.26 at 茗筑美嘉