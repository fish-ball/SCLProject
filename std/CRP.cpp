Coloring regular $n$-vertex polygon with $m$ white and $n-m$ black.
When $n=17$ and $m=8$ OUTPUT : $750$
\begin{lstlisting}
int c[maxn][maxn], ans, n, m;

int gcd(int i,int j){ if(j==0) return i; else return gcd(j,i%j); }

int main()
{
    cin>>n>>m;  
    int i,j,k,l,d;  
    c[0][0]=1;
    for(i=1; i<maxn; i++) { 
        c[i][0]=1;
        for(j=1; j<=i; j++) c[i][j]=c[i-1][j]+c[i-1][j-1];      
    }   
    for(k=0;k<m;k++) { 
        d=gcd(m,k);
        if( n*d % m == 0 ) { l=n*d/m; ans+=c[l-1][d-1]; }
    }   
    if(m%2==0) {
        if(n%2==0) ans+=(m/2)*c[n/2-1][m/2-1];
        if(m==2) ans+=(m/2)*(n-1); else
            for(i=2-n%2; i<=n-(m-2); i+=2) 
                ans+=(m/2)*(i-1)*c[(n-i)/2-1][(m-2)/2-1];
    } else for(i=2-n%2; i<=n-(m-1); i+=2) ans+=m*c[(n-i)/2-1][(m-1)/2-1];
    cout<<ans/(2*m)<<endl;          
    return 0;   
}
\end{lstlisting}