/*

//***********************************************537. Complex Number Multiplication***********************************************

Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the 
range of [-100, 100]. And the output should be also in this form.

//Time Complexity: O(n).
// Space Complexity: O(n).

//**************************************************THIS IS LEET ACCEPTED CODE.*************************************************
*/

class Solution {
public:
    vector<int> extractInt(string s){
        int a=0,b=0,i=0, len=s.length();
        vector<int> v;
        while(s.compare(i,1,"+")!=0)
            i++;
        
        a=stoi(s.substr(0,i+1));// Extracting the real part of complex number.
        v.push_back(a);// Pushing real part into vector.
        b=stoi(s.substr(i+1,len-2-i));// Extracting the imaginary part of complex number.
        v.push_back(b);// Pushing imaginary part into vector.
        //cout<<" a is: "<<a<<" and b is: "<<b<<endl;
        return v;
    }
    string complexNumberMultiply(string a, string b) {
        vector<int> u,v;
        u=extractInt(a);
        v=extractInt(b);
        int real, imag;
        real=u[0]*v[0]-u[1]*v[1];// Calc. real part of final result.
        imag=u[0]*v[1]+u[1]*v[0];// Calc. imag. part of final result.
        //cout<<" real is: "<<real<<" and imag is: "<<imag<<endl;
        string t;
        t+=to_string(real)+"+"+to_string(imag)+"i";// Pushing the calc. values into final result string.
        
        return t ;
    }
};