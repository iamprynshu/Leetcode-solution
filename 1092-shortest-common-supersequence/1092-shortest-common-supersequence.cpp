class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.size(); int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        
        int i = n; int j = m;
        string ans = "";
        while(i>0 && j>0){
            if(s[i-1] == t[j-1]){
                ans = s[i-1]+ans;
                i--; j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans = s[i-1] +ans;
                i--;
            }
            else{
                ans = t[j-1]+ans;
                j--;
            }
        }
        
        while(i>0) {
            ans = s[i-1]+ans;
            i--;
        }
        while(j>0){
            ans = t[j-1] + ans;
            j--;
        }
        return ans;
    }
};