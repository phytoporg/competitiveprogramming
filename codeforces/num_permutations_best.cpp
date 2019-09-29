#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;
const ll md=998244353;
const int mxn=3e5+5;
map<pair<int,int>,int> cp;
pair<int,int>a[mxn];
int n;
int cf[mxn]; // Counts the number of instances we run into first integers
int cs[mxn]; // Counts the number of instances we run into second integers
ll t=1;
ll f=1;
ll s=1;
ll p=1;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;

	for(int i=1;i<=n;++i){
		cin>>a[i].first>>a[i].second;

		(t *= i)                   %=md;
        (f *= (++cf[a[i].first]))  %=md;
        (s *= (++cs[a[i].second])) %=md;
        (p *= (++cp[a[i]]))        %=md;
	}

    // t = n!, the total possible number of permutations
    // f = (num repeated first digits)!
    // s = (num repeated second digits)!
    // p = (num repeated pairs)!
    cout << t << endl;
    cout << f << endl;
    cout << s << endl;
    cout << p << endl;

	t -= (f + s - p);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		if(a[i].second<a[i-1].second){
			t-=p; // remove (num repeated pairs)!
			break;
		}
	}
	cout<<(t%md+md)%md<<endl;
}
