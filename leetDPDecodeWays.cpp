/*
*
//*************************************************************91. Decode Ways.****************************************************

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

//These are the cases, I had worked on.
"12232624278492048483"
"12222222222"


// Time Complexity: O(n).
// Space Complexity: O(1	).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************

*/


//************************************************************Solution 1:************************************************************
// Time Complexity: O(n).
// Space Complexity: O(1).

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;
        if (n == 1) return 1;
        int pre2 = 1, pre1 = 1;
        int cur;
        for (int i = 1; i < n; ++i) {
            cur = 0;
            int first = (s[i] - '0');
            int second = stoi(s.substr(i - 1, 2));
            if (1 <= first && first <= 9)						//Adding prev-1 values, as they equals the case when curr. is in original state.
                cur += pre1;
            if (10 <= second && second <= 26)					//Adding prev-2 values, as they indir. indicate "i-1,i" indexes indi. as "L"-"Z".
                cur += pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;												//Returning the no. of ways to represent the elem. upto index "i".
    }
};



//************************************************************Solution 2:************************************************************
//********************************************************THIS IS NOT LEET ACCEPTED CODE.***************************************************
//It had passed 244/259 cases. Need to Improve the code.
// Time Complexity: O(n).
// Space Complexity: O(n).




class Solution {
public:
    int numDecodings(string s) {
        int result;
        int len=s.length();
        int count=0,seq=0;
        vector<int>v(len,0);
        if(stoi(s.substr(0,2))<=26){
            count++;
            v[0]=1;
        }
        
        for(int i=1;i<len-1;i++){
            string temp=s.substr(i,2);
            cout<<"Temp string for i: "<<i<<" is: "<<s.substr(i,2)<<endl;
            if(stoi(temp)<=26){
                count++;
                //v[i]=1;
                if(v[i-1]>=1){
                    v[i]=v[i-1]+1;
                    //seq++;
                }
                else
                    v[i]=1;
            }
            
        }
        for(int i=0;i<len;i++){
            cout<<"Value of v[i] at index i: "<<i<<" is: "<<v[i]<<endl;
            if(v[i]>=2 && ((i+1)==len ||v[i+1]==0))
                seq+=pow(2,v[i]-1)-1;
        }
        cout<<"The count is: "<<count<<endl;
        cout<<"The seq is: "<<seq<<endl;
        result=pow(2,count)-seq;
        cout<<"The result is: "<<result<<endl;
        return result;
    }
};






//************************************************************Solution 3:************************************************************
//********************************************************THIS IS NOT LEET ACCEPTED CODE.***************************************************
// Time Complexity: O(n).
// Space Complexity: O(n).
//This is the solution I had come up with keeping Alphabet occurences number representation in binary format. Need to Improve the code.



class Solution {
public:
    int numDecodings(string s) {
        if(s=="null" || s.length()==0 || s.compare(0,1,"0")==0)
            return 0;
        int len=s.length();
        if(len==1)
            return 1;
        int result;
        int count=0,seq=0;
        vector<int>v(len,0);
        v[0]=s.compare(0,1,"0")==0?0:1;
        if(s.compare(1,1,"0")==0)
            return 0;
        v[1]=1;
        if(s[1]>0 && s[1]<=10)
            v[1]=2;
        if(stoi(s.substr(0,2))<=26 && stoi(s.substr(0,2))>10)
            v[1]=2;
        for(int i=2;i<len;i++){
            if(s.compare(i,1,"0")==0)
                return 0;
            if(stoi(s.substr(i,1))<=9 && stoi(s.substr(i,1))>=1)
            v[i]+=v[i-1];
            if(stoi(s.substr(i-1,2))<=26 && stoi(s.substr(i-1,2))>=10)
                v[i]+=v[i-2];
        }
        
        //for(int i=0;i<len;i++){
        //    cout<<" value for index i: "<<i<<" is: "<<v[i]<<endl;
        //}
        //cout<<"The result is: "<<v[len-1]<<endl;
        return v[len-1];
    }
};