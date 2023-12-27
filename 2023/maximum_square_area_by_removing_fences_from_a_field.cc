class Solution {
 public:
  int maximizeSquareArea(int m,
                         int n,
                         vector<int>& hFences,
                         vector<int>& vFences) {
    hFences.push_back(1);
    hFences.push_back(m);

    unordered_set<int> st;
    for (int i = 0; i < hFences.size(); ++i) {
      for (int j = i + 1; j < hFences.size(); ++j) {
        st.insert(abs(hFences[j] - hFences[i]));
      }
    }

    int ans = -1;
    int mod = 1e9 + 7;
    vFences.push_back(1);
    vFences.push_back(n);

    long long side = 0LL;
    for (int i = 0; i < vFences.size(); ++i) {
      for (int j = i + 1; j < vFences.size(); ++j) {
        if (st.find(abs(vFences[j] - vFences[i])) != st.end()) {
          long long s = abs(vFences[j] - vFences[i]);
          side = max(side, (long long)abs(vFences[j] - vFences[i]));
        }
      }
    }

    return side == 0 ? -1 : (side * side) % mod;
  }
};
// 1154ms
// 262.74MB