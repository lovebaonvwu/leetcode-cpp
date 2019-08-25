class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    if (nums.size() < 3) {
      return 0;
    }

    int ans = 0;

    sort(nums.begin(), nums.end());

    for (int i = nums.size() - 1; i >= 2; --i) {
      int j = 0;
      int k = i - 1;

      while (j < k) {
        if (nums[j] + nums[k] > nums[i]) {
          ans += k - j;
          --k;
        } else {
          ++j;
        }
      }
    }

    return ans;
  }
};  // 16ms

class Solution {
 public:
  int triangleNumber(vector<int>& nums) {
    if (nums.size() < 3) {
      return 0;
    }

    int ans = 0;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i) {
      for (int j = i + 1; j < nums.size() - 1; ++j) {
        for (int k = j + 1; k < nums.size(); ++k) {
          if (nums[i] + nums[j] > nums[k]) {
            ++ans;
          }
        }
      }
    }

    return ans;
  }
};  // 1192ms