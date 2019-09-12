class Solution {
 public:
  int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> st;

    for (string& e : emails) {
      size_t pos = e.find("@");
      string tmp = e.substr(0, pos);
      string domain = e.substr(pos);

      string local;
      for (const char& t : tmp) {
        if (t == '.') {
          continue;
        } else if (t == '+') {
          break;
        } else {
          local += t;
        }
      }

      st.insert(local.append(domain));
    }

    return st.size();
  }
};  // 24ms

class Solution {
 public:
  int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> st;

    for (string& e : emails) {
      int i = 0;
      string mail;

      for (; i < e.size(); ++i) {
        if (e[i] == '.') {
          continue;
        } else if (e[i] == '+' || e[i] == '@') {
          break;
        } else {
          mail += e[i];
        }
      }

      while (e[i] != '@') {
        ++i;
      }

      mail += e.substr(i);

      st.insert(mail);
    }

    return st.size();
  }
};  // 36ms