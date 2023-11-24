class Solution {
 public:
  vector<int> lastVisitedIntegers(vector<string>& words) {
    vector<int> nums;
    vector<int> ans;
    for (int i = 0, cnt = 0; i < words.size(); ++i) {
      if (words[i][0] == 'p') {
        ++cnt;
        if (cnt > nums.size()) {
          ans.push_back(-1);
        } else {
          ans.push_back(nums[nums.size() - cnt]);
        }
      } else {
        nums.push_back(stoi(words[i]));
        cnt = 0;
      }
    }

    return ans;
  }
};
// 11ms
// 23.83MB