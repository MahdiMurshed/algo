#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        
        vector<int> ans(amount+1,amount+1);
        ans[0]=0;
        for(int i=1;i<=amount;i++){
            for(int c:coins){
                if(c<=i){
                    ans[i]=min(1+ans[i-c],ans[i]);
                    
                    
                }
            }
        }
        return ans[amount]==amount+1?-1:ans[amount];
        
        
    }
};