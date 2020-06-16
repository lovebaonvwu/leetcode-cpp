class Solution {
  bool validIPv4(string ip) {
    if (count(ip.begin(), ip.end(), '.') != 3) {
      return false;
    }

    vector<string> s = split(ip, '.');

    if (s.size() != 4) {
      return false;
    }

    for (auto& t : s) {
      if ((t.size() > 1 && t[0] == '0') || t.size() > 3 || t.empty()) {
        return false;
      }

      int sum = 0;
      for (int i = 0; i < t.size(); ++i) {
        if (!isdigit(t[i])) {
          return false;
        }

        sum = sum * 10 + (t[i] - '0');
      }

      if (sum > 255) {
        return false;
      }
    }

    return true;
  }

  bool validIPv6(string ip) {
    if (count(ip.begin(), ip.end(), ':') != 7) {
      return false;
    }

    vector<string> s = split(ip, ':');

    if (s.size() != 8) {
      return false;
    }

    const string ipv6_c = "0123456789abcdefABCDEF";

    for (auto& t : s) {
      if (t.empty() || t.size() > 4) {
        return false;
      }

      for (auto c : t) {
        if (ipv6_c.find(c) == string::npos) {
          return false;
        }
      }
    }

    return true;
  }

  vector<string> split(string s, char c) {
    vector<string> res;

    istringstream in(s);
    string t;

    while (getline(in, t, c)) {
      res.push_back(t);
    }

    return res;
  }

 public:
  string validIPAddress(string IP) {
    return validIPv4(IP) ? "IPv4" : validIPv6(IP) ? "IPv6" : "Neither";
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.6 MB, less than 25.36%