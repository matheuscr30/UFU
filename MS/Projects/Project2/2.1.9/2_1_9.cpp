#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
 
int main(){
    ll m;
    cout << "type the m: ";
    cin >> m;
 
    vector<ll>relativePrimes;
    ll cont = 0;
    for(ll i = 1; i < m-1; i++)
    {
        if(__gcd(m-1, i) == 1)
            relativePrimes.push_back(i);
 
        if(relativePrimes.size() == 10)
            break;
    }
 
	cout << endl;
    for(ll i = 0; i < relativePrimes.size(); i++)
    {
        if(i) cout << " ";
        cout << relativePrimes[i];
    }
    cout << endl;
    return 0;
}