class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r  = 0;
        unordered_map<char, int> ump;
        int maxSize= 0;
        int maxFreq = 0;

        for (int r = 0; r < s.size(); r++) {
            ump[s[r]]++; //record frquency of s[r]
            maxFreq = max(maxFreq, ump[s[r]]); //get the max freq

            // check if current window (r-l+1) is valid (window size-maxFreq > k)
            // number of replacements to be done = (r - l + 1) - maxFreq
            while ((r - l + 1) - maxFreq > k) { 
                ump[s[l]]-=1;
                l++;
            }

            maxSize = max(maxSize, (r - l + 1)); //get the max window size
        }

        return maxSize;
        
    }
};