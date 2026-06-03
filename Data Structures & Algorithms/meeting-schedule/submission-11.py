"""
Definition of Interval:
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    def canAttendMeetings(self, intervals: List[Interval]) -> bool:
        intervals.sort(key=lambda pair:pair.end)
        lastEnd = -1
        for i in range(0,len(intervals)):
            if lastEnd>intervals[i].start:
                return False
            else:
                lastEnd = intervals[i].end
        return True
