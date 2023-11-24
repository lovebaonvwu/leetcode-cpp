class Solution {
 public:
  vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    set<string> st_food;
    set<int> st_table;
    unordered_map<string, unordered_map<string, int>> mp;

    for (auto& order : orders) {
      st_food.insert(order[2]);
      st_table.insert(stoi(order[1]));
      ++mp[order[1]][order[2]];
    }

    vector<vector<string>> ans(st_table.size() + 1,
                               vector<string>(st_food.size() + 1, "0"));

    ans[0][0] = "Table";

    int i = 1;
    for (auto& food : st_food) {
      ans[0][i++] = food;
    }

    i = 1;
    for (auto& table : st_table) {
      ans[i++][0] = to_string(table);
    }

    for (int i = 1; i < ans.size(); ++i) {
      for (int j = 1; j < ans[i].size(); ++j) {
        ans[i][j] = to_string(mp[ans[i][0]][ans[0][j]]);
      }
    }

    return ans;
  }
};
// Runtime: 380 ms, faster than 81.79%
// Memory Usage: 75.4 MB, less than 100.00%