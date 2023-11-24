class Solution {
 public:
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    unordered_map<int, int> mp;
    for (auto b : barcodes) {
      ++mp[b];
    }

    vector<pair<int, int>> vct;
    for (auto& [num, cnt] : mp) {
      vct.push_back({cnt, num});
    }

    sort(vct.rbegin(), vct.rend());
    int cur = 0;
    int n = barcodes.size();
    for (auto [cnt, num] : vct) {
      for (; cnt > 0; cur += 2, --cnt) {
        if (cur >= n) {
          cur = 1;
        }

        barcodes[cur] = num;
      }
    }

    return barcodes;
  }
};
// Runtime: 175 ms, faster than 44.82%
// Memory Usage: 42.1 MB, less than 59.71%
// 2022.9.12 at 茗筑美嘉