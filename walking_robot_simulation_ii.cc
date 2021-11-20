class Robot {
  const string dir[4] = {"East", "North", "West", "South"};
  const int d[5] = {0, 1, 0, -1, 0};
  int k;
  int m;
  int n;
  int x;
  int y;

 public:
  Robot(int width, int height) : m(height), n(width), k(0), x(0), y(0) {}

  void step(int num) {
    while (num > 0) {
      int dy = y + d[k];
      int dx = x + d[k + 1];

      if (dx < 0 || dy < 0 || dx == n || dy == m) {
        k = (k + 1) % 4;
        continue;
      }

      x = dx;
      y = dy;

      --num;
    }
  }

  vector<int> getPos() { return {x, y}; }

  string getDir() { return dir[k]; }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
// Time Limit Exceeded
// 2021.11.20 at 茗筑美嘉

class Robot {
  const string dir[4] = {"East", "North", "West", "South"};
  int k;
  int m;
  int n;
  int x;
  int y;

 public:
  Robot(int width, int height) : m(height), n(width), k(0), x(0), y(0) {}

  void step(int num) {
    while (num > 0) {
      if (k == 0) {
        if (num <= n - x - 1) {
          x += num;
          num = 0;
        } else {
          num -= n - x - 1;
          x = n - 1;
          k = (k + 1) % 4;
        }
      } else if (k == 1) {
        if (num <= m - y - 1) {
          y += num;
          num = 0;
        } else {
          num -= m - y - 1;
          y = m - 1;
          k = (k + 1) % 4;
        }
      } else if (k == 2) {
        if (num <= x) {
          x -= num;
          num = 0;
        } else {
          num -= x;
          x = 0;
          k = (k + 1) % 4;
        }
      } else if (k == 3) {
        if (num <= y) {
          y -= num;
          num = 0;
        } else {
          num -= y;
          y = 0;
          k = (k + 1) % 4;
        }
      }
    }
  }

  vector<int> getPos() { return {x, y}; }

  string getDir() { return dir[k]; }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
// Time Limit Exceeded
// 2021.11.20 at 茗筑美嘉

class Robot {
  const string dir[4] = {"East", "North", "West", "South"};
  const int d[5] = {0, 1, 0, -1, 0};
  int k;
  int m;
  int n;
  int x;
  int y;
  int perimeter;

 public:
  Robot(int width, int height)
      : m(height), n(width), k(0), x(0), y(0), perimeter(2 * (m + n - 2)) {}

  void step(int num) {
    if (num >= perimeter) {
      num %= perimeter;

      if (x == 0 && y == 0 && k == 0) {
        k = 3;
      }
    }

    while (num > 0) {
      int dy = y + d[k];
      int dx = x + d[k + 1];

      if (dx < 0 || dy < 0 || dx == n || dy == m) {
        k = (k + 1) % 4;
        continue;
      }

      x = dx;
      y = dy;

      --num;
    }
  }

  vector<int> getPos() { return {x, y}; }

  string getDir() { return dir[k]; }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
// Runtime: 224 ms, faster than 55.21%
// Memory Usage: 120.3 MB, less than 85.42%
// 2021.11.20 at 茗筑美嘉