class Solution {
  int diff(const string& a, const string& b) {
    if (a == b) {
      return 0;
    }

    int ha = 0, hb = 0;
    for (int i = 0; i < 2; ++i) {
      ha = ha * 10 + (a[i] - '0');
      hb = hb * 10 + (b[i] - '0');
    }

    int ma = 0, mb = 0;

    for (int i = 3; i < 5; ++i) {
      ma = ma * 10 + (a[i] - '0');
      mb = mb * 10 + (b[i] - '0');
    }

    int diff = abs(ha * 60 + ma - (hb * 60 + mb));

    return min(24 * 60 - diff, diff);
  }

 public:
  int findMinDifference(vector<string>& timePoints) {
    int ans = INT_MAX;

    for (int i = 0; i < timePoints.size(); ++i) {
      for (int j = 0; j < timePoints.size(); ++j) {
        if (i != j) {
          ans = min(ans, diff(timePoints[i], timePoints[j]));
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
  int diff(const string& a, const string& b) {
    if (a == b) {
      return 0;
    }

    int ha = 0, hb = 0;
    for (int i = 0; i < 2; ++i) {
      ha = ha * 10 + (a[i] - '0');
      hb = hb * 10 + (b[i] - '0');
    }

    int ma = 0, mb = 0;

    for (int i = 3; i < 5; ++i) {
      ma = ma * 10 + (a[i] - '0');
      mb = mb * 10 + (b[i] - '0');
    }

    int diff = abs(ha * 60 + ma - (hb * 60 + mb));

    return min(24 * 60 - diff, diff);
  }

 public:
  int findMinDifference(vector<string>& timePoints) {
    int ans = INT_MAX;

    sort(timePoints.begin(), timePoints.end());

    for (int i = 1; i < timePoints.size(); ++i) {
      ans = min(ans, diff(timePoints[i], timePoints[i - 1]));
    }

    ans = min(ans, diff(timePoints[0], timePoints.back()));

    return ans;
  }
};
// Runtime: 16 ms, faster than 73.52%
// Memory Usage: 13.4 MB, less than 81.78%

class Solution {
 public:
  int findMinDifference(vector<string>& timePoints) {
    int ans = INT_MAX;

    vector<int> time;

    for (auto& timePoint : timePoints) {
      int t = timePoint[0] * 10;
      t += timePoint[1];

      t *= 60;

      t += timePoint[3] * 10;
      t += timePoint[4];

      time.push_back(t);
    }

    sort(time.begin(), time.end());

    time.push_back(time[0] + 60 * 24);

    for (int i = 1; i < time.size(); ++i) {
      ans = min(ans, time[i] - time[i - 1]);
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 91.10%
// Memory Usage: 13.6 MB, less than 77.12%