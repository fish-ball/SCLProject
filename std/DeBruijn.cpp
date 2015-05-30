\begin{lstlisting}
int go[1<<maxn],start,now,n,k,a[(1<<maxn)+maxn],i,ans,caseno;   

int main()
{
    ifstream cin("input.txt");
    for(cin>>caseno; caseno--;){ cin>>n>>k;
        memset(go,0,sizeof(go));  memset(a,0,sizeof(a));
        now=start=(1<<(n-1))-1;    i=0;
        do { if(go[now]){ a[i++]=1; now=(now*2+1)&start; }
         else { go[now]=1; a[i++]=0; now=(now*2)&start; }
        } while( now!=start );
        a[i++]=1;
        for(i=0; i<n; i++) a[i+(1<<n)]=a[i];
        for(ans=i=0; i<n; i++) ans=ans*2+a[k+i];
        cout<<ans<<endl;
    }
    return 0;
}
\end{lstlisting}
