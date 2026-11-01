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
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> arvlTime;
        vector<int> deptTime;
        for(Interval i:intervals){
            arvlTime.push_back(i.start);
            deptTime.push_back(i.end);
        }
        sort(arvlTime.begin(),arvlTime.end());
        sort(deptTime.begin(),deptTime.end());
        int i=0,j=0,n=intervals.size();
        int numPlt = 0;
        int maxPlt = 0;
        while(i<n){
            if(arvlTime[i]<deptTime[j]){
                numPlt++;
                maxPlt = max(maxPlt,numPlt);
                i++;
            }
            else{
                numPlt--;
                j++;
            }
        }
        return maxPlt;

    }
};
