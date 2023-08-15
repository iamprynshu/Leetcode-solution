//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        vector<int> arr(n, 0);
        bool flag = true;
        for(int i=0; i<n; i++){
            if(a[i] == 0) {
                arr[i] = 1;
                flag = false;
            }
            else arr[i] = -1;
        }
        if(flag) return n;
        // for(int i = 0; i<n; i++){
        //     cout<<arr[i]<<endl;
        // }
        // cout<<endl;
        
        
        int currentsum = 0;
        int maxsum = 0;
        int left = 0;
        int right = 0;
        int start = 0;
        
        for(int i=0; i<n; i++){
            currentsum += arr[i];
            
            if(currentsum > maxsum){
                maxsum = currentsum;
                left = start;
                right = i;
            }
            
            if(currentsum <= 0){
                currentsum = 0;
                start = i+1;
                // cout<<start<<endl;
            }
            
        }
      
     
        for(int i=left; i<=right; i++){
            if(a[i] == 0) a[i] =1;
            else a[i] = 0;
        }
        
        
        
        int ans = 0;
        for(int i=0; i<n ;i++){
            if(a[i] == 1) ans++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends