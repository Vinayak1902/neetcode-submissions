/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n==0) return true;
        sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
            return a.end<b.end;
        });
        int prev_end = intervals[0].end;
        
        for(int i=1;i<n;i++){
            if(prev_end>intervals[i].start) return false;
            else prev_end = intervals[i].end;
        }
        return true;
    }
};
