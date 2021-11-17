#include <bits/stdc++.h>
using namespace std;
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

struct comparitor_{
    bool operator()(Job min,Job max){
        return max.profit>min.profit;
    }
};

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        priority_queue<Job,vector<Job>,comparitor_> pq;
        vector<int> ans(2,0);
        vector<int> slot(n,0),result(n);
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
        }
        for(int i=0;i<n;i++){
            auto top=pq.top();pq.pop();
            for(int j=min(n,top.dead)-1;j>=0;j--){
                
                if(slot[j]==0){
                    result[j]=top.id;
                    slot[j]=1;
                    ans[0]++;
                    ans[1]+=top.profit;
                    break;
                }
                
            }
        }
        return ans;
        
    } 
};