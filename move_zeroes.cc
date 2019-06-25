class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int slow = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] == 0) {
        slow = i;
        break;
      }
    }

    for (int i = slow + 1; i < nums.size(); ++i) {
      if (nums[i] != 0 && nums[slow] == 0) {
        swap(nums[slow], nums[i]);
        ++slow;

        for (int j = slow; j < nums.size(); ++j) {
          if (nums[j] == 0) {
            slow = j;
            break;
          }
        }
      }
    }
  }
};  // 16ms

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int slow = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        swap(nums[slow], nums[i]);
        ++slow;
      }
    }
  }
};  // 20ms