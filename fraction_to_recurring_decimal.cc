class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0) {
      return "0";
    }

    string ans;
    if (numerator > 0 ^ denominator > 0) {
      ans += '-';
    }

    long long n = labs(numerator), d = labs(denominator), r = n % d;
    ans += to_string(n / d);
    if (r == 0) {
      return ans;
    }

    ans += '.';
    unordered_map<long long, int> mp;
    while (r) {
      if (mp.find(r) != mp.end()) {
        ans.insert(mp[r], "(");
        ans += ')';
        break;
      }

      mp[r] = ans.size();
      r *= 10;
      ans += to_string(r / d);
      r %= d;
    }

    return ans;
  }
};
// 3ms
// 6.64MB