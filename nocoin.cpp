class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> ans(amount+1);
        ans[0]=1;
        for(int c:coins){
             for(int i=1;i<=amount;i++){
                if(c<=i){
                    ans[i]+=ans[i-c];
                }
            }
        }
        return ans[amount];
        
    }
};