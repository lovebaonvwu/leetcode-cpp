class Solution {
 public:
  int maximum69Number(int num) {
    vector<int> v;

    while (num > 0) {
      v.push_back(num % 10);

      num /= 10;
    }

    int n = v.size() - 1;
    for (int i = n; i >= 0; --i) {
      if (v[i] == 6) {
        v[i] = 9;
        break;
      }
    }

    int ans = 0;
    for (int i = n; i >= 0; --i) {
      ans = ans * 10 + v[i];
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.2 MB, less than 100.00%

class Solution {
 public:
  int maximum69Number(int num) {
    string s = to_string(num);

    for (auto& ch : s) {
      if (ch == '6') {
        ch = '9';
        break;
      }
    }

    return stoi(s);
  }
};
// Runtime: 4 ms, faster than 33.33%
// Memory Usage: 8.5 MB, less than 100.00%