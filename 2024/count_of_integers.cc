class Solution {
 public:
  int count(string num1, string num2, int min_sum, int max_sum) {
    long long a = stoll(num1);
    long long b = stoll(num2);

    int ans = 0;
    for (int i = a; i <= b; ++i) {
      int sum = 0;
      int n = i;
      while (n > 0) {
        sum += n % 10;
        n /= 10;
      }

      if (sum >= min_sum && sum <= max_sum) {
        ++ans;
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int count(string num1, string num2, int min_sum, int max_sum) {
    int cached[2][23][401];
    int mod = 1e9 + 7;

    function<int(const string&, int, int, bool)> dfs =
        [&](const string& s, int cur, int sum, bool tight) -> int {
      if (sum > max_sum)
        return 0;

      if (cur == s.size()) {
        return sum >= min_sum;
      }

      if (cached[tight][cur][sum] != -1) {
        return cached[tight][cur][sum];
      }

      int ret = 0;
      if (tight) {
        for (int i = 0; i < s[cur] - '0'; ++i) {
          ret = (ret + dfs(s, cur + 1, sum + i, false)) % mod;
        }

        ret = (ret + dfs(s, cur + 1, sum + (s[cur] - '0'), true)) % mod;
      } else {
        for (int i = 0; i <= 9; ++i) {
          ret = (ret + dfs(s, cur + 1, sum + i, false)) % mod;
        }
      }

      return cached[tight][cur][sum] = ret;
    };

    memset(cached, -1, sizeof(cached));
    int upper = dfs(num2, 0, 0, true);
    memset(cached, -1, sizeof(cached));
    int lower = dfs(num1, 0, 0, true);

    int sum = 0;
    for (auto c : num1) {
      sum += c - '0';
    }

    return (upper - lower + mod) % mod + (sum >= min_sum && sum <= max_sum);
  }
};
// 48 ms
// 9.32 MB