class Solution {
  bool isPrice(const string& s) {
    if (s.size() < 2 || s[0] != '$') {
      return false;
    }

    for (int i = 1; i < s.size(); ++i) {
      if (!isdigit(s[i])) {
        return false;
      }
    }

    return true;
  }

  void updatePrice(string& s, int discount) {
    int d = (100.0 - discount);
    long long price = std::stol(s.substr(1));

    stringstream ss;
    ss << fixed << setprecision(2) << (price * 0.01 * d);

    s = '$' + ss.str();
  }

 public:
  string discountPrices(string sentence, int discount) {
    vector<string> words;
    stringstream ss(sentence);
    string s;

    while (ss >> s) {
      words.push_back(s);
    }

    for (auto& w : words) {
      if (isPrice(w)) {
        updatePrice(w, discount);
      }
    }

    string ans;
    for (auto& w : words) {
      ans += w;
      ans += ' ';
    }

    return ans.substr(0, ans.size() - 1);
  }
};
// Runtime: 327 ms, faster than 16.11%
// Memory Usage: 45.6 MB, less than 16.08%
// 2022.6.2 at 奥盛大厦