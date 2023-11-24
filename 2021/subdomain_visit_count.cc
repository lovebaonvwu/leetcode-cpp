class Solution {
 public:
  vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> mp;

    for (const string& s : cpdomains) {
      size_t pos = s.find(" ");

      int cnt = stoi(s.substr(0, pos));

      while (pos != string::npos) {
        mp[s.substr(pos + 1)] += cnt;
        pos = s.find(".", pos + 1);
      }
    }

    vector<string> ans;

    for (auto& m : mp) {
      ans.push_back(to_string(m.second).append(" ").append(m.first));
    }

    return ans;
  }
};  // 16ms

class Solution {
 public:
  vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> mp;

    for (const string& s : cpdomains) {
      int visits = 0;

      int i = 0;
      for (; i < s.size(); ++i) {
        if (s[i] == ' ') {
          break;
        }

        visits = visits * 10 + (s[i] - '0');
      }

      string domain;
      for (int j = s.size() - 1; j >= i; --j) {
        if (s[j] == '.' || s[j] == ' ') {
          mp[domain] += visits;
        }

        if (s[j] != ' ') {
          domain = s[j] + domain;
        }
      }
    }

    vector<string> ans;
    for (const pair<string, int>& m : mp) {
      string tmp;
      tmp.append(to_string(m.second)).append(" ").append(m.first);

      ans.push_back(tmp);
    }

    return ans;
  }
};  // 20ms