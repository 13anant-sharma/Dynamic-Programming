//Not recommended as it will give TLE
//Time Complexity = exponential
//can be done by both DP memoisation and tabulation

class Solution {
public:
    int func(int idx, int amount, vector<int>&coins){
        
        //base case
        if(idx==0){
            return (amount%coins[idx]==0);
        }
        
        //rec case
        int not_take = func(idx-1, amount, coins);
        int take = 0;
        if(coins[idx]<=amount){
            take = func(idx, amount-coins[idx], coins);
        }
        
        return take + not_take;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return func(n-1, amount, coins);
    }
};
