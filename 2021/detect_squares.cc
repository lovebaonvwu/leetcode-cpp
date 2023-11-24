class DetectSquares {
  unordered_map<int, unordered_set<int>> mp;

  map<pair<int, int>, int> points;

 public:
  DetectSquares() {}

  void add(vector<int> point) {
    mp[point[0]].insert(point[1]);

    ++points[{point[0], point[1]}];
  }

  int count(vector<int> point) {
    int x = point[0], y = point[1];

    int res = 0;

    if (mp.find(x) == mp.end() || (mp[x].size() == 1 && *mp[x].begin() == y)) {
      return res;
    }

    for (auto dy : mp[x]) {
      if (dy == y) {
        continue;
      }

      if (dy > y) {
        res += cnt1(x, y, dy);
        res += cnt2(x, y, dy);
      } else {
        res += cnt3(x, y, dy);
        res += cnt4(x, y, dy);
      }
    }

    return res;
  }

  int cnt1(int x, int y, int dy) {
    int res = 0;

    auto a = pair<int, int>({x, dy});
    auto b = pair<int, int>({x - (y - dy), dy});
    auto c = pair<int, int>({x - (y - dy), y});

    if (points.find(a) == points.end() || points.find(b) == points.end() ||
        points.find(c) == points.end()) {
      res += 0;
    }

    res += points[a] * points[b] * points[c];

    return res;
  }

  int cnt2(int x, int y, int dy) {
    int res = 0;

    auto a = pair<int, int>({x, dy});
    auto b = pair<int, int>({x + (y - dy), dy});
    auto c = pair<int, int>({x + (y - dy), y});

    if (points.find(a) == points.end() || points.find(b) == points.end() ||
        points.find(c) == points.end()) {
      res += 0;
    }

    res += points[a] * points[b] * points[c];

    return res;
  }

  int cnt3(int x, int y, int dy) {
    int res = 0;

    auto a = pair<int, int>({x, dy});
    auto b = pair<int, int>({x - (dy - y), dy});
    auto c = pair<int, int>({x - (dy - y), y});

    if (points.find(a) == points.end() || points.find(b) == points.end() ||
        points.find(c) == points.end()) {
      res += 0;
    }

    res += points[a] * points[b] * points[c];

    return res;
  }

  int cnt4(int x, int y, int dy) {
    int res = 0;

    auto a = pair<int, int>({x, dy});
    auto b = pair<int, int>({x + (dy - y), dy});
    auto c = pair<int, int>({x + (dy - y), y});

    if (points.find(a) == points.end() || points.find(b) == points.end() ||
        points.find(c) == points.end()) {
      res += 0;
    }

    res += points[a] * points[b] * points[c];

    return res;
  }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// Runtime: 570 ms, faster than 54.87%
// Memory Usage: 94.3 MB, less than 70.67%
// 2021.10.22 at 奥盛大厦

class DetectSquares {
  int g[1001][1001] = {0};

 public:
  DetectSquares() {}

  void add(vector<int> point) { ++g[point[0]][point[1]]; }

  int count(vector<int> point) {
    int cnt = 0, x0 = point[0], y0 = point[1];

    for (int x = 0; x < 1001; ++x) {
      if (x != x0 && g[x][y0] > 0) {
        int side = abs(x - x0);

        if (y0 + side <= 1000) {
          cnt += g[x][y0 + side] * g[x][y0] * g[x0][y0 + side];
        }

        if (y0 - side >= 0) {
          cnt += g[x][y0 - side] * g[x][y0] * g[x0][y0 - side];
        }
      }
    }

    return cnt;
  }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
// Runtime: 560 ms, faster than 55.74%
// Memory Usage: 143.6 MB, less than 44.95%
// 2021.10.22 at 奥盛大厦