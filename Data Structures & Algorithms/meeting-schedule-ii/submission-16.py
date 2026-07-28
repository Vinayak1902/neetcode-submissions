"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def minMeetingRooms(self, intervals: List[Interval]) -> int:
        start, end = [],[]
        for interval in intervals:
            start.append(interval.start)
            end.append(interval.end)
        start.sort()
        end.sort()
        res,cnt,s,e,n = 0,0,0,0,len(intervals)
        while s<n:
            if start[s] < end[e]:
                cnt += 1
                s += 1
            else:
                cnt -= 1
                e += 1
            res = max(res,cnt)
        return res
        