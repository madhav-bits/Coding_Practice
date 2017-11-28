/*

//*************************************************************372. Super Pow.*****************************************************

Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:

a = 2
b = [3]

Result: 8
Example2:

a = 2
b = [1,0]

Result: 1024
Credits:
Special thanks to @Stomach_ache for adding this problem and creating all test cases.





//Time Complexity: O(nlogn).
// Space Complexity: O(1).

//****************************************************THIS IS LEET ACCEPTED CODE.**********************************************
*/
//This is sort of easy question, logic wise. But not implementation wise, we have to convert(mod) the number to be less than 
//-1337 at each and every moment. Line 42 had caused hell lot of problems. :(

class Solution {
public:
    int powCalc(int num, int power){
        if(power==0)
            return 1;
        if(power==1)
            return num;
        if(power%2==0){
            int temp=powCalc(num, power/2);
            return (temp*temp)%1337;
        }
        else{
            int temp=powCalc(num, power/2);
            temp=(temp*temp)%1337;//Damn this point, this single line had wasted almost 1.5 hours.
            return (temp*num)%1337;// Able to this of this point when I was able to posopone solving this problem.
        }
            
    }
    
    int superPow(int a, vector<int>& v) {
        if(v.size()==1 && v[0]==0)
            return 1;
        if(v.size()==1 && v[0]==1)
            return a;
        int fin=1, temp2=1;
        a=a%1337;
        //cout<<" a is: "<<a<<endl;
        for(int i=0;i<v.size();i++){
            //cout<<"fin at the beginning of index i: "<<i<<" is: "<<fin<<endl;
            fin=powCalc(fin,10);
            temp2=powCalc(a, v[i]);;
            fin=(fin*temp2)%1337;
            //cout<<"fin after multi. with temp at index i: "<<i<<" is: "<<fin<<endl;
        }
        
        //cout<<"The result is: "<<fin<<endl;
        return fin;
    }
};