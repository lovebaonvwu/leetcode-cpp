class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    if (all_of(nums.begin(), nums.end(), [](int& n) { return n == 0; })) {
      return "0";
    }

    vector<string> s;
    for_each(nums.begin(), nums.end(),
             [&s](int& n) { s.push_back(to_string(n)); });

    sort(s.begin(), s.end(),
         [](string& a, string& b) { return a + b > b + a; });

    return accumulate(s.begin(), s.end(), string(""));
  }
};
// Runtime: 8 ms, faster than 78.51%
// Memory Usage: 10.8 MB, less than 9.09%