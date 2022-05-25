class Solution {
 public:
  vector<int> maxDepthAfterSplit(string seq) {
    vector<int> ans(seq.size());

    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < seq.size(); ++i) {
      if (seq[i] == '(') {
        if (cnt1 >= cnt0) {
          ++cnt0;
        } else {
          ++cnt1;
          ans[i] = 1;
        }
      } else {
        if (cnt1 >= cnt0) {
          --cnt1;
          ans[i] = 1;
        } else {
          --cnt0;
        }
      }
    }

    return ans;
  }
};
// Runtime: 9 ms, faster than 15.74%
// Memory Usage: 7.4 MB, less than 69.36%
// 2022.5.25 at 奥盛大厦