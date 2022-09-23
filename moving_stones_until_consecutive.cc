class Solution {
 public:
  vector<int> numMovesStones(int a, int b, int c) {
    vector<int> abc{a, b, c};
    sort(abc.begin(), abc.end());

    int minstep = ((abc[1] - abc[0]) > 1) + ((abc[2] - abc[1]) > 1);
    if ((abc[1] - abc[0] == 2) || abc[2] - abc[1] == 2) {
      minstep = min(minstep, 1);
    }
    int maxstep = (abc[1] - abc[0] - 1) + (abc[2] - abc[1] - 1);

    return {minstep, maxstep};
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 60.70%
// 2022.9.23 at 奥盛大厦