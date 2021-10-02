#include<bits/stdc++.h>

using namespace std;

void solve(int s , int d , int h , int n){
    if(n == 1){  // base condition i.e rod has only 1 plate.
        cout<<"move "<<n<<"from "<<s<<"to "<<d<<endl;
        return;
    }
    solve(s , h , d , n - 1);
    cout<<"move "<<n<<"from "<<s<<"to "<<d<<endl;
    solve(h , d , s , n - 1);
    return;

}

int main(){
    int n ;
    cout<<"Enter No. of Plates";
    cin>>n;
    int s =  1 , h = 2 , d = 3;  // s , h , d --> are source , helper and destination plates.
    solve(s , d , h , n);
    return 0;
}