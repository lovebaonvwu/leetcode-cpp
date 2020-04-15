class Solution {
 public:
  string entityParser(string text) {
    unordered_map<string, string> mp = {
        {"&quot;", "\""}, {"&apos;", "'"}, {"&amp;", "&"},
        {"&gt;", ">"},    {"&lt;", "<"},   {"&frasl;", "/"},
    };

    string ans, partial;
    for (char c : text) {
      ans += c;

      if (c == '&') {
        partial = "";
        partial += c;
      } else if (!partial.empty()) {
        partial += c;
      }

      if (mp.find(partial) != mp.end()) {
        ans.replace(ans.size() - partial.size(), partial.size(), mp[partial]);
        partial = "";
      }
    }

    return ans;
  }
};
// Runtime: 372 ms, faster than 61.25%
// Memory Usage: 19 MB, less than 100.00%