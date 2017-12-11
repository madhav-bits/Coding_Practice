/*

//**********************************************************179. Largest Number.*****************************************************

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.


//Time Complexity: O(nlogn).
// Space Complexity: O(n).

//********************************************************THIS IS LEET ACCEPTED CODE.***************************************************
*/


//Solution 1:
// The main logic is to sort elem. in increasing order of value as per the question(ex: "32"<"3 and "34">"3"). Gather them from the end-
//- and return them after removing leading zeroes if any.
 
 
class Solution {
public:
    static bool comparator(string x, string y){
		if(x+y< y+x)									//Didn't thought of this logic. Really cool it is.
			return 1;									//Gives true if x<y as per the question(ex: "32"<"3 and "34">"3").
		else
			return 0;
	}
    
    string largestNumber(vector<int>& v) {
        string s;
        vector<string> u;
        for(const auto& num: v)
            u.push_back(to_string(num));
        sort(u.begin(),u.end(),comparator);				//The resulting string is in ascending order of values.
        for(int i=u.size()-1;i>=0;i--)					//Pushing values from the end, as the values are in ascending order.
            s+=u[i];	
        while(0<s.length() && s.compare(0,1,"0")==0)	//Removing all the leading zeroes.
            s.erase(0,1);
        if(s.length()==0)								//In case of all zeroes, returning "0"(Single zero).
            s+="0";
        return s;
    }
};




//*****************************************************THIS IS NOT A LEET ACCEPTED CODE.************************************************
//Solution 2:
//Time Complexity: O(nlogn).
// Space Complexity: O(n).  
//I designed this algorithm, but don't know reason why it isn't working for the case of large no. of zeroes, tried out all possible slns.

 
class Solution {
public:
    static bool comparator(string x, string y){				//Works fine for all values, except for large no. of zeroes, don't know why.
      cout<<"Passed strings are x: "<<x<<"and y: "<<y<<endl;
      int i=0, j=0, b=0;
      if(x.length()< y.length()){
        swap(x,y);
        b=1;
      }
      while(i<x.length() && j<y.length()){
        if(x[i]<y[j] && b==1)
          return 0;
        if(x[i]>y[j] && b==1)
          return 1;
        if(x[i]<y[j] && b==0)
          return 1;
        if(x[i]>y[j] && b==0)
          return 0;
        i++; j++;
      }
      j--;
      while(i<x.length()){
        if(x[i]<y[j] && b==1)
          return 0;
        if(x[i]>y[j] && b==1)
          return 1;
        if(x[i]<y[j] && b==0)
          return 1;
        if(x[i]>y[j] && b==0)
          return 0;
          i++;
      }
      return 1;
    }
	
	
    string largestNumber(vector<int>& v) {
        string s;
        vector<string> u;
        cout<<"Before Allocation."<<endl;
        for(const auto& num: v)
            u.push_back(to_string(num));
        for(const auto& num:u)
            cout<<"the string is: "<<num<<endl;
        cout<<"Before sort."<<endl;
        sort(u.begin(),u.end(),comparator);
        cout<<"After sort."<<endl;
        for(int i=u.size()-1;i>=0;i--)
            s+=u[i];
        int j=0;
        while(j<s.length() && s.compare(j,1,"0")==0){
            cout<<"j is: "<<j<<" and length is: "<<s.length()<<endl;
            s.erase(0,1);    
        }  
        if(s.length()==0)
            s+="0";
        return s;
    }
};