#include<iostream>
#include<vector>
#include<string>
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

// Link: https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

int findAns(int ind,vector<int> &dp,vector<int> &heights){
    if(ind == 0) return 0;

    if(dp[ind] != -1) return dp[ind];

    int left = findAns(ind - 1,dp,heights) + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;
    if(ind > 1) right = findAns(ind - 2,dp,heights) + abs(heights[ind] - heights[ind-2]);

    return dp[ind] = min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(heights.size()+1,-1);
    return findAns(n-1,dp,heights);
}

int main()
{
    int n = 4;
    vector<int> heights;
    heights.push_back(10);   
    heights.push_back(20);   
    heights.push_back(30);   
    heights.push_back(10);
    cout<<"Minimum energy will be: "<<frogJump(n,heights)<<endl;
    return 0;
}