class Solution {
  vector<int> backet;
  default_random_engine e;

 public:
  Solution(vector<int>& w) {
    for (int i = 0; i < w.size(); ++i) {
      while (w[i]-- > 0) {
        backet.push_back(i);
      }
    }
  }

  int pickIndex() {
    uniform_int_distribution<unsigned> u(0, backet.size() - 1);

    return backet[u(e)];
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// Time Limit Exceeded

class Solution {
  vector<int> backet;

 public:
  Solution(vector<int>& w) {
    for (int i = 0; i < w.size(); ++i) {
      while (w[i]-- > 0) {
        backet.push_back(i);
      }
    }
  }

  int pickIndex() { return backet[rand() % backet.size()]; }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// Time Limit Exceeded

class Solution {
  vector<int> bucket;
  int total = 0;

 public:
  Solution(vector<int>& w) {
    for (int i = 0; i < w.size(); ++i) {
      total += w[i];
      bucket.push_back(total);
    }
  }

  int pickIndex() {
    int r = rand() % total;

    auto it = upper_bound(bucket.begin(), bucket.end(), r);

    return it - bucket.begin();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// Runtime: 188 ms, faster than 50.33%
// Memory Usage: 40.9 MB, less than 8.07%

class Solution {
  vector<int> bucket;

 public:
  Solution(vector<int>& w) {
    for (auto i : w) {
      bucket.push_back(bucket.empty() ? i : i + bucket.back());
    }
  }

  int pickIndex() {
    int b = rand() % bucket.back();

    auto it = upper_bound(bucket.begin(), bucket.end(), b);

    return it - bucket.begin();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// Runtime: 180 ms
// Memory Usage : 40.6 MB
// Your runtime beats 64.49 %