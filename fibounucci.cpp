#include <bits/stdc++.h>
using namespace std;

int fib(int n){
	if(n==1) return 1;
	if(n==0) return 0;

	return fib(n-2)+fib(n-1);
}

int main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cout<< "  "<< fib(i) << "  ";
	}
	return 0;
}