#include<cstdlib>
#include<vector>
#include<iostream>
#include<algorithm>
#include<string>


using namespace std;



//***************************************************FIDESSA TECHNICLA RECRUITING EXAMINATION.****************************************
//************************************************************************************************************************************
//Need to find out if the given measurements forms a Isosceles, Equilateral, None of These or Such a Triangle Exists Or Not.


int main() {
/* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
            long int a,b,c;
        cin>>a; cin>>b; cin>>c;
        //cout<<"a is: "<<a<<endl;
        //cout<<"b is: "<<b<<endl;
        //cout<<"c is: "<<c<<endl;
        if(a+b<c ||a+c<b ||b+c<a)
            cout<<"None of these"<<endl;		//Such a Triangle doesn't exist.
        else if(a==b && b==c && a==b)			//Equilateral Triangle.
            cout<<"Equilateral"<<endl;
        else if(a==b || b==c || a==c)			//Isosceles Triangle.
            cout<<"Isosceles"<<endl;
        else
            cout<<"None of these"<<endl;		//Triangle Exists, but not a Equilateral and Isosceles Triangle.
    }
return 0;
}