class Solution {
 public:
  int maxPalindromesAfterOperations(vector<string>& words) {
    unordered_map<char, int> cnt;
    vector<int> size;
    for (auto& w : words) {
      for (auto c : w) {
        ++cnt[c];
      }
      size.push_back(w.size());
    }

    int pairs = 0;
    for (auto& [_, v] : cnt) {
      pairs += v / 2;
    }

    sort(begin(size), end(size));
    int ans = 0;
    for (auto c : size) {
      pairs -= c / 2;
      ans += pairs >= 0;
    }

    return ans;
  }
};
// 58 ms
// 28.56 MB