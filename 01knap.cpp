#include <bits/stdc++.h> 
using namespace std;
  
// A utility function that returns maximum of two integers 
int max(int a, int b) { return (a > b) ? a : b; } 
struct Item{
int val,wt;
};
  
// Prints the items which are put in a knapsack of capacity W 
void printknapSack(int W, Item it[], int n) 
{ 
    int i, w; 
    int K[n + 1][W + 1]; 
  
    // Build table K[][] in bottom up manner 
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (it[i - 1].wt <= w) 
                K[i][w] = max(it[i - 1].val +  
                    K[i - 1][w -it[i - 1].wt], K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
  
    // stores the result of Knapsack 
    int res = K[n][W];     
    printf("%d\n", res); 
      
    w = W; 
    for (i = n; i > 0 && res > 0; i--) { 
          
        // either the result comes from the top 
        // (K[i-1][w]) or from (val[i-1] + K[i-1] 
        // [w-wt[i-1]]) as in Knapsack table. If 
        // it comes from the latter one/ it means  
        // the item is included. 
        if (res == K[i - 1][w])  
            continue;         
        else { 
  
            // This item is included. 
            printf("%d ", it[i - 1].wt); 
              
            // Since this weight is included its  
            // value is deducted 
            res = res - it[i - 1].val; 
            w = w - it[i - 1].wt; 
        } 
    } 
} 
  

int main() 
{ 
    int n;
    cout<<"number of works"<<endl;
    cin>>n;
    Item it[n];
    cout<<"enter input"<<endl;
    for(int i = 0;i<n;i++){
        cin>>it[i].val>>it[i].wt;
    }
    // int val[] = { 60, 100, 120 }; 
    // int wt[] = { 10, 20, 30 }; 
    int W = 50;  
    printknapSack(W, it, n); 
      
    return 0; 
}