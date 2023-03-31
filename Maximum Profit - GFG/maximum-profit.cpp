//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int prices[]) {
        //  int n = prices.size();
        vector<int> ahead(2*k+1, 0), cur(2*k+1, 0);
        for(int ind = n-1; ind>=0; ind--){
            for(int cap = 2*k-1; cap>=0; cap--){
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
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends