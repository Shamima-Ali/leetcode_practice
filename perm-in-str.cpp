class Solution {
public:
    bool is_equal(vector<int> mp1, vector<int> mp2) {
        for (int i = 0; i < 26; i++) {
            if (mp1[i] != mp2[i]) {
                return false;
            }
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        // get the sizes of the strings
        int size1 = s1.size();
        int size2 = s2.size();

        // create vectors that we will use as hashmaps
        vector<int> mp1(26,0);
        vector<int> mp2(26,0);

        // create hashmap with s1
        for (int i = 0; i < size1; i++) {
            mp1[s1[i] - 'a']++;
        }

        // go over s2
        for (int i = 0; i < size2; i++) {
            // when i is within the sliding window
            if (i < size1) {
                // incraese sliding window to the left
                mp2[s2[i] - 'a']++;
            } else {
                // check if mp1 == mp2
                if (is_equal(mp1, mp2)) {
                    return true;
                }

    // If not, reduce sliding window from right and increase from left
                mp2[s2[i - size1] - 'a']--;
                mp2[s2[i] - 'a']++;
            }
        }
        
        // after going through s2, check equality again
         if (is_equal(mp1, mp2)) {
            return true;
        }

        return false;
    }

};