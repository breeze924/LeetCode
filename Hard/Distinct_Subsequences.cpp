class Solution {
public:
    int numDistinct(string s, string t) {
        if(t.length() == 0) {
            return 1;
        }
        if(s.length() == 0) {
            return 0;
        }
        vector<int> dp(s.length() + 1, 1);
        for(int i = 0; i < t.length(); ++i) {
            vector<int> dp2(s.length() + 1);
            dp2[0] = 0;
            for(int j = 0; j < s.length(); ++j) {
                dp2[j+1] = dp2[j];
                if(t[i] == s[j]) {
                    dp2[j+1] += dp[j];
                }
            }
            dp.swap(dp2);
        }
        return dp[s.length()];
    }
};

