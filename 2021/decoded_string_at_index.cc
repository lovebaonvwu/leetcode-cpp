class Solution {
 public:
  string decodeAtIndex(string S, int K) {
    long cnt = 0, i;

    for (i = 0; cnt < K; ++i) {
      if (isdigit(S[i])) {
        cnt *= S[i] - '0';
      } else {
        ++cnt;
      }
    }

    while (i--) {
      if (isdigit(S[i])) {
        cnt /= S[i] - '0';
        K %= cnt;
      } else if (isalpha(S[i]) && K % cnt == 0) {
        return string(1, S[i]);
      } else {
        --cnt;
      }
    }

    return "";
  }
};

class Solution {
 public:
  string decodeAtIndex(string S, int K) {
    string full = "";
    string s = "";

    for (auto& c : S) {
      if (isalpha(c)) {
        s += c;
      } else if (isdigit(c)) {
        int times = c - '0';
        full += s;
        s = "";

        if (full.size() * times > K - 1) {
          int index = (K - 1) % full.size();
          return string(1, full[index]);
        }

        string tmp = full;
        full = "";
        while (times-- > 0) {
          full += tmp;
        }
      }
    }

    full += s;
    if (full.size() > K - 1) {
      return string(1, full[K - 1]);
    }

    return "";
  }
};  // Memory Limit Exceeded