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
        sort(intervals.begin(),intervals.end(),[](const auto &a, const auto &b){
            return a.end<b.end;
        });
        int n = intervals.size();
        if(n==0) return true;
        int prevEnd = intervals[0].end;
        for(int i=1;i<n;i++){
            if(prevEnd>intervals[i].start){
                return false;
            }
            else{
                prevEnd = intervals[i].end;
            }
        }
        return true;
    }
};
