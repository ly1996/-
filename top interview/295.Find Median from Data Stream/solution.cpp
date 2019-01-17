class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(size == 0)
        {
            minQ.push(num);
            size ++;
            return ;
        }
        if(size % 2 == 0)
        {
            if (num >= maxQ.top())
            {
                minQ.push(num);
            }
            else
            {
                minQ.push(maxQ.top());
                maxQ.pop();
                maxQ.push(num);
            }
        }
        else
        {
            if(num <= minQ.top())
            {
                maxQ.push(num);
            }
            else
            {
                maxQ.push(minQ.top());
                minQ.pop();
                minQ.push(num);
            }
        }
        size ++;
    }
    
    double findMedian() {
        if(size == 0)
            return 0;
        if(size % 2 == 0)
        {
            return (minQ.top() + maxQ.top())/2.0;
        }
        else
            return minQ.top();
    }
private:
    priority_queue<int, vector<int>, greater<int> > minQ;
    priority_queue<int, vector<int>, less<int> > maxQ;
    int size = 0;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */