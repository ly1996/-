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
        sort(intervals.begin() , intervals.end() , compare);
        
        vector<Interval>::iterator it;
        
        vector<Interval>::iterator before = intervals.begin();
        for(it = intervals.begin() + 1; it < intervals.end() ; ++ it)
        {
            if(it -> start <= before -> end)
            {
                before -> end = max(it -> end , before -> end);
                it = intervals.erase(it);
                it --;
            }
            before = it;
        }
        
        return intervals;
    }
    
    static bool compare(Interval a , Interval b){
        return a.start < b.start;
    }
};