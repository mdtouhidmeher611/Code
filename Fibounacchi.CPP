#include<bits/stdc++.h>
using namespace std;

int fibonoucci(int n){
	if(n==0 ) return 0;
	if (n==1) return 1;
	return fibonoucci(n-1)+ fibonoucci(n-2);
}

int main(){
    int n;
    cout<<"Enter number of terms: ";
    cin>>n;

    for(int i = 0; i < n; i++){
        cout<<fibonoucci(i)<<" ";
    }

    return 0;
}