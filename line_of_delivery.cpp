// #Nhận thấy việc bi đụng nhau rồi bay ra xa k ảnh hưởng đến thứ tự của các viên bi
// #sort lại rồi dụng cnp để tìm vtri gần với G nhất
#define TASK "text"
#define INPUT TASK".INP" 
#define OUTPUT TASK".OUT"
#include<bits/stdc++.h>
using namespace std; 
bool multitest = 1;
#define ll long long 
#define int ll
#define db double 
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define vi vector<int>
#define vll vector<ll> 
#define ve vector 
#define str string 
#define pb push_back 
#define pk pop_back 
#define el '\n'
#define fi first 
#define se second  
#define tct template<typename T>
#define FOR(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define FORD(i,a,b) for(int i=(int)(a);i>=(int)(b);i--)
#define FORN(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(a) a.begin(),a.end() 
#define btpc(a) __builtin_popcount(a)  
ll lg(ll a){return __lg(a);}
ll sq(ll a){return a*a;}  
ll gcd(ll a , ll b){return __gcd(a,b);} 
ll lcm(ll a,  ll b){return a/gcd(a,b)*b;}
tct bool mini(T& a,const T& b){return (a>b)?a=b,1:0;}
tct bool maxi(T& a,const T& b){return (a<b)?a=b,1:0;}
tct void prt(T a[] ,int n ){FOR(i,1,n)cout<<a[i]<<" ";cout<<el;}
int xx[] = {0,0,-1,0,1}; 
int yy[] = {0,-1,0,1,0};
 
const int N = 1e6+5, oo = 2e9, LO = 19; 
const ll inf = 1e17, cs = 330, sm = 1e9+7; 
const db PI = acos(-1), e = 1e-9;

int  n,G;
int a[N];

namespace sub
{

	int dd[N];
	void xuly()
	{
		a[0] = -1e6;
		a[n + 1] = 1e6;
		sort(a + 1,a + n + 1);
		FORD(i,n,1)
		{
			dd[a[i]] = n - i + 1;
		}
		int r = upper_bound(a,a + n + 1,G) - a;
		int l = upper_bound(a,a + n + 1,G) - a - 1;
		
		// cout<<l<<" "<<r<<" "<<a[l]<<" "<<a[r]<<endl;
		if(abs(a[r] - G) <= abs(a[l] - G))
		{
			int pos = dd[a[r]];
			cout<<pos<<" "<<abs(a[r] - G)<<'\n';
		}
		else
		{
			int pos = dd[a[l]];
			cout<<pos<<" "<<abs(a[l] - G)<<'\n';
		}
	}
}

void doc()
{
	cin>>n>>G;
	FOR(i,1,n) cin>>a[i];
}

signed main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    if(fopen(INPUT,"r"))
    {
        freopen(INPUT ,"r",stdin);
        freopen(OUTPUT,"w",stdout);
    }
    int test =1;
    if(multitest)cin>>test;
    srand(time(NULL));
    FOR(i,1,test)
    {
        doc() ;
        cout<<"Case #"<<i<<": "; 
        sub::xuly();
    }
    cerr<<el<<"Time: "<<clock()<<"ms"<<el;
}
