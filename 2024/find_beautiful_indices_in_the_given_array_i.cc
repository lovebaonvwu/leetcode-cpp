class Solution {
 public:
  vector<int> beautifulIndices(string s, string a, string b, int k) {
    vector<int> indexA;
    int offset = 0;

    auto p = s.find(a, offset);
    while (p != string::npos) {
      indexA.push_back(p);
      offset = p + 1;
      p = s.find(a, offset);
    }

    vector<int> indexB;
    offset = 0;
    p = s.find(b, offset);
    while (p != string::npos) {
      indexB.push_back(p);
      offset = p + 1;
      p = s.find(b, offset);
    }

    vector<int> ans;
    for (auto i : indexA) {
      auto it = lower_bound(begin(indexB), end(indexB), i - k);
      if (it != end(indexB) && abs(*it - i) <= k) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// 18 ms
// 14.04 MB