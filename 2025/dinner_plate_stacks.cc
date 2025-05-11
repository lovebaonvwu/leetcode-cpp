class DinnerPlates
{
    int cap;
    map<int, vector<int>> cnt;
    set<int> st;

public:
    DinnerPlates(int capacity) : cap(capacity)
    {
    }

    void push(int val)
    {
        if (!st.empty())
        {
            cnt[*st.begin()].push_back(val);
            if (cnt[*st.begin()].size() == cap)
            {
                st.erase(*st.begin());
            }
        }
        else
        {
            if (cnt.empty())
            {
                cnt[0].push_back(val);
                if (cnt[0].size() < cap)
                {
                    st.insert(0);
                }
            }
            else
            {
                auto it = prev(cnt.end());
                if (it->second.size() == cap)
                {
                    cnt[it->first + 1].push_back(val);
                    if (cnt[it->first + 1].size() < cap)
                    {
                        st.insert(it->first + 1);
                    }
                }
                else
                {
                    cnt[it->first].push_back(val);
                    if (cnt[it->first].size() == cap)
                    {
                        st.erase(it->first);
                    }
                }
            }
        }
    }

    int pop()
    {
        if (cnt.empty())
        {
            return -1;
        }

        auto it = prev(cnt.end());
        int index = it->first;

        return popAtStack(index);
    }

    int popAtStack(int index)
    {
        if (cnt.find(index) == cnt.end())
        {
            return -1;
        }

        int ret = cnt[index].back();
        cnt[index].pop_back();
        st.insert(index);

        if (cnt[index].size() == 0)
        {
            cnt.erase(index);
        }

        return ret;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
// Time: O(n log n)
// Space: O(n)