#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll a, x, m, p;
	cout << "type the m: ";
	cin >> m;

	vector<ll>fullPeriodAndModulusCompatibility;
    for(int i = 1; i < m; i++)
    {
        p = 1;
        x = i;
        while(x != 1){
            p++;
            x = (i * x) % m;
        }

        if(p == m-1 && m%i < floor(m/i)){
			cout << i << " is a full period and modulus compatibility" << endl;
			fullPeriodAndModulusCompatibility.push_back(i);
		}
    }

	cout << endl;
	for(ll i = 0; i < fullPeriodAndModulusCompatibility.size(); i++)
	{
		if(i) cout << " ";
		cout << fullPeriodAndModulusCompatibility[i];
	}
	cout << endl;
	cout << "count " << fullPeriodAndModulusCompatibility.size() << endl;
    return 0;
}
