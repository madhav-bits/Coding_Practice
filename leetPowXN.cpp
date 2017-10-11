/*
Implement pow(x, n).
//************************************************THIS IS LEET ACCEPTED CODE.*******************************************
*/
class Solution {
public:
    double calcPower(double x, unsigned long long int n){
        cout<<"The n value is: "<<n<<endl;
        if(n==1)
            return x;
        int power; double ans;
        if(n%2==0){
            power=n/2;
            ans =calcPower(x,power);
            return ans*ans;
        }
        else{
            power=n/2;
            ans =calcPower(x,power);
            return ans*ans*x;
        }
    }
    
    double myPow(double x, int n) {
        double val;
        if(x==1 && n!=0)
            return 1;
        if(n==0)
            return 1;
        if (n>0){
            //unsigned long long int posPower=n;
            cout<<"For positive power."<<endl;
            val=calcPower(x,n);
        }
        else{
            //unsigned long long int negPower=(-1)*n;
            //cout<<"negpPower is: "<<negPower<<endl;
            cout<<n<<endl;
            if (n<-32765)// This is to just reducing the negative power, when the power goes beyond range of integer.
                n=-32000;
            val=calcPower(x,-n);
            val=(1/val);
        }
        cout<<"The answer is: "<<val<<endl;
        return val;
    }
};