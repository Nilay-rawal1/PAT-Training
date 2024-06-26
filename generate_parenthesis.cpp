#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_SIZE 100

void _generateParenthesis(int pos, int n, int open, int close, vector<string> &result);

// Wrapper over _generateParenthesis()
void generateParenthesis(int n, vector<string> &result)
{
	if (n > 0)
		_generateParenthesis(0, n, 0, 0, result);
	return;
}

void _generateParenthesis(int pos, int n, int open, int close, vector<string> &result)
{
	static char str[MAX_SIZE];

	if (close == n) {
		str[pos] = '\0';
		result.push_back(str);
		return;
	}
	else {
		if (open > close) {
			str[pos] = ')';
			_generateParenthesis(pos + 1, n, open, close + 1, result);
		}

		if (open < n) {
			str[pos] = '(';
			_generateParenthesis(pos + 1, n, open + 1, close, result);
		}
	}
}

// Driver program to test above functions
int main()
{
	int n;
	cin >> n;

	vector<string> result;
	generateParenthesis(n, result);

	// Reverse the result vector to match the expected output format
	reverse(result.begin(), result.end());

	// Print the result
	for (const string &s : result) {
		cout << s << " ";
	}

	return 0;
}
