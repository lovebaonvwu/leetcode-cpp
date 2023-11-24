class Solution {
  static const char* const OneToTwenty[];
  static const char* const TwentyToHundred[];

 public:
  string numberToWords(int num) {
    if (num == 0) {
      return "Zero";
    }

    return dfs(num).substr(1);
  }

  string dfs(int num) {
    if (num >= 1000000000) {
      return dfs(num / 1000000000) + " Billion" +
             dfs(num - 1000000000 * (num / 1000000000));
    } else if (num >= 1000000) {
      return dfs(num / 1000000) + " Million" +
             dfs(num - 1000000 * (num / 1000000));
    } else if (num >= 1000) {
      return dfs(num / 1000) + " Thousand" + dfs(num - 1000 * (num / 1000));
    } else if (num >= 100) {
      return dfs(num / 100) + " Hundred" + dfs(num - 100 * (num / 100));
    } else if (num >= 20) {
      return string(" ") + TwentyToHundred[num / 10 - 2] +
             dfs(num - 10 * (num / 10));
    } else if (num >= 1) {
      return string(" ") + OneToTwenty[num / 1 - 1];
    }

    return "";
  }
};

const char* const Solution::OneToTwenty[] = {
    "One",     "Two",       "Three",    "Four",     "Five",
    "Six",     "Seven",     "Eight",    "Nine",     "Ten",
    "Eleven",  "Twelve",    "Thirteen", "Fourteen", "Fifteen",
    "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
const char* const Solution::TwentyToHundred[] = {"Twenty", "Thirty", "Forty",
                                                 "Fifty",  "Sixty",  "Seventy",
                                                 "Eighty", "Ninety"};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.3 MB, less than 62.35%
// 2022.10.21 at 奥盛大厦