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