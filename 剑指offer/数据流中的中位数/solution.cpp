bool cmp1(int a,int b){
    return a < b;
}
bool cmp2(int a,int b)
{
    return a > b;
}
class Solution {
public:
    priority_queue<int, vector<int>, greater<int> > minQ;
    priority_queue<int, vector<int>, less<int> > maxQ;
    int size = 0;
    void Insert(int num)
    {
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

    double GetMedian()
    { 
        if(size == 0)
            return 0;
        if(size % 2 == 0)
        {
            return (minQ.top() + maxQ.top())/2.0;
        }
        else
            return minQ.top();
    }
};