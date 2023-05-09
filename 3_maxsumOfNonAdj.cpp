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
using namespace std;


// Problem link: https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261
// Recursive
/*
int printF(int i, int arr[])
{
    if(i == 0) return arr[i];

    if(i < 0) return 0;

    int l = printF(i - 2, arr) + arr[i];
    int r = printF(i - 1, arr);

    return max(l,r);
}
*/

// Memoizetoin
/*
int printF(int i, int arr[],vector<int> &dp)
{
    if(i == 0) return arr[i];

    if(dp[i] != -1) return dp[i];

    if(i < 0) return 0;

    int l = printF(i - 2, arr,dp) + arr[i];
    int r = printF(i - 1, arr,dp);

    return dp[i] = max(l,r);
}
*/

// Tabular
int printF(int ind, int arr[],vector<int> &dp,int n)
{
    dp[0] = arr[0];
    int neg = 0;

    for(int i=1;i<n;i++){
        int l = arr[i];
        if(i>1){
            l += dp[i-2];
        }
        int r = dp[i-1];
        dp[i] = max(l,r);
    }

    return dp[ind];
}

int main()
{
    int arr[] = {3, 1, 2, 4};
    int n = 4;
    vector<int> dp(n+1,-1);
    int ans = printF(3,arr,dp,n);
    cout << "Max sum is: "<<ans<<endl;
    return 0;
}