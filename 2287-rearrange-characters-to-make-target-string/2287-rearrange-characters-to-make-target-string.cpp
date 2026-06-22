class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int freqS[26] = {0};
        int freqT[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            freqS[s[i] - 'a']++;
        }

        for (int i = 0; i < target.length(); i++) {
            freqT[target[i] - 'a']++;
        }

        int ans = 100;

        for (int i = 0; i < 26; i++) {
            if (freqT[i] > 0) {
                ans = min(ans, freqS[i] / freqT[i]);
            }
        }

        return ans;
    }
};