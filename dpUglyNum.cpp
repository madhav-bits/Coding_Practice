#include<iostream>
#include<cstdlib>

using namespace std;

// Calculates the number in the particular position in the ugly number series(Which are divisible by 2,3,5 only).

int min(int a, int b, int c){
    if(a<=b && a<=c)
        return a;
    else if(b<=a && b<=c)
        return b;
    else if(c<=b && c<=a)
        return c;
}


int uglyFn(int des_count){
    int ugly[des_count];
    ugly[0]=1;
    int i1=0;
    int i2=0;
    int i3=0;
    int count=1;
    int next_number=1;int next_multi;
    while(count<des_count){
        next_multi=min(ugly[i1]*2, ugly[i2]*3, ugly[i3]*5);
        if(next_multi %2==0){//If the next int is divisible by 2, then 2's index inc.
            next_number=ugly[i1]*2;// Useful in the cases->6=2*3, then i1, i2 increases.
            i1++;
            ugly[count]=next_number;
        }
        if(next_multi %3==0){//If the next int is divisible by 3, then 3's index inc.
            next_number=ugly[i2]*3;// Useful in the cases->6=2*3, then i1, i2 increases.
            i2++;
            ugly[count]=next_number;
        }
        if(next_multi %5==0){
            next_number=ugly[i3]*5;
            i3++;
            ugly[count]=next_number;
            
        }
        count++;
    }
    return next_number;
}


int main(){
    cout<<"Hi"<<endl;
    int des_count=150;
    int number=uglyFn(des_count);
    cout<<number<<" is the "<<des_count<<" th ugly number."<<endl;
    return 0;
}
