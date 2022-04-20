class Solution {
 public:
  string digitSum(string s, int k) {
    string t = s;

    while (t.size() > k) {
      s.clear();

      for (int i = 0; i < t.size(); i += k) {
        string u = t.substr(i, k);

        int sum = 0;
        for (auto c : u) {
          sum += (c - '0');
        }

        s += to_string(sum);
      }

      swap(t, s);
    }

    return t;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 32.07%
// 2022.4.20 at 奥盛大厦