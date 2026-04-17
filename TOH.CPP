#include<bits/stdc++.h>
using namespace std;

void TOH(int n , char beg ,char aux, char end){

		if(n==1){
			cout << " disk " <<n<< " : " <<" from "<< beg << " to " <<end << endl;
			return;
		}
		TOH(n-1,beg,end,aux);
		cout<< " disk " <<n<< " : " <<" from "<< beg << " to " <<end << endl;
		TOH(n-1,aux,beg,end);

}



int main(){
	int n;
	cin >> n;
	TOH(n,'A','B','C');
	return 0;
}