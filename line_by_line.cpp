// #P^(N - 1) = B^(N) -> P * (1 / P) ^ (1 / N) = B
// #Áp dụng Newton Raphson để tính B
// #kq = (B - P) * 100
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

int  n;
db k;

namespace sub
{

	double pw(double u,int l)
	{
	    if(l == 1) return u;
	    if(l == 0) return 1LL;
	    double w = pw(u,l/2); 
	    if(l & 1)
	    {
	        return w * w * u;
	    }
	    return w * w;
	}

	double nthRoot(double A, int N)
	{

	    double xPre = rand()  % 10 + 1;

	    double eps = 1e-6;
	 

	    double delX = INT_MAX;
	 

	    double xK;

	    while (delX > eps)
	    {

	        xK = ((N - 1.0) * xPre +
	              (double)A/pw(xPre, N-1)) / (double)N;
	        delX = abs(xK - xPre);
	        xPre = xK;
	    }
	 
	    return xK;
	}
	void xuly()
	{
	
		k = k / 100;
		db A = 1 / k;
		db B = k * nthRoot(A,n);
		cout<<setprecision(6)<<fixed;
		cout<<(B - k)*100<<'\n';
	}
}

void doc()
{
	cin>>n>>k;
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
