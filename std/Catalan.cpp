\begin{lstlisting}

\\ Catalan[ 19] = 1767263190           < 2^31
\\ Catalan[ 35] = 3116285494907301262  < 2^63
\\ Catalan[100] = 896519947090131496687170070074100632420837521538745909320

#define maxn 1000
#define maxlen 700
#define maxpnum 400

int prime[maxpnum],primepos[maxn*2],num[maxpnum],pnum;

struct HP{ int len; int s[maxlen]; };

void PrintHP(HP x) { for(int i=x.len; i>0; i--) cout<<x.s[i]; }

void Multi(HP &x,int k)
{
    int i; for(i=1;i<=x.len;i++) x.s[i]*=k;
    x.len+=8; // log(10,maxn*2);
    for(i=1;i<=x.len;i++) { x.s[i+1]+=x.s[i]/10; x.s[i]%=10; }  
    while( x.len>1 && !x.s[x.len]) x.len--;
}

void Factorize(int x,int flag)
{
    for(int i=0; prime[i]*prime[i]<=x; i++)
        while( x%prime[i]==0 ) { x/=prime[i]; num[i]+=flag; }
    if(x>1) num[primepos[x]]+=flag;
}

HP Catalan(int n)
{
    HP x; memset(&x,0,sizeof(x)); x.len=1; x.s[1]=1;
    memset(num,0,sizeof(num)); int i,j;
    for(i=1;i<=n;i++) { Factorize(2*n+1-i , 1); Factorize(i,-1); }
    Factorize(n+1,-1);
    for(i=0;i<pnum;i++) while(num[i]-->0) Multi(x,prime[i]);            
    return x;
}

void InitPrimes()
{
    int i,j; pnum=0; memset(primepos,0,sizeof(primepos));
    for(i=2;i<=maxn*2;i++) if(!primepos[i]) {
        primepos[i]=pnum; prime[pnum++]=i;
        for(j=i+i;j<=maxn*2;j+=i) primepos[j]=-1;
    }   
}

void main()
{
    InitPrimes(); int n;
    while(cin>>n) { PrintHP(Catalan(n));cout<<endl; }
}
\end{lstlisting}
