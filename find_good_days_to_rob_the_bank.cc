class Solution {
 public:
  vector<int> goodDaysToRobBank(vector<int>& security, int time) {
    deque<int> dec, inc;

    vector<int> ans;

    for (int i = 0; i + time < security.size(); ++i) {
      while (!dec.empty() && security[dec.back()] < security[i]) {
        dec.pop_back();
      }
      dec.push_back(i);

      while (!dec.empty() && dec.front() < i - time) {
        dec.pop_front();
      }

      while (!inc.empty() && security[inc.back()] > security[i + time]) {
        inc.pop_back();
      }
      inc.push_back(i + time);

      while (!inc.empty() && inc.front() < i) {
        inc.pop_front();
      }

      if ((dec.size() == time + 1) && (inc.size() == time + 1)) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 221 ms, faster than 15.81%
// Memory Usage: 87.4 MB, less than 74.63%
// 2021.12.16 at 奥盛大厦