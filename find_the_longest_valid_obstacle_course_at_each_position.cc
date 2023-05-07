class Solution {
 public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
    vector<int> ans, mono;

    for (auto a : obstacles) {
      int l = 0, r = mono.size();

      while (l < r) {
        int m = (l + r) / 2;

        if (mono[m] <= a) {
          l = m + 1;
        } else {
          r = m;
        }
      }

      ans.push_back(l + 1);

      if (l == mono.size()) {
        mono.push_back(a);
      }

      mono[l] = a;
    }

    return ans;
  }
};
// Runtime 322 ms
// Memory 123.1 MB