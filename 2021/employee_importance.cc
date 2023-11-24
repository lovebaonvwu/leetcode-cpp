/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {
    int sum = 0;

    stack<int> stk;
    unordered_map<int, Employee*> mp;

    for (auto& e : employees) {
      mp[e->id] = e;
    }

    stk.push(id);

    while (!stk.empty()) {
      int e_id = stk.top();
      stk.pop();

      auto employee = mp.at(e_id);

      sum += employee->importance;

      for (auto& sub : employee->subordinates) {
        stk.push(sub);
      }
    }

    return sum;
  }
};  // 32ms

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
 public:
  int getImportance(vector<Employee*> employees, int id) {
    int sum = 0;

    stack<int> stk;
    unordered_map<int, int> mp;

    for (int i = 0; i < employees.size(); ++i) {
      mp[employees[i]->id] = i;
    }

    stk.push(id);

    while (!stk.empty()) {
      int e_id = stk.top();
      stk.pop();

      int index = mp[e_id];

      sum += employees[index]->importance;

      for (auto& sub : employees[index]->subordinates) {
        stk.push(sub);
      }
    }

    return sum;
  }
};  // 36ms