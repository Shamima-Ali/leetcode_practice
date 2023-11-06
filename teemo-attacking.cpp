class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int end = -1;
        int timer = 0;

        for (int start : timeSeries) {
            //1. start timer for poison attack
            timer += duration;

            //2a. if end time overlaps with start time of poison attack
            if (end >= start) {
                //2b. restart timer
                timer = timer - (abs(end-start)) - 1;
            }

            //3. calculate end time for this poison attack
            end = (start + duration) - 1; 
        }

        return timer;
    }
};