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

class Solution {
 public:
  bool validUtf8(vector<int>& data) {
    int count = 0;

    for (auto c : data) {
      if (count == 0) {
        if ((c >> 5) == 0b110) {
          count = 1;
        } else if ((c >> 4) == 0b1110) {
          count = 2;
        } else if ((c >> 3) == 0b11110) {
          count = 3;
        } else if ((c >> 7) == 0b1) {
          return false;
        }
      } else {
        if ((c >> 6) != 0b10) {
          return false;
        }

        --count;
      }
    }

    return count == 0;
  }
};
// Runtime: 22 ms, faster than 33.55%
// Memory Usage: 14.1 MB, less than 30.65%
// 2022.3.17 at 奥盛大厦