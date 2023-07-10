class Solution {
 public:
  vector<int> relocateMarbles(vector<int>& nums,
                              vector<int>& moveFrom,
                              vector<int>& moveTo) {
    set<int> st;
    for (auto n : nums) {
      st.insert(n);
    }

    for (int i = 0; i < moveFrom.size(); ++i) {
      int from = moveFrom[i], to = moveTo[i];
      st.erase(from);
      st.insert(to);
    }

    vector<int> ans;
    for (auto n : st) {
      ans.push_back(n);
    }

    return ans;
  }
};
// Runtime 428 ms
// Memory 186.6 MB