#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

static const long long MOD = 998244353;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Q;
	cin >> Q;

	vector<long long> pow10(Q+1);
	pow10[0]= 1;
	for (int i=1;i<=Q;i++){
		pow10[i] =( pow10[i-1]*10)%MOD;

	}
	deque<int>dq;
	dq.push_back(1);
	long long value ;

	while(Q--){
		int type;
		cin >> type;
		if (type ==1){
			int x;
			cin >>x;
			dq.push_back(x);
			value = (value*10+x)%MOD;

		}
		else if (type ==2){
			int front = dq.front();
			dq.pop_front();
			int len= dq.size();
			value = (value-front*pow10[len]%MOD+MOD)%MOD;

		}
		else{
			cout << value <<endl;
		}
	}
	return 0;
}