class Solution {
 public:
  int numSpecialEquivGroups(vector<string>& words) {
    set<pair<string, string>> st;
    for (auto& w : words) {
      string odd, even;
      for (int i = 0; i < w.size(); ++i) {
        if (i & 1) {
          odd += w[i];
        } else {
          even += w[i];
        }
      }

      sort(odd.begin(), odd.end());
      sort(even.begin(), even.end());

      st.insert({odd, even});
    }

    return st.size();
  }
};
// 13ms
// 8.70mb