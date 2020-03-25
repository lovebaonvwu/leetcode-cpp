class Solution {
 public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    vector<vector<int>> seats(n, vector<int>(10, 0));

    for (auto& reserved : reservedSeats) {
      seats[reserved[0] - 1][reserved[1] - 1] = 1;
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
      if (all_of(seats[i].begin() + 1, seats[i].begin() + 9,
                 [](int n) { return n == 0; })) {
        ans += 2;
      } else if (all_of(seats[i].begin() + 1, seats[i].begin() + 5,
                        [](int n) { return n == 0; })) {
        ++ans;
      } else if (all_of(seats[i].begin() + 3, seats[i].begin() + 7,
                        [](int n) { return n == 0; })) {
        ++ans;
      } else if (all_of(seats[i].begin() + 5, seats[i].begin() + 9,
                        [](int n) { return n == 0; })) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime Error
// out of memory

class Solution {
 public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, char> seats;

    for (auto& r : reservedSeats) {
      if (r[1] > 1 && r[1] < 10) {
        seats[r[0]] |= 1 << (r[1] - 2);
      }
    }

    int ans = 2 * n;

    for (auto seat : seats) {
      bool left = !(seat.second & 0b11110000);
      bool mid = !(seat.second & 0b00111100);
      bool right = !(seat.second & 0b00001111);

      if (left && right) {
        continue;
      } else if (left || mid || right) {
        --ans;
      } else {
        ans -= 2;
      }
    }

    return ans;
  }
};
// Runtime: 192 ms, faster than 99.56%
// Memory Usage: 38.8 MB, less than 100.00%

class Solution {
 public:
  int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, int> seats;

    for (auto& r : reservedSeats) {
      seats[r[0]] |= 1 << r[1] - 1;
    }

    int ans = 2 * n;

    for (auto& [r, mask] : seats) {
      if (mask & 0x1fe) {
        --ans;
      }

      if (mask & 0x78 && mask & 0x1e && mask & 0x1e0) {
        --ans;
      }
    }

    return ans;
  }
};
// Runtime: 204 ms, faster than 96.35%
// Memory Usage: 39.9 MB, less than 100.00%