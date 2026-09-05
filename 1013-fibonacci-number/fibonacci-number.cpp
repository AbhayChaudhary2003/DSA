class Solution {
public:
    unordered_map<int,int>DP;
    int fib(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(DP.find(n)!=DP.end())
            return DP[n];

        int ans = fib(n-1)+fib(n-2);
        DP[n]=ans;
        return ans;

        
    }
};