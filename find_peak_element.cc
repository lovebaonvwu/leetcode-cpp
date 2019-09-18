class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    if (nums.size() <= 1) {
      return 0;
    }

    if (nums[0] > nums[1]) {
      return 0;
    }

    if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
      return nums.size() - 1;
    }

    for (int i = 1; i < nums.size() - 1; ++i) {
      if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
        return i;
      }
    }

    return -1;
  }
};  // 4ms

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int i{0}, j{nums.size()};

    while (i < j) {
      int mid = i + (j - i) / 2;

      if (mid == i) {
        break;
      }

      if (nums[mid] > nums[mid - 1]) {
        i = mid;
      } else {
        j = mid;
      }
    }

    return i;
  }
};  // 8ms

class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int lo{0}, hi{nums.size() - 1};

    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;

      if (nums[mid] < nums[mid + 1]) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }

    return lo;
  }
};  // 8ms