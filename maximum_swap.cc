class Solution {
 public:
  int maximumSwap(int num) {
    string s = to_string(num);

    for (int i = 0; i < s.size() - 1; ++i) {
      char max = s[i];
      int pos = i;

      for (int j = i; j < s.size(); ++j) {
        if (s[j] >= max) {
          max = s[j];
          pos = j;
        }
      }

      if (max != s[i]) {
        swap(s[i], s[pos]);
        break;
      }
    }

    return stoi(s);
  }
};  // 0ms

class Solution {
 public:
  int maximumSwap(int num) {
    deque<int> nums;
    priority_queue<int> pq;

    while (num > 0) {
      int remainder = num % 10;

      nums.push_front(remainder);
      pq.push(remainder);

      num /= 10;
    }

    bool fin = false;
    for (int i = 0; i < nums.size() && !fin; ++i) {
      if (nums[i] == pq.top()) {
        pq.pop();
      } else {
        for (int j = nums.size() - 1; j > i; --j) {
          if (nums[j] == pq.top()) {
            swap(nums[i], nums[j]);
            fin = true;
            break;
          }
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      ans = ans * 10 + nums[i];
    }

    return ans;
  }
};  // 4ms