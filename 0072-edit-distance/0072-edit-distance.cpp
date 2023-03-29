class Solution {
public:
    
//     int solve(string &w1,string &w2,int n1,int n2 ,vector<vector<int>> &dp){
        
//         if(n1==0)return dp[n1][n2] = n2;
//         if(n2==0)return dp[n1][n2] = n1;
//         if(dp[n1][n2]!=-1)return dp[n1][n2];

//         if(w1[n1-1]==w2[n2-1]){
//             return dp[n1][n2] = solve(w1,w2,n1-1,n2-1,dp);
//         }
//         else{
//             int Insert = solve(w1,w2,n1,n2-1,dp);
//             int Delete = solve(w1,w2,n1-1,n2,dp);
//             int Replace = solve(w1,w2,n1-1,n2-1,dp);

//             return dp[n1][n2] = 1 + min({Insert,Delete,Replace});
//         }
//     }
    int minDistance(string s, string t) {
       int n = s.size(); 
        int m = t.size();
        
        vector<int> prev(m+1, 0), cur(m+1, 0);
        for(int j=0; j<=m; j++) prev[j] = j;
        
        
        for(int i=1; i<=n; i++){
            cur[0] = i;
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]) cur[j] = prev[j-1];
                else cur[j] = 1 + min(cur[j-1], min(prev[j], prev[j-1]));
            }
            prev = cur;
        }
        return prev[m];
    }
};