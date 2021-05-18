class Solution {
 public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> mp;

    for (auto& path : paths) {
      stringstream ss(path);

      string dir, tmp;

      ss >> dir;

      while (ss >> tmp) {
        string content, filename;

        int i = 0;

        while (tmp[i] != '(') {
          filename += tmp[i++];
        }

        ++i;
        while (tmp[i] != ')') {
          content += tmp[i++];
        }

        mp[content].push_back(dir + '/' + filename);
      }
    }

    vector<vector<string>> ans;

    for (auto [content, file] : mp) {
      if (file.size() > 1) {
        ans.push_back(file);
      }
    }

    return ans;
  }
};
// Runtime: 104 ms, faster than 45.82%
// Memory Usage: 40.5 MB, less than 59.75%