\begin{lstlisting}
#define llong __int64

int ModPow(int a,int b,int n) // a^b mod n a,b>=0
{
    llong d(1),i(0);
    while (b>=((llong)1<<i)) i++;
    for (--i;i>=0;--i){ d=d*d%n; if(b&(1<<i)) d=d*a%n;}
    return d;
}

// x*x = a (mod n) n should be a prime and gcd(a,n)==1
int ModSqrt(int a,int n) 
{
    int b,k,i,x;
    if (n==2) return a%n;
    if (ModPow(a,(n-1)/2,n)==1) {
        if (n%4==3) x = ModPow(a,(n+1)/4,n); else {
            for(b=1; ModPow(b,(n-1)/2,n)==1; b++);
            i=(n-1)/2; k=0; do{ i/=2; k/=2;
                if((ModPow(a,i,n)*(llong)ModPow(b,k,n)+1)%n==0) k+=(n-1)/2;
            } while (i%2==0);
            x=( ModPow(a,(i+1)/2,n)*(llong)ModPow(b,k/2,n) ) % n;
        }   if(x*2>n) x=n-x; return x;
    } return -1;
}

int main()
{
    int a,n,casec,x; cin >> casec;
    while (casec--) {
        cin >> a >> n;  x = ModSqrt(a,n);
        if (x<0) cout << "No root" << endl;
        else if (x*2==n) cout << x << endl;
        else cout << x << ' ' << n-x << endl;
    }
    return 0;
}
\end{lstlisting}
