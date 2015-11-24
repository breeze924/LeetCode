class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>> dp(2,vector<int>(n2+1));
        int now=0;
        int next=1;
        for(int i=0;i<=n2;++i) {
            dp[now][i]=i;
        }
        for(int i=1;i<=n1;++i) {
            dp[next][0]=i;
            for(int j=1;j<=n2;++j) {
                dp[next][j]=min(dp[next][j-1],dp[now][j])+1;
                dp[next][j]=min(dp[next][j],dp[now][j-1]+(word1[i-1]==word2[j-1]?0:1));
            }
            swap(now,next);
        }
        return dp[now][n2];
    }
};

