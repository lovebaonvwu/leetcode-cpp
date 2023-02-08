class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i += 2) {
      if (i + 1 < nums.size()) {
        swap(nums[i], nums[i + 1]);
      }
    }
  }
};
// Runtime 17 ms
// Memory 13.6 MB
// 2023.2.8 at 聊城市东昌路怡莱酒店

class Solution {
 public:
  void wiggleSort(vector<int>& nums) {
    for (int i = 0; i < nums.size() - 1; ++i) {
      if ((i % 2 == 0 && nums[i] > nums[i + 1]) ||
          ((i % 2 == 1 && nums[i] < nums[i + 1]))) {
        swap(nums[i], nums[i + 1]);
      }
    }
  }
};
// Runtime 15 ms
// Memory 13.6 MB
// 2023.2.8 at 聊城市东昌路怡莱酒店
