class Solution {
 public:
  bool isPathCrossing(string path) {
    int n = 0;
    int e = 0;

    for (int i = 0; i < path.size(); ++i) {
      for (int j = i, n = 0, e = 0; j < path.size(); ++j) {
        if (path[j] == 'E') {
          ++e;
        } else if (path[j] == 'W') {
          --e;
        } else if (path[j] == 'N') {
          ++n;
        } else {
          --n;
        }

        if (n == 0 && e == 0) {
          return true;
        }
      }
    }

    return false;
  }
};
// Runtime: 8 ms, faster than 45.53%
// Memory Usage: 6.9 MB, less than 100.00%

class Solution {
 public:
  bool isPathCrossing(string path) {
    for (int i = 0; i < path.size(); ++i) {
      for (int j = i, n = 0, e = 0; j < path.size(); ++j) {
        if (path[j] == 'E') {
          ++e;
        } else if (path[j] == 'W') {
          --e;
        } else if (path[j] == 'N') {
          ++n;
        } else {
          --n;
        }

        if (n == 0 && e == 0) {
          return true;
        }
      }
    }

    return false;
  }
};
// Runtime: 4 ms, faster than 97.22%
// Memory Usage: 6.7 MB, less than 100.00%

class Solution {
 public:
  bool isPathCrossing(string path) {
    unordered_set<int> st;

    st.insert(0);
    for (int i = 0, n = 0, e = 0; i < path.size(); ++i) {
      if (path[i] == 'E') {
        ++e;
      } else if (path[i] == 'W') {
        --e;
      } else if (path[i] == 'N') {
        ++n;
      } else {
        --n;
      }

      int item = e * 100000 + n;
      if (st.count(item)) {
        return true;
      }

      st.insert(item);
    }

    return false;
  }
};
// Runtime: 4 ms, faster than 97.22%
// Memory Usage: 6.7 MB, less than 100.00%