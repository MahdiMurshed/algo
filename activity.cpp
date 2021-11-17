#include <bits/stdc++.h>
using namespace std;

struct Activity
{
	int start, finish;
};

// A utility function that is used for sorting
// activities according to finish time
bool activityCompare(Activity s1, Activity s2)
{
	return (s1.finish < s2.finish);
}

// Returns count of the maximum set of activities that can
// be done by a single person, one at a time.
void printMaxActivities(Activity arr[], int n)
{
	// Sort jobs according to finish time
	sort(arr, arr+n, activityCompare);

	cout << "Following activities are selected n";

	// The first activity always gets selected
	int i = 0;
	cout << "(" << arr[i].start << ", " << arr[i].finish << "), ";

	// Consider rest of the activities
	for (int j = 1; j < n; j++)
	{
	// If this activity has start time greater than or
	// equal to the finish time of previously selected
	// activity, then select it
	if (arr[j].start >= arr[i].finish)
	{
		cout << "(" << arr[j].start << ", "
			<< arr[j].finish << "), ";
		i = j;
	}
	}
}

// Driver program
int main()
{
    int n;
    cout<<"number of works"<<endl;
    cin>>n;
    Activity a[n];
    cout<<"enter input"<<endl;
    for(int i=0;i<n;i++){
        cin >>a[i].start>>a[i].finish;
    }
	printMaxActivities(a, n);
	return 0;
}
