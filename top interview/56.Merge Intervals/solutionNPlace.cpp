/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> vec;
        if(intervals.size() == 0)
        {
            return vec;
        }
        
        sort(intervals.begin() , intervals.end() , compare);
        Interval interval((intervals[0]).start , (intervals[0]).end);
        for(int i = 0 ; i < intervals.size() ; i++)
        {
            Interval tmp = intervals[i];
            if(tmp.start <= interval.end)
            {
                if(interval.end < tmp.end)
                {
                    interval.end = tmp.end;
                }
            }
            else
            {
                vec.push_back(interval);
                interval = tmp;
            }
        }
        vec.push_back(interval);
        return vec;
    }
    static bool compare(Interval a , Interval b){
        return a.start < b.start;
    }
};
