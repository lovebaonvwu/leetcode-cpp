class Solution {
 public:
  int fourSumCount(vector<int>& A,
                   vector<int>& B,
                   vector<int>& C,
                   vector<int>& D) {
    unordered_map<int, int> mp;

    int ans = 0;

    for (auto a : A) {
      for (auto b : B) {
        mp[a + b]++;
      }
    }

    for (auto c : C) {
      for (auto d : D) {
        auto item = mp.find(-c - d);

        if (item != mp.end()) {
          ans += item->second;
        }
      }
    }

    return ans;
  }
};  // 148ms