#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> res(n+1,vector<int>(m+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    res[i][j]=1+res[i-1][j-1];
                }else{
                    res[i][j]=max(res[i-1][j],res[i][j-1]);
                }
            }
        }
        return res[n][m];
        
        
    }
};