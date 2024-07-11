class FileSystem {
  unordered_map<string, int> mp;

 public:
  FileSystem() {}

  bool createPath(string path, int value) {
    if (mp.find(path) != mp.end())
      return false;

    string cur = "/";
    for (int i = 1; i < path.size(); ++i) {
      if (path[i] == '/') {
        if (mp.find(cur) == mp.end()) {
          return false;
        }
      }

      cur += path[i];
    }

    mp[cur] = value;

    return true;
  }

  int get(string path) {
    if (mp.find(path) == mp.end())
      return -1;
    return mp[path];
  }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
// 149 ms
// 65.22 MB
