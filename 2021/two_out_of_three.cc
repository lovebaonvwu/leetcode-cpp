class Solution {
 public:
  vector<int> twoOutOfThree(vector<int>& nums1,
                            vector<int>& nums2,
                            vector<int>& nums3) {
    unordered_set<int> st1(nums1.begin(), nums1.end());
    unordered_set<int> st2(nums2.begin(), nums2.end());
    unordered_set<int> st3(nums3.begin(), nums3.end());

    vector<int> ans;
    for (int i = 1; i <= 100; ++i) {
      int cnt = 0;

      if (st1.count(i)) {
        ++cnt;
      }

      if (st2.count(i)) {
        ++cnt;
      }

      if (st3.count(i)) {
        ++cnt;
      }

      if (cnt >= 2) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 34 ms, faster than 30.22%
// Memory Usage: 26.8 MB, less than 55.82%
// 2021.10.16 at 茗筑美嘉