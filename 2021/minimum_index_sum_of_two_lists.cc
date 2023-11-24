class Solution {
 public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> mp;

    vector<string> ans;

    int min = INT_MAX;

    for (int i = 0; i < list1.size(); ++i) {
      mp[list1[i]] = i;
    }

    for (int i = 0; i < list2.size(); ++i) {
      if (mp.find(list2[i]) != mp.end()) {
        if (i + mp[list2[i]] == min) {
          ans.push_back(list2[i]);
        } else if (i + mp[list2[i]] < min) {
          min = i + mp[list2[i]];
          ans.clear();
          ans.push_back(list2[i]);
        }
      }
    }

    return ans;
  }
};  // 104ms