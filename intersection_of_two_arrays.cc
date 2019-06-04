class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s1(nums1.begin(), nums1.end());
    unordered_set<int> s2(nums2.begin(), nums2.end());

    vector<int> ans;

    if (s1.size() < s2.size()) {
      for (int& n : nums1) {
        if (s2.count(n)) {
          ans.push_back(n);
          s2.erase(n);
        }
      }
    } else {
      for (int& n : nums2) {
        if (s1.count(n)) {
          ans.push_back(n);
          s1.erase(n);
        }
      }
    }

    return ans;
  }
};  // 8ms