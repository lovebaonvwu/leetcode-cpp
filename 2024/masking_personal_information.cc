class Solution {
  bool isEmail(const string& s) { return s.find("@") != string::npos; }

  string maskEmail(const string& s) {
    int p = s.find("@");

    string name = s.substr(0, p);
    string domain = s.substr(p);

    string maskName = name[0] + string(5, '*') + name.back();
    string res = maskName + domain;

    for (int i = 0; i < res.size(); ++i) {
      if (res[i] >= 'A' && res[i] <= 'Z') {
        res[i] = tolower(res[i]);
      }
    }

    return res;
  }

  string maskPhoneNumber(string& s) {
    int i = 0, j = 0;
    while (j < s.size()) {
      while (isdigit(s[i])) {
        ++i;
      }

      j = i + 1;
      while (j < s.size() && !isdigit(s[j])) {
        ++j;
      }

      swap(s[i], s[j]);
    }

    s = s.substr(0, i);

    int n = s.size();
    string country = s.substr(0, n - 10);
    string local = s.substr(n - 10);
    string last4 = local.substr(6);

    string res;
    if (country.size()) {
      res += "+";
      res.append((int)country.size(), '*');
      res += "-";
    }

    res += "***-***-";
    res += last4;

    return res;
  }

 public:
  string maskPII(string s) {
    if (isEmail(s)) {
      return maskEmail(s);
    }

    return maskPhoneNumber(s);
  }
};
// 2 ms
// 6.54MB