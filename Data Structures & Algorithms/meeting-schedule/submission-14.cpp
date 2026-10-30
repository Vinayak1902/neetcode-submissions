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
        int res = 0;
        sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
            return a.end < b.end;
        });
        int prev = intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            if(prev>intervals[i].start){
                return false;
            }
            else{
                prev = intervals[i].end;
            }
        }
        return true;
    }
};
