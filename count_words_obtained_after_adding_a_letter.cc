class Solution {
 public:
  int wordCount(vector<string>& startWords, vector<string>& targetWords) {
    auto mask = [](const string& s) {
      int mask = 0;

      for (auto c : s) {
        mask |= 1 << (c - 'a');
      }

      return mask;
    };

    unordered_set<int> words;
    for (auto& w : startWords) {
      words.insert(mask(w));
    }

    int ans = 0;
    for (auto& target : targetWords) {
      auto targetMask = mask(target);

      for (auto c : target) {
        if (words.find(targetMask ^ (1 << (c - 'a'))) != words.end()) {
          ++ans;
          break;
        }
      }
    }

    return ans;
  }
};
// Runtime: 232 ms, faster than 99.79%
// Memory Usage: 98.7 MB, less than 89.53%
// 2022.1.13 at 奥盛大厦