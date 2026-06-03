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
        int cnt=1;
        sort(intervals.begin(),intervals.end(),[](auto &a, auto &b){
            return a.start<b.start;
        });
        int lastEnd = intervals[0].end;
        for(int i=1;i<n;i++){
            if(lastEnd<=intervals[i].start){
                cnt++;
                lastEnd = intervals[i].end;
            }
        }
        if(cnt==n) return true;
        else return false;
    }
};
