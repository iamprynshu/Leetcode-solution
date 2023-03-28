class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int K) {
        int sum = 0;
        if(numOnes>=K) return K;
        else if(K<=(numOnes + numZeros)) {
            return numOnes;
        }else{
            return numOnes-(K-numOnes-numZeros);
        }
        
    }
};