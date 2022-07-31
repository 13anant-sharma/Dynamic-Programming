// Hint: Do your best and assume the worst to happen
// Explanation: Whichever coin you choose from the row, the next coin chosen by opponent form the remaining coins will leave u with worst case of remaing i.e
// he will choose a coin such that u will get min amount of coin

#include <bits/stdc++.h>
using namespace std;

int MaxValue(int n, vector<int>v){
   int dp[n][n];
   for(int g=0; g<n; g++){
      for(int i=0, j=g; j<n; i++, j++){
         if(g==0) dp[i][j]=v[i];
         else if(g==1) dp[i][j]=max(v[i], v[j]);
         else{
            int pick_i = v[i] + min(dp[i+2][j], dp[i+1][j-1]);
            int pick_j = v[j] + min(dp[i][j-2], dp[i+1][j-1]);
            dp[i][j] = max(pick_j, pick_i);
         }
      }
   }
   return dp[0][n-1];
}
