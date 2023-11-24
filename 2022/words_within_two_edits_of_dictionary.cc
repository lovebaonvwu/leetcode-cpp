class Solution {
  bool editable(const string& a, const string& b) {
    int diff = 0;
    for (int i = 0; i < a.size(); ++i) {
      diff += a[i] != b[i];
    }

    return diff <= 2;
  }

 public:
  vector<string> twoEditWords(vector<string>& queries,
                              vector<string>& dictionary) {
    vector<string> ans;
    for (auto q : queries) {
      for (auto d : dictionary) {
        if (editable(q, d)) {
          ans.push_back(q);
          break;
        }
      }
    }

    return ans;
  }
};
// Runtime: 36 ms, faster than 81.82%
// Memory Usage: 15.5 MB, less than 81.82%
// 2022.10.31 at 奥盛大厦