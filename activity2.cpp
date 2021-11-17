
#include <bits/stdc++.h>
using namespace std;


void printMaxActivities(int s[], int f[], int n, vector<int> &a,int &act)
{
    int i, j,ind=0;
    
  
    cout <<"Following activities are selected "<< endl;
  
    // The first activity always gets selected
    i = 0;
    a[ind]=i;
    act++;
    cout <<" "<< i;
  
    // Consider rest of the activities
    for (j = 1; j < n; j++)
    {
      // If this activity has start time greater than or
      // equal to the finish time of previously selected
      // activity, then select it
      if (s[j] >= f[i])
      {
          ind++;
          a[ind]=j;
          act++;  
          i = j;
      }
    }
    
}
  
// driver program to test above function
int main()
{
    vector<int> ans(7);
    int act=0;  
    int s[] =  {1, 3, 0, 5, 8, 5};
    int f[] =  {2, 4, 6, 7, 9, 9};
    int n = sizeof(s)/sizeof(s[0]);
    printMaxActivities(s, f, n,ans,act);
    cout<<"ans array"<<endl;
    for(int i=0;i<act;i++)
        cout<<ans[i]<<endl;
    return 0;
}