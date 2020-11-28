// C++ program to Count the numbers having 
// exactly K non-zero digits and sum 
// of digits are odd and distinct. 
#include <bits/stdc++.h> 
using namespace std; 

// To store digits of N 
vector<int> digits; 

// visited map 
bool vis[170] = { false }; 

// DP Table 
int dp[19][19][2][170]; 

// Push all the digits of N into 
// digits vector 
void ConvertIntoDigit(int n) 
{ 
	while (n) { 
		int dig = n % 10; 
		digits.push_back(dig); 
		n /= 10; 
	} 
	reverse(digits.begin(), digits.end()); 
} 

// Function returns the count 
int solve(int idx, int k, int tight, int sum) 
{ 
	// If desired number is formed 	// whose sum is odd 
	if (idx == digits.size() && k == 0 && sum & 1) { 
		// If it is not present in map, 		// mark it as true and return 1 
		if (!vis[sum]) { 
			vis[sum] = 1; 
			return 1; 
		} 
		// Sum is present in map already 
		return 0; 
	} 
	// Desired result not found 
	if (idx > digits.size()) { 
		return 0; 
	} 
	// If that state is already calculated 	// just return that state value 
	if (dp[idx][k][tight][sum]) { 
		return dp[idx][k][tight][sum]; 
	} 
	// Upper limit 
	int j; 
	if (tight == 0) { 
		j = digits[idx]; 
	} 
	else { 
		j = 9; 
	} 
	// To store the count of 	// desired numbers 
	int cnt = 0; 
	// If k is non-zero, i ranges from 	// 0 to j else [1, j] 
	for (int i = (k ? 0 : 1); i <= j; i++) { 
		int newtight = tight; 
		if (i < j) { 
			newtight = 1; 
		} 
		// If current digit is 0, decrement 
		// k and recurse sum is not changed 
		// as we are just adding 0 that 
		// makes no difference 
		if (i == 0) 
			cnt += solve(idx + 1, k - 1, 
						newtight, sum); 

		// If i is non zero, then k remains 
		// unchanged and value is added to sum 
		else
			cnt += solve(idx + 1, k, newtight, 
						sum + i); 
	} 
	// Memoize and return 
	return dp[idx][k][tight][sum] = cnt; 
} 

// Driver code 
int main() 
{ 

	// K is the number of exact non-zero 
	// elements to have in number 
	int N, k; 
	N = 169, k = 2; 
	cin >> N >> k;
	// break N into its digits 
	ConvertIntoDigit(N); 

	// We keep record of 0s we need to 
	// place in the number 
	k = digits.size() - k; 
	cout << solve(0, k, 0, 0); 
} 
