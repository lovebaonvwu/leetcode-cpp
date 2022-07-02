class Solution {
 public:
  int minSwaps(string s) {
    int cnt0 = count(s.begin(), s.end(), '0');
    int cnt1 = s.size() - cnt0;
    int miss0 = 0, miss1 = 0;

    if (abs(cnt0 - cnt1) > 1) {
      return -1;
    }

    if (cnt0 > cnt1) {
      for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0 && s[i] != '0') {
          ++miss0;
        } else if ((i & 1) && s[i] != '1') {
          ++miss1;
        }
      }
    } else if (cnt1 > cnt0) {
      for (int i = 0; i < s.size(); ++i) {
        if (i % 2 == 0 && s[i] != '1') {
          ++miss1;
        } else if ((i & 1) && s[i] != '0') {
          ++miss0;
        }
      }
    } else {
      for (int i = 0; i < s.size(); i += 2) {
        if (s[i] == '0') {
          ++miss1;
        } else {
          ++miss0;
        }
      }
    }

    return min(miss0, miss1);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.6 MB, less than 34.94%
// 2022.7.2 at 茗筑美嘉

class Solution {
 public:
  int minSwaps(string s) {
    int cnt0 = count(s.begin(), s.end(), '0');
    int cnt1 = s.size() - cnt0;
    int miss0 = 0, miss1 = 0;

    if (abs(cnt0 - cnt1) > 1) {
      return -1;
    }

    for (int i = 0; i < s.size(); i += 2) {
      miss0 += s[i] != '0';
      miss1 += s[i] != '1';
    }

    return cnt0 == cnt1 ? min(miss0, miss1) : cnt0 > cnt1 ? miss0 : miss1;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.4 MB, less than 95.86%
// 2022.7.2 at 茗筑美嘉