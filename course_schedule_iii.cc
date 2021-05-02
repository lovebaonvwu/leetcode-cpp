class Solution {
 public:
  int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(),
         [](auto& a, auto& b) { return a[1] < b[1]; });

    int days = 0;
    priority_queue<int> pq;

    for (auto& c : courses) {
      days += c[0];
      pq.push(c[0]);

      if (days > c[1]) {
        days -= pq.top();
        pq.pop();
      }
    }

    return pq.size();
  }
};
// Runtime: 192 ms, faster than 94.50%
// Memory Usage: 56.2 MB, less than 62.20%