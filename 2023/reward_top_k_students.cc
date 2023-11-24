class Solution {
 public:
  vector<int> topStudents(vector<string>& positive_feedback,
                          vector<string>& negative_feedback,
                          vector<string>& report,
                          vector<int>& student_id,
                          int k) {
    vector<pair<int, int>> points;

    unordered_set<string> pos(positive_feedback.begin(),
                              positive_feedback.end());
    unordered_set<string> neg(negative_feedback.begin(),
                              negative_feedback.end());

    for (int i = 0; i < student_id.size(); ++i) {
      int sum = 0;
      stringstream ss(report[i]);
      string w;

      while (ss >> w) {
        if (pos.find(w) != pos.end()) {
          sum += 3;
        } else if (neg.find(w) != neg.end()) {
          sum -= 1;
        }
      }

      points.push_back({sum, student_id[i]});
    }

    sort(points.begin(), points.end(), [](auto& a, auto& b) {
      if (a.first == b.first) {
        return a.second < b.second;
      }

      return a.first > b.first;
    });

    vector<int> ans;
    for (int i = 0; i < k; ++i) {
      ans.push_back(points[i].second);
    }

    return ans;
  }
};
// Runtime 262 ms
// Memory 55.6 MB