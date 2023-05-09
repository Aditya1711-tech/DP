#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#define ll long long int
using namespace std;

// Memoization
// Here TC -> O(N) ans SC -> O(N) + O(N)
                    // Stack space + For DP arry
/*
int fibonaci(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fibonaci(n - 2, dp) + fibonaci(n - 1, dp);
}
*/

// Tabulation
// Here TC -> O(N) and SC -> O(N)
//                      Because No recursion stack space
/*
int fibonaci(int n,vector<int> &dp){
    dp[0] = 0;
    dp[1] = 1;

    if(n <= 1){
        return dp[n];
    }

    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-2] + dp[i-1];
    }
    
    return dp[n];
}
*/

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    // cout << fibonaci(n, dp) << endl;

    // No use of extra space (Optimised SC -> O(1)) TC -> O(N)
    int prev2 = 0,prev1 = 1;
    for(int i=2;i<=n;i++){
        int curi = prev2 + prev1;
        prev2 = prev1;
        prev1 = curi;
    }
    cout<<prev1<<endl;

    return 0;
}