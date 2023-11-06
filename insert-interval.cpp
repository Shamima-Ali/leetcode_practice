class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        for (int i = 0; i < intervals.size(); i++) {
            //1. if newInterval > intervals[x], push intervals[x]
            if (newInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
            } 
            //2. if newInterval < intervals[x], push newInterval and the rest of interval
            else if (newInterval[1] < intervals[i][0]){
                res.push_back(newInterval);
                for (int j = i; j < intervals.size(); j++) {
                    res.push_back(intervals[j]);
                }
                return res;
            } 
            //3. if overlap, update newInterval
            else {
                int a = min(intervals[i][0], newInterval[0]);
                int b = max(intervals[i][1], newInterval[1]);
                newInterval[0] = a;
                newInterval[1] = b;
            }
        }

        //4. push newInterval to res
        res.push_back(newInterval);
        return res;
    }
};