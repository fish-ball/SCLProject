\begin{lstlisting}
#define llong __int64
inline int mod(int x,int n) {return (x%n+n)%n;}
\end{lstlisting}


// $ax \equiv 1$ (mod $n$)
\begin{lstlisting}
int Inv(int a,int n) 
{
    int d,x,y; Gcd(a,n,d,x,y);
    if (d==1) return mod(x,n); else return -1;
}
\end{lstlisting}

// $x \equiv a^b$ (mod $n$),  $a,b>=0$
\begin{lstlisting}
int ModPow(int a,int b,int n) 
{
    llong d(1),i(0); while (b>=((llong)1<<i)) i++;
    for(--i;i>=0;--i){ d=d*d%n; if(b&(1<<i)) d=d*a%n; }
    return d;
}
\end{lstlisting}

// $a^x \equiv b$ (mod $n$), $n$ is prime!

\begin{lstlisting}
int mexp[50000],id[50000];

bool logcmp(const int &a,const int &b) {return mexp[a]<mexp[b];}

int ModLog(int a,int b,int n)
{
    int i,j,m = (int)ceil(sqrt(n)), inv = Inv(ModPow(a,m,n),n);
    for (id[0]=0,mexp[0]=i=1;i<m;i++)
        { id[i]=i;mexp[i] = (mexp[i-1]*(llong)a)%n; }
    std::stable_sort(id,id+m,logcmp);
    std::sort(mexp,mexp+m);
    for (i=0; i<m; i++) {    // i*m < n
        j = std::lower_bound(mexp,mexp+m,b)-mexp;
        if (j<m && mexp[j]==b) return i*m+id[j];
        b = (b*(llong)inv)%n;
    }
    return -1;
}
\end{lstlisting}
