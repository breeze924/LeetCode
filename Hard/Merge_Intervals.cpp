/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty()) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), my_cmp);
        vector<Interval> result;
        int p=0;
        result.push_back(intervals[0]);
        for(const auto& interval: intervals) {
            if(result[p].end<interval.start) {
                result.emplace_back(interval);
                ++p;
            }
            else {
                result[p].end=max(result[p].end,interval.end);
            }
        }
        return result;
    }
    
private:
    struct {
        bool operator()(const Interval& lhs, const Interval& rhs) {
            return lhs.start<rhs.start;
        }
    } my_cmp;
};

