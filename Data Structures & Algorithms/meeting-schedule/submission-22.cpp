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
        if(intervals.empty())return true;
        sort(intervals.begin(),intervals.end(),[](const Interval &a, const Interval &b) {
    return a.start < b.start;});
        int s=intervals[0].start;
        int e=intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start<e)return false;
            s=intervals[i].start;
            e=intervals[i].end;
            // cout<<intervals[i].start<<" "<<intervals[i].end<<endl;
        }
        return true;
    }
};
