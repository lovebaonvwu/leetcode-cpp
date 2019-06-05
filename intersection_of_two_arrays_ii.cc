class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mp;
    vector<int> ans;

    if (nums1.size() < nums2.size()) {
      for (int& n : nums2) {
        if (!mp[n]) {
          mp[n] = 1;
        } else {
          mp[n]++;
        }
      }

      find(mp, nums1, ans);
    } else {
      for (int& n : nums1) {
        if (!mp[n]) {
          mp[n] = 1;
        } else {
          mp[n]++;
        }
      }

      find(mp, nums2, ans);
    }

    return ans;
  }

  void find(unordered_map<int, int>& mp, vector<int>& nums, vector<int>& ans) {
    for (int& n : nums) {
      if (mp[n]) {
        ans.push_back(n);
        mp[n]--;
      }
    }
  }
};