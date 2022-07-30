//will still get TLE
//best approach is Tabulation

class Solution {
public:
    int func(int idx, int amount, vector<int>&coins, vector<vector<int>>&dp){
        
        //base case
        if(idx==0){
            return (amount%coins[idx]==0);
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        
        //rec case
        int not_take = func(idx-1, amount, coins, dp);
        int take = 0;
        if(coins[idx]<=amount){
            take = func(idx, amount-coins[idx], coins, dp);
        }
        
        return take + not_take;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return func(n-1, amount, coins, dp);
    }
};
