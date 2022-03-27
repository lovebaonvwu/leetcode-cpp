class Solution {
 public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> n1(nums1.begin(), nums1.end());
    unordered_set<int> n2(nums2.begin(), nums2.end());

    unordered_set<int> a1;
    for (auto n : nums1) {
      if (n2.find(n) == n2.end()) {
        a1.insert(n);
      }
    }

    unordered_set<int> a2;
    for (auto n : nums2) {
      if (n1.find(n) == n1.end()) {
        a2.insert(n);
      }
    }

    return {vector<int>(a1.begin(), a1.end()),
            vector<int>(a2.begin(), a2.end())};
  }
};
// Runtime: 90 ms, faster than 44.44%
// Memory Usage: 34.4 MB, less than 11.11%
// 2022.3.27 at 茗筑美嘉

class Solution {
 public:
  vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> n1(nums1.begin(), nums1.end());
    unordered_set<int> n2(nums2.begin(), nums2.end());

    vector<int> a1;
    for (auto n : n1) {
      if (n2.find(n) == n2.end()) {
        a1.push_back(n);
      }
    }

    vector<int> a2;
    for (auto n : n2) {
      if (n1.find(n) == n1.end()) {
        a2.push_back(n);
      }
    }

    return {a1, a2};
  }
};
// Runtime: 84 ms, faster than 44.44%
// Memory Usage: 31.8 MB, less than 22.22%
// 2022.3.27 at 茗筑美嘉