class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int sum = 0;
        vector<int> low;
        int start;
        int tmpSum;
        for(int i = 0 ; i < len ; i ++)
        {
            low.push_back(gas[i] - cost[i]);
            sum += (gas[i] - cost[i]);
            if(gas[i] - cost[i] >= 0)
            {
                start = i;
                tmpSum = gas[i] - cost[i];
            }
        }
        
        if(sum < 0)
            return -1;
        
        //start inited
        int currentIndex = start;
        while(true)
        {
            currentIndex = (currentIndex + 1) % len;
            if(currentIndex == start)
                return start;
            
            tmpSum += low[currentIndex];
            if(tmpSum < 0)
            {
                start = (start + 1) % len;
                tmpSum -= low[start];
                while(low[start] < 0)
                {
                    start = (start + 1) % len;
                    tmpSum -= low[start];
                }
            }
        }
    }
};