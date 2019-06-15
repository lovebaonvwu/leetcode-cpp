class Solution {
 public:
  int compareVersion(string version1, string version2) {
    queue<int> q1;
    queue<int> q2;

    version(q1, version1);
    version(q2, version2);

    while (!q1.empty() || !q2.empty()) {
      int v1, v2;

      if (q1.empty()) {
        v1 = 0;
      } else {
        v1 = q1.front();
        q1.pop();
      }

      if (q2.empty()) {
        v2 = 0;
      } else {
        v2 = q2.front();
        q2.pop();
      }

      if (v1 > v2) {
        return 1;
      } else if (v1 < v2) {
        return -1;
      }
    }

    return 0;
  }

  void version(queue<int>& q, string s) {
    string tmp;

    for (auto& c : s) {
      if (c == '.') {
        q.push(stoi(tmp));
        tmp = "";
      } else {
        tmp += c;
      }
    }

    if (tmp != "") {
      q.push(stoi(tmp));
    }
  }
};