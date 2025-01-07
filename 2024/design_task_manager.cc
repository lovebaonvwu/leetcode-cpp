class TaskManager {
    unordered_map<int, pair<int, int>> mp;
    priority_queue<pair<int, int>> pq;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& task : tasks) {
            int userId = task[0];
            int taskId = task[1];
            int priority = task[2];

            add(userId, taskId, priority);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        pq.push({priority, taskId});
    }
    
    void edit(int taskId, int newPriority) {
        mp[taskId].second = newPriority;
        pq.push({newPriority, taskId});
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);
    }
    
    int execTop() {
        int userId = -1;
        while (!pq.empty()) {
            auto [priority, taskId] = pq.top();
            pq.pop();

            if (mp.find(taskId) != mp.end() && priority == mp[taskId].second) {
                userId = mp[taskId].first;
                mp.erase(taskId);
                break;
            }
        }

        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
 // 168 ms
 // 347.46 MB