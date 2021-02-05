class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> paths;

    path += "/";

    string p;
    for (int i = 0; i < path.size(); ++i) {
      if (path[i] == '/') {
        if (!p.empty()) {
          if (p == "..") {
            if (!paths.empty()) {
              paths.pop_back();
            }
          } else if (p != ".") {
            paths.push_back(p);
          }

          p.clear();
        }
      } else {
        p.append(1, path[i]);
      }
    }

    if (paths.empty()) {
      return "/";
    }

    string ans;
    for (int i = 0; i < paths.size(); ++i) {
      ans += "/";
      ans += paths[i];
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 93.11%
// Memory Usage: 7.7 MB, less than 89.46%