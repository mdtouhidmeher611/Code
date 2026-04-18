#include<bits/stdc++.h>

using namespace std;

void toh(int n , char beg , char  aux , char end){
	if(n==1){
		cout <<" disk " << n <<" : "<< beg << " to " << end << endl ;
		return;
	}
	toh(n-1,beg,end,aux);
	cout <<" disk " << n <<" : "<< beg << " to " << end << endl ;
	toh(n-1,aux,beg,end);

}
int main(){

	int n;
	cin>>n;
	toh(n,'x','y','z');
	return 0;
}