class Solution {
public:
    int parseMinute(string time){
        int index = time.find(":");
        string before = time.substr(0,index);
        string after = time.substr(index + 1);
        
        int beforeInt;
        int afterInt;
        
        stringstream streamBefore(before);  
        streamBefore>>beforeInt;  
        
        stringstream streamAfter(after);
        streamAfter >> afterInt;
        
        // cout << before << " : " << after <<  endl;
        
        return beforeInt * 60 + afterInt;
    }
    
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for(int i = 0 ; i < timePoints.size() ; i ++)
        {
            times.push_back(parseMinute(timePoints[i]));
        }
        
        sort(times.begin(),times.end());
        
        // for(int i = 0 ; i < times.size() ; i ++)
        // {
        //     cout << times[i] << " ";
        // }
        
        int min = 1440;
        for(int i = 1 ;i < times.size() ; i ++)
        {
            int tmp = times[i] - times[i - 1];
            if(tmp < min)
            {
                min = tmp;
            }
        }
        if(times[0] + 1440 - times[times.size() - 1] < min)
        {
            min = times[0] + 1440 - times[times.size() - 1];
        }
        
        return min;
    }
};