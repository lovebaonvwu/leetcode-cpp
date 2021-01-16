class Solution {
 public:
  int countStudents(vector<int>& students, vector<int>& sandwiches) {
    vector<int> student(2);

    queue<int> q;

    for (auto s : students) {
      ++student[s];
      q.push(s);
    }

    int i = 0;
    for (; i < sandwiches.size(); ++i) {
      if (sandwiches[i] != q.front() && student[sandwiches[i]] == 0) {
        break;
      }

      while (q.front() != sandwiches[i]) {
        q.push(q.front());
        q.pop();
      }

      --student[sandwiches[i]];
      q.pop();
    }

    return q.size();
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.8 MB, less than 98.84%

class Solution {
 public:
  int countStudents(vector<int>& students, vector<int>& sandwiches) {
    vector<int> student(2);

    for (auto s : students) {
      ++student[s];
    }

    int i = 0;
    for (; i < sandwiches.size(); ++i) {
      --student[sandwiches[i]];

      if (student[sandwiches[i]] < 0) {
        break;
      }
    }

    return sandwiches.size() - i;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.7 MB, less than 98.84%