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

class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> paths;

    stringstream ss(path);
    string p;

    while (getline(ss, p, '/')) {
      if (!p.empty()) {
        if (p == ".") {
          continue;
        }

        if (p == ".." && !paths.empty()) {
          paths.pop_back();
        }

        if (p != "..") {
          paths.push_back(p);
        }
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
// Runtime: 8 ms, faster than 60.74%
// Memory Usage: 7.5 MB, less than 95.61%

class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> paths;

    path += "/";

    string p;
    for (int i = 0; i < path.size(); ++i) {
      if (path[i] == '/') {
        if (!p.empty()) {
          if (p == ".." && !paths.empty()) {
            paths.pop_back();
          } else if (p != ".." && p != ".") {
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
// Runtime: 8 ms, faster than 60.74%
// Memory Usage: 7.6 MB, less than 91.76%

class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> paths;

    path += "/";

    string p;
    for (int i = 0; i < path.size(); ++i) {
      if (path[i] == '/' && !p.empty()) {
        if (p == ".." && !paths.empty()) {
          paths.pop_back();
        } else if (p != ".." && p != ".") {
          paths.push_back(p);
        }

        p.clear();
      } else if (path[i] != '/') {
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
// Runtime: 8 ms, faster than 60.74%
// Memory Usage: 7.6 MB, less than 91.76%