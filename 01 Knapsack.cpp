//knap sack recursive approach 
//O(n^2)
//not a  good approach will give TLE

#include<bits/stdc++.h>
using namespace std;

int func(int ind, int W, vector<int>&weight, vector<int>&value){
    if(ind==0){
        if(weight[0]<=W) return value[0];
        return 0;
    }
    
    int not_take = 0 + func(ind-1, W, weight, value);
    int take = INT_MIN;
    if(weight[ind]<=W){
        take = value[ind] + func(ind-1, W-weight[ind], weight, value);
    }
    return max(take, not_take);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    return func(n-1, maxWeight, weight, value);
}
