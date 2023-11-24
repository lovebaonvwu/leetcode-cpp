class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nums;

    for (int i = 0, j = 0; i < nums1.size() || j < nums2.size();) {
      if (i == nums1.size()) {
        nums.push_back(nums2[j++]);
      } else if (j == nums2.size()) {
        nums.push_back(nums1[i++]);
      } else {
        if (nums1[i] < nums2[j]) {
          nums.push_back(nums1[i++]);
        } else {
          nums.push_back(nums2[j++]);
        }
      }
    }

    int mid = nums.size() >> 1;

    return nums.size() & 1
               ? nums[mid]
               : (static_cast<double>(nums[mid] + nums[mid - 1]) / 2);
  }
};
// Runtime: 20 ms, faster than 68.90%
// Memory Usage: 9.6 MB, less than 84.54%

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nums;

    for (int i = 0, j = 0; i < nums1.size() || j < nums2.size();) {
      if (i == nums1.size()) {
        nums.push_back(nums2[j++]);
      } else if (j == nums2.size()) {
        nums.push_back(nums1[i++]);
      } else {
        if (nums1[i] < nums2[j]) {
          nums.push_back(nums1[i++]);
        } else {
          nums.push_back(nums2[j++]);
        }
      }
    }

    int mid = nums.size() >> 1;

    return nums.size() & 1 ? nums[mid] : (nums[mid] + nums[mid - 1]) / 2.0;
  }
};
// Runtime: 24 ms, faster than 38.48%
// Memory Usage: 8.2 MB, less than 100.00%