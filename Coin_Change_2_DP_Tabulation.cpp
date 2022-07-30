class Solution {
public:
  
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
    
    
        //Initializing base condition
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0)
                dp[0][i]=1;
            // Else condition is automatically fulfilled,
            // as dp array is initialized to zero
        }

        for(int ind=1; ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int notTaken = dp[ind-1][target];

                int taken = 0;
                if(coins[ind]<=target)
                    taken = dp[ind][target-coins[ind]];

                dp[ind][target] = notTaken + taken;
            }
        }

        return dp[n-1][amount];
        }
};
