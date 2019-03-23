/*

//*****************************************MCIRGAME - Point Connection Game in a Circle.*********************************************
https://www.spoj.com/problems/MCIRGAME/




Time Complexity:O(n^2).                                                     // Assuming product takes O(1) time, but actually lot of time.                                                                                                                                       
Space Complexity:O(n).                                                      

*/


//***********************************************************Solution 1.*************************************************************
// Time Complexity:O(n^2).                                                  // Assuming product takes O(1) time, but actually lot of time.                                      
// Space Complexity:O(n).                                                   
// This is Dynamic Programming based solution. Here, since we have overlapping subproblems. We get #ways to split given nums. 
// into serveral parts. Where in each part, we multiply #ways to split nums in left, right halfs from dp array and multiply them
// to get final result. Since, the results are very large we use strings to store nums. 
// This is precomputation based, we precalclate #ways to split all possible nums. in given range and store them in DP array, once 
// receiving query, we return the values directly.



// Big Int multiplication, addition has been copied from: https://github.com/subodra999/Spoj-Solution/blob/master/MCIRGAME.cpp








#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
#include<fstream>


#define mod 1000000007
#define nax 1000005
#define inf 100000000000000000LL
#define pb push_back
#define mp make_pair
#define in insert
#define ff first
#define ss second
#define pll pair<long long int,long long int>
#define pii pair<int,int>
#define vll vector<long long int>
#define vii vector<int>
#define sii set<int>
#define vb vector<bool>
#define sll set<long long int>
#define mii map<int,int>
#define mll map<long long int,long long int>
#define mis map<int,string>
#define all(n) n.begin(),n.end()
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define lpi(i,a,b) for(int i=a;i<=b;i++)
#define lpir(i,a,b) for(int i=a;i>=b;i--)
#define lpl(i,a,b) for(ll i=a;i<=b;++i)
#define lplr(i,a,b) for(ll i=a;i>=b;--i)
#define lpv(c,it) for(vii::iterator it=(c).begin();it!=(c).end();it++)

using namespace std;



typedef unsigned long long int ll;

string dp[301];

string add(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
 
    // Take an empty string for storing result
    string str = "";
 
    // Calculate lenght of both string
    int n1 = str1.length(), n2 = str2.length();
 
    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
 
        // Calculate carry for next step
        carry = sum/10;
    }
 
    // Add remaining digits of larger number
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
 
    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');
 
    // reverse resultant string
    reverse(str.begin(), str.end());
 
    return str;
}

// Multiplies str1 and str2, and prints result.
string multiply(string num1, string num2)
{
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
       return "0";
 
    // will keep the result number in vector
    // in reverse order
    vector<int> result(n1 + n2, 0);
 
    // Below two indexes are used to find positions
    // in result. 
    int i_n1 = 0; 
    int i_n2 = 0; 
 
    // Go from right to left in num1
    for (int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
 
        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0; 
         
        // Go from right to left in num2             
        for (int j=n2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';
 
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position. 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
 
            // Carry for next iteration
            carry = sum/10;
 
            // Store result
            result[i_n1 + i_n2] = sum % 10;
 
            i_n2++;
        }
 
        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
 
        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }
 
    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
       i--;
 
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
       return "0";
 
    // generate the result string
    string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);
 
    return s;
}



void buildDP(vector<string>&dp){
    dp[0]="1";
    for(int i=2;i<=300;i+=2){
        for(int left=0;left<=i-2;left+=2){
            // dp[i]+=dp[left]*dp[i-left-2];
            dp[i]=add(dp[i], multiply(dp[left], dp[i-left-2]));
        }
    }

}


int main() {
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    ifstream cin;
    cin.open("F:\\Masters\\Coding_Practice\\CPP\\SPOJ\\testFile.txt");

    int num;
    cin>>num;
    vector<string> dp(301,"0");
    buildDP(dp);
    while(num!=-1){
        cout<<dp[2*num]<<endl;
        cin>>num;
    }
    return 0;
}
