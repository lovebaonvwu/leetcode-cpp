class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int slow = 0;
    int fast = 0;

    do {
      slow = nums[slow];
      fast = nums[nums[fast]];
    } while (slow != fast);

    slow = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};  // 8ms

class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[nums[0]];

    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    slow = 0;
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[fast];
    }

    return slow;
  }
};  // 20ms