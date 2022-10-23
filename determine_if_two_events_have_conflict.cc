class Solution {
 public:
  bool haveConflict(vector<string>& event1, vector<string>& event2) {
    return !(event1[0] > event2[1] || event2[0] > event1[1]);
  }
};
// Runtime: 8 ms, faster than 14.29%
// Memory Usage: 11.1 MB, less than 47.62%
// 2022.10.23 at 茗筑美嘉