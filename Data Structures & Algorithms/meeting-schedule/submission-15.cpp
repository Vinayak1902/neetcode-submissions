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
            return a.end < b.end;
        });
        int i = 0, j = 1, n = intervals.size();
        int res = 0;
        while(j<n){
            if(intervals[i].end > intervals[j].start){
                return false;
            }
            else{
                i=j;
            }
            j++;
        }
        return true;
    }
};
