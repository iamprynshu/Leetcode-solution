//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&prices){
     int n = prices.size();
        vector<int> ahead(5, 0), cur(5, 0);
        for(int ind = n-1; ind>=0; ind--){
            for(int cap = 3; cap>=0; cap--){
                        if(cap%2 == 0){ // buy
                 cur[cap] = max(-prices[ind] + ahead[cap+1], 0+ahead[cap]);
                }
                else{
                 cur[cap] = max(prices[ind]+ahead[cap+1], 0+ahead[cap]);
                }
            }
            ahead = cur;
        }
        return ahead[0];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends