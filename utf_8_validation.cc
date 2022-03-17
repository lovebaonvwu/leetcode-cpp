class Solution {
  string helper(int n) {
    string s(8, '0');

    for (int i = 0; i < 8; ++i) {
      s[7 - i] = (((n >> i) & 1) + '0');
    }

    return s;
  }

 public:
  bool validUtf8(vector<int>& data) {
    for (int i = 0; i < data.size(); ++i) {
      string first = helper(data[i]);

      if (first[0] == '0') {
        continue;
      }

      if (first[1] == '0') {
        return false;
      }

      ++i;
      if (i >= data.size()) {
        return false;
      }

      string second = helper(data[i]);

      if (second[0] != '1' || second[1] != '0') {
        return false;
      }

      if (first[2] == '0') {
        continue;
      }

      ++i;
      if (i >= data.size()) {
        return false;
      }

      string third = helper(data[i]);

      if (third[0] != '1' || third[1] != '0') {
        return false;
      }

      if (first[3] == '0') {
        continue;
      }

      ++i;
      if (i >= data.size()) {
        return false;
      }

      string forth = helper(data[i]);

      if (forth[0] != '1' || forth[1] != '0') {
        return false;
      }

      if (first[4] == '1') {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 23 ms, faster than 31.29%
// Memory Usage: 14 MB, less than 30.65%
// 2022.3.17 at 奥盛大厦