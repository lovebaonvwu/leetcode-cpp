class Solution {
 public:
  vector<int> occurrencesOfElement(vector<int>& nums,
                                   vector<int>& queries,
                                   int x) {
    vector<int> occurrence;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (nums[i] == x) {
        occurrence.push_back(i);
      }
    }

    vector<int> ans;
    for (auto q : queries) {
      if (q > occurrence.size()) {
        ans.push_back(-1);
      } else {
        ans.push_back(occurrence[q - 1]);
      }
    }

    return ans;
  }
};
// 173 ms
// 183.78 MB