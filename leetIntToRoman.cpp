/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

//***********************************THIS IS LEET ACCEPTED CODE.*******************************************
*/

class Solution {
public:
    string intToRoman(int num) {
        string s;
        s="";
        int arr[]={1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5,4, 1};
        int size=sizeof(arr)/ sizeof(arr[0]);
        if(num==0)
            return s;
        map<int, string>m;
        m[1000]='M';
        m[900]="CM";
        m[500]='D';
        m[400]="CD";
        m[100]='C';
        m[90]="XC";
        m[50]='L';
        m[40]="XL";
        m[10]='X';
        m[9]="IX";
        m[5]="V";
        m[4]="IV";
        m[1]='I';
        //ut<<"9 string is: "<<m[400]<<endl;
        //int number=1000;
        //s="X";
        //s="V"+s;
        int rem;int numer;
        //ut<<"Size of array is: "<<size<<endl;
        int i=0;
        while(i<size){
            numer=1;
            while(numer>0){
                numer=num/arr[i];
                //ut<<"outside condition is: "<<arr[i]<<"and number is: "<<num<<endl;
                if(numer>0){
                    //ut<<"The divisor is: "<<arr[i]<<" numer is: "<<numer<<endl;
                    s=s+m[arr[i]];
                    //ut<<"The new string is: "<<s<<endl;
                    num-=(arr[i]*1);
                }
            }
            i+=1;
        }
        //ut<<"The string is: "<<s<<endl;
        return s;
    }
};