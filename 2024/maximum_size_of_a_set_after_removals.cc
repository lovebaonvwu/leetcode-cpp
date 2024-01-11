class Solution {
 public:
  int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
    set<int> s1(begin(nums1), end(nums1));
    set<int> s2(begin(nums2), end(nums2));

    int n = nums1.size();
    int redundant = s1.size() - n / 2;
    int ans = min((int)s1.size(), n / 2);

    int selected = 0;
    for (auto num : s2) {
      if (s1.find(num) == s1.end()) {
        ++selected;
      } else if (redundant > 0) {
        --redundant;
        ++selected;
      }

      if (selected >= n / 2) {
        break;
      }
    }

    return ans + selected;
  }
};
// 241ms
// 132.55MB