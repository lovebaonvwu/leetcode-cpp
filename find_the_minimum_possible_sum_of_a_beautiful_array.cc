class Solution {
 public:
  long long minimumPossibleSum(int n, int target) {
    unordered_set<int> st;
    st.insert(1);
    long long ans = 1;
    int i = 2;

    while (st.size() < n) {
      while (st.find(target - i) != st.end()) {
        ++i;
      }

      st.insert(i);
      ans += i;
      ++i;
    }

    return ans;
  }
};
// 105ms
// 43.63MB