//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int n = nums.size();
        int xr = 0;
        
        for(int i = 0; i<n; i++){
            xr ^= nums[i];
        }
        
        xr = xr&~(xr-1);
        
        int num1 = 0;
        int num2 = 0;
        
        for(int i=0; i<n; i++){
            if(xr & nums[i]){
                num1^=nums[i];
            }
            else {
                num2 ^= nums[i];
            }
        }
        vector<int> ans;
        ans.push_back(num1);
        ans.push_back(num2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends