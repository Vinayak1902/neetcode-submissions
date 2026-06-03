class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n==0) return true;
        sort(intervals.begin(),intervals.end(),[](Interval& a,Interval& b){
            return a.end<=b.end;
        });
        int cnt=1;
        int lastEnd = intervals[0].end;
        for(int i=1;i<n;i++){
            if(lastEnd<=intervals[i].start){
                cnt++;
                lastEnd = intervals[i].end;
            }
        }
        if(n==cnt) return true;
        return false;
    }
};
