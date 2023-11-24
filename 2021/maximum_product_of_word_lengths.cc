class Solution {
 public:
  int maxProduct(vector<string>& words) {
    unordered_map<int, bitset<26>> mp;

    for (int i = 0; i < words.size(); ++i) {
      for (auto c : words[i]) {
        mp[i][c - 'a'] = 1;
      }
    }

    int ans = 0;

    for (int i = 0; i < words.size(); ++i) {
      for (int j = i + 1; j < words.size(); ++j) {
        bool share = false;
        for (int k = 0; k < 26; ++k) {
          if (mp[i][k] & mp[j][k]) {
            share = true;
            break;
          }
        }

        if (!share) {
          ans = max(ans, (int)(words[i].size() * words[j].size()));
        }
      }
    }

    return ans;
  }
};
// Runtime: 460 ms, faster than 11.81%
// Memory Usage: 17.8 MB, less than 26.97%

class Solution {
 public:
  int maxProduct(vector<string>& words) {
    vector<int> mask(words.size());

    sort(words.begin(), words.end(),
         [](auto& a, auto& b) { return a.size() < b.size(); });

    int ans = 0;
    for (int i = 0; i < words.size(); ++i) {
      for (auto c : words[i]) {
        mask[i] |= 1 << (c - 'a');
      }

      for (int j = i - 1; j >= 0; --j) {
        if (!(mask[i] & mask[j])) {
          ans = max(ans, (int)(words[i].size() * words[j].size()));
        }
      }
    }

    return ans;
  }
};
// Runtime: 48 ms, faster than 50.84%
// Memory Usage: 15.6 MB, less than 89.14%