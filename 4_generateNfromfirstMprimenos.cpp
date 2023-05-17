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

int genNumber(int cnt, int n, vector<int> &p, vector<vector<int> > &dp)
{
    if (n == 0)
        return cnt;
    if (n < 0)
        return INT_MAX;
    if (dp[cnt][n] != -1)
        return dp[cnt][n];
    int ans = INT_MAX;
    for (int i = 0; i < p.size(); i++)
    {
        int count = genNumber(cnt + 1, n - p[i], p, dp);
        ans = min(count, ans);
    }
    return dp[cnt][n] = ans;
}

int main()
{
    vector<int> primes;
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    // primes.push_back(7);
    // primes.push_back(11);
    int n = 11;
    vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
    cout
        << genNumber(0, n, primes, dp) << endl;
    return 0;
}