class Solution {
 public:
  string originalDigits(string s) {
    vector<int> alpha(26);

    for (auto c : s) {
      ++alpha[c - 'a'];
    }

    vector<string> words = {"zero", "one", "two",   "three", "four",
                            "five", "six", "seven", "eight", "nine"};

    vector<vector<int>> cnt;

    for (auto& w : words) {
      vector<int> tmp(26);

      for (auto c : w) {
        ++tmp[c - 'a'];
      }

      cnt.push_back(tmp);
    }

    string ans;

    while (any_of(alpha.begin(), alpha.end(), [](int i) { return i > 0; })) {
      for (int i = 0; i < cnt.size(); ++i) {
        bool find = true;
        for (int j = 0; j < 26; ++j) {
          if (alpha[j] < cnt[i][j]) {
            find = false;
            break;
          }
        }

        if (find) {
          for (int j = 0; j < 26; ++j) {
            alpha[j] -= cnt[i][j];
          }

          ans += (i + '0');
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  string originalDigits(string s) {
    vector<int> cnt(10);

    unordered_map<char, int> mp;

    for (auto c : s) {
      ++mp[c];
    }

    cnt[0] = mp['z'];
    cnt[2] = mp['w'];
    cnt[4] = mp['u'];
    cnt[6] = mp['x'];
    cnt[8] = mp['g'];
    cnt[1] = mp['o'] - cnt[0] - cnt[2] - cnt[4];
    cnt[3] = mp['t'] - cnt[2] - cnt[8];
    cnt[5] = mp['f'] - cnt[4];
    cnt[7] = mp['s'] - cnt[6];
    cnt[9] = mp['i'] - cnt[5] - cnt[6] - cnt[8];

    string ans;
    for (int i = 0; i < 10; ++i) {
      ans.append(cnt[i], i + '0');
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 50.54%
// Memory Usage: 9.3 MB, less than 16.13%