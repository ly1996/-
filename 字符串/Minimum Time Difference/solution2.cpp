class Solution {
public:
    int parseMinute(string time){
        /*
        int index = time.find(":");
        string before = time.substr(0,index);
        string after = time.substr(index + 1);
        
        int beforeInt;
        int afterInt;
        
        stringstream streamBefore(before);  
        streamBefore>>beforeInt;  
        
        stringstream streamAfter(after);
        streamAfter >> afterInt;
        
        return beforeInt * 60 + afterInt;
        */
        
        return (time[0] - '0') * 10 * 60 + (time[1] - '0') * 60 + (time[3] - '0') * 10 + (time[4] - '0');
        
        
    }
    
    int findMinDifference(vector<string>& timePoints) {
        vector<bool> times(1440,false);
        for(int i = 0 ; i < timePoints.size() ; i ++)
        {
            int time = parseMinute(timePoints[i]);
            if(times[time])
            {
                return 0;
            }
            else
            {
                times[time] = true;
            }
        }
        
        vector<int> timeArray;
        for(int i = 0 ; i < 1440 ; i ++)
        {
            if(times[i])
            {
                timeArray.push_back(i);
            }
        }
        
        timeArray.push_back(timeArray[0] + 1440);
        
        int min = 1440;
        for(int i = 1 ; i < timeArray.size() ; i ++)
        {
            if(timeArray[i] - timeArray[i - 1] < min)
            {
                min = timeArray[i] - timeArray[i - 1];
            }
        }
        
        return min;
    }
};