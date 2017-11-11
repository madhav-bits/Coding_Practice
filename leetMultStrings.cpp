/*

//***********************************************43. Multiply Strings.*************************************************************
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

// Solution 1: 
//Time Complexity: O(n^2).
// Space Complexity: O(n).
//**************************************************THIS IS LEET ACCEPTED CODE.*************************************************
*/

class Solution {
public:
    string multiply(string s1, string s2) {
        if(s1=="0" || s2=="0")
            return to_string(0);
        vector<int> u,v,w(s1.length()+s2.length(),0);// W is vector the multiplication result is put into.
        int a=s1.length()-1, b=s2.length()-1;// W is already safely initialized to this length, so that we need not use push_back fn.
        for(int i=0;i<s1.length();i++)// Converting string's char into integers and storing them in vectors-
            u.push_back(int(s1[i])-48);//- useful while multiplying.
        for(int i=0;i<s2.length();i++)
            v.push_back(int(s2[i])-48);
        
        for(int i=b;i>=0;i--){// Multiplying two integers(pushed into vectors.)
            int rem=0,val=0;// rem means which needs to pushed into adjacent number(when value is >= 10).
            for(int j=a;j>=0;j--){
                val=(v[i]*u[j])+rem+w[b+a-i-j];//w[b+a-i-j] is the prior value existing at that index used in interlayer(final step)addition.
                //cout<< "val is: "<<val<<" with i is: "<<i<< " and j is: "<<j<<endl;
                w[b+a-i-j]=val%10;// Pushing the val. <9
                rem=val/10;// Storing the val. needs to be pushed into adj. value.
            }
            w[b+a-i+1]=rem;// Pushing the final rem. into vector if remained after every row of multiplications.
        }
        int i=0, j=w.size()-1;
        while(i<=j){// Placing the integer, it was reversed till now.
            swap(w[i], w[j]);
            i++; j--;
        }
        int e=0;
        while(w[e]==0)// Finding the first non-zero val as the beginning zeroes doesn't have any value.
            e++;
        string res;
        for(int f=e;f<w.size();f++)// Pushing into string from the first non-zero value in the final result-w(int).
            res+=to_string(w[f]);
        //for(const auto& num: w)// To print elements of vector w.
        //    cout<<num<<endl;
        return res;
    }
};



// Solution 2: 
//Time Complexity: O(n).
// Space Complexity: O(1).
//**************************THIS IS STRAIGHT FORWARD WAY OF DOING THIS, BUT GIVES INT VALUE EXCEEDING ERRORS.***********************
//**************************************************THIS IS NOT LEET ACCEPTED CODE.*************************************************
class Solution {
public:
    string multiply(string num1, string num2) {
        unsigned long long int dig1=0, dig2=0, len=num1.length(), result;
        for(unsigned long long int i=0;i<len;i++){
            dig1+=(int(num1[i])-48)*pow(10,len-1-i );
        }
        cout<<" dig1 is: "<<dig1<<endl;
        len=num2.length();
        for(unsigned long long int i=0;i<len;i++){
            dig2+=(int(num2[i])-48)*pow(10,len-1-i );
        }
        cout<<" dig2 is: "<<dig2<<endl;
        result=dig1*dig2;
        cout<<"the integer is: "<<result<<endl;
        return to_string(result);
    }
};