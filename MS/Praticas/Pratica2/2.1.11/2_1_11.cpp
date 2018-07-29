#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, x, m, p;
	cout << "type the m: ";
	cin >> m;

	int cont = 0;
    for(int i = 1; i < m; i++)
    {
        p = 1;
        x = i;
        while(x != 1){
            p++;
            x = (i * x) % m;
        }

        if(p == m-1){
			cout << i << " is a full period" << endl;
			cont++;
        }
        else
			cout << i << " is not a full period" << endl;
    }

	cout << "There are " << cont << " full period multipliers" << endl;
    return 0;
}
