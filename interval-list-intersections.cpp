class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;

        int f_index = 0;
        int s_index = 0;

        while (f_index < firstList.size() && s_index < secondList.size()) {
            // using variables for better readability
            int f_start = firstList[f_index][0];
            int f_end   = firstList[f_index][1];
            int s_start = secondList[s_index][0];
            int s_end   = secondList[s_index][1];

            //1. if overlaps are detected, get the intersection and add them
            if (f_start >= s_start && f_start <= s_end ||
                s_start >= f_start && s_start <= f_end) 
            {
                int a = max(f_start, s_start);
                int b = min(f_end, s_end);
                res.push_back({a, b});
            } 

            //2. Otherwise, move to the next index for which interval finishes first
            if (s_end < f_end) {
                s_index++;
            } else {
                f_index++;
            }
        }

        return res;
    }
};