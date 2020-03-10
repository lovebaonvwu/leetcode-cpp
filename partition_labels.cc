class Solution {
 public:
  vector<int> partitionLabels(string S) {
    int mp[26] = {0};

    for (int i = 0; i < S.size(); ++i) {
      mp[S[i] - 'a'] = i;
    }

    vector<int> ans;
    for (int i = 0, j = 0, farest = 0; i < S.size(); ++i) {
      farest = max(farest, mp[S[i] - 'a']);

      if (farest == i) {
        ans.push_back(i - exchange(j, i + 1) + 1);
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 92.65%
// Memory Usage: 7.8 MB, less than 100.00%

class Solution {
 public:
  vector<int> partitionLabels(string S) {
    int total[26] = {0};

    for (char ch : S) {
      ++total[ch - 'a'];
    }

    int cnt[26] = {0};

    vector<int> ans;

    for (int i = 0, j = 0; i < S.size(); ++i) {
      ++cnt[S[i] - 'a'];
      --total[S[i] - 'a'];

      bool complete = true;
      for (int k = 0; k < 26; ++k) {
        if (cnt[k] > 0 && total[k] > 0) {
          complete = false;
          break;
        }
      }

      if (complete) {
        ans.push_back(i - j + 1);
        j = i + 1;
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 92.65%
// Memory Usage: 7.9 MB, less than 100.00%