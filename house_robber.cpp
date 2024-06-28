// CPP program to find the maximum stolen value 
#include <bits/stdc++.h> 
using namespace std; 

// calculate the maximum stolen value 
int maxLoot(int *hval, int n, vector<int> &dp){ 
	
// base case 
if(n < 0){ 
		return 0 ; 
} 
	
if(n == 0){ 
		return hval[0] ; 
} 
// If the subproblem is already solved 
// then return its value 
if(dp[n] != -1 ){ 
		return dp[n] ; 
} 
	
//if current element is pick then previous cannot be picked 
int pick = hval[n] + maxLoot(hval, n-2, dp) ; 
//if current element is not picked then previous element is picked 
int notPick = maxLoot(hval, n-1, dp) ; 
	
// return max of picked and not picked 
return dp[n] = max(pick, notPick) ; 
	
} 

// Driver to test above code 
int main() 
{ 
  int n;
  cin>>n;
	int hval[n];
  for(int i=0;i<n;i++){
    cin>>hval[i];}
  
	// Initialize a dp vector 
	vector<int> dp(n+1, -1) ; 
	cout<< maxLoot(hval, n-1, dp); 
	return 0; 
} 
