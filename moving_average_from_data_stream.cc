class MovingAverage 
{
    deque<int> dq;
    int size;
    int sum;
public:
    MovingAverage(int size) 
    {
        this->size = size;
        this->sum = 0;
    }
    
    double next(int val) 
    {
        sum += val;
        dq.push_back(val);

        if (dq.size() > size)
        {
            int removing = dq.front();
            dq.pop_front();

            sum -= removing;
        }

        return sum / (double)dq.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
 // Runtime 47 ms
 // Memory 14.1 MB
 // 2022.12.12 at 奥盛大厦