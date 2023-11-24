class Solution {
 public:
  int countWords(vector<string>& words1, vector<string>& words2) {
    unordered_map<string, int> w1;
    unordered_map<string, int> w2;

    for (auto& w : words1) {
      ++w1[w];
    }

    for (auto& w : words2) {
      ++w2[w];
    }

    int ans = 0;

    for (auto& w : w1) {
      if (w.second == 1 && w2[w.first] == 1) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 32 ms
// Memory Usage : 18.9 MB
// 2021.12.3 at 茗筑美嘉

class Solution {
 public:
  int countWords(vector<string>& words1, vector<string>& words2) {
    unordered_map<string, int> mp;

    for (auto& w : words1) {
      ++mp[w];
    }

    for (auto& w : words2) {
      if (mp.find(w) != mp.end() && mp[w] <= 1) {
        --mp[w];
      }
    }

    return count_if(mp.begin(), mp.end(),
                    [](auto& m) { return m.second == 0; });
  }
};
// Runtime: 16 ms, faster than 99.88%
// Memory Usage: 15.9 MB, less than 95.87%
// 2021.12.3 at 茗筑美嘉