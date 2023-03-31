//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        //  int n = prices.size();

        long long aheadbuy, aheadnotbuy, curnotbuy, curbuy;
        aheadbuy = 0; aheadnotbuy = 0;

        for(int ind = n-1; ind>=0; ind--){
                curnotbuy = max(prices[ind]-fee + aheadbuy, 0+ aheadnotbuy);
                curbuy = max(-prices[ind]+aheadnotbuy, 0 + aheadbuy);
                aheadnotbuy = curnotbuy;
                aheadbuy = curbuy;
        }

        return aheadbuy;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends