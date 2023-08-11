//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        int pSum = 0;
        unordered_map<int, int> mpp;
        mpp[0] =-1;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            pSum += arr[i];
            if(mpp.find(pSum) != mpp.end()){
                ans = max(ans, i-mpp[pSum]);
            }
            else{
                mpp[pSum] = i;
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends