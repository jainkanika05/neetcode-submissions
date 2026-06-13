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
        if(intervals.size()<2)return intervals.size();
        sort(intervals.begin(),intervals.end(),[](const Interval &a, const Interval &b) {
    return a.start < b.start;});
        vector<vector<Interval>> v(100);
        int i=0;
        int j=0;
        while(i<intervals.size()){
            if(intervals[i].start==intervals[i].end)i++;
            if(v[j].empty()){
                v[j].push_back(intervals[i]);
                i++;
                j=0;
            }
            else if(!v[j].empty() and intervals[i].start>= v[j][v[j].size()-1].end){
                v[j].push_back(intervals[i]);
                i++;
                j=0;
            }
            else if(!v[j].empty() and intervals[i].start< v[j][v[j].size()-1].end){
                j++;
            }
        }
        i=0;
        int day=0;
        while(i<v.size()){
            if(!v[i].empty())day++;
            i++;
        }
        return day;
    }
};
