class Solution {
 public:
  int subarrayBitwiseORs(vector<int>& arr) {
    unordered_set<int> values;

    for (int i = 0; i < arr.size(); ++i) {
      for (int j = i; j < arr.size(); ++j) {
        int val = 0;
        for (int k = i; k <= j; ++k) {
          val |= arr[k];
        }

        values.insert(val);
      }
    }

    return values.size();
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int subarrayBitwiseORs(vector<int>& arr) {
    unordered_set<int> values, cur, tmp;

    for (auto n : arr) {
      cur = {n};
      for (auto t : tmp) {
        cur.insert(n | t);
      }

      for (auto t : tmp = cur) {
        values.insert(t);
      }
    }

    return values.size();
  }
};
// Runtime: 2950 ms, faster than 5.06%
// Memory Usage: 209.4 MB, less than 53.09%
// 2022.10.11 at 奥盛大厦