\begin{lstlisting}
const int maxlen = 50005;
const int maxn   = 50000;

int n,st[maxlen],a[maxn],b[maxn],c[maxn],up;

int main(){
    int i,more;
    while(cin>>n){
        for(i=0; i<n; i++){
            cin>>a[i]>>b[i]>>c[i];
            if(++b[i]>up) up=b[i];
        }
        memset(st, 0, sizeof(st));
        for(more=1; more; ){
            more = 0;
            for(i=0; i<n; i++) if (st[a[i]]+c[i]>st[b[i]])
                { st[b[i]]=st[a[i]]+c[i];  more=1; }
            for(i=1; i<=up; i++) {
                if(st[i-1]+1<st[i]){ st[i-1]=st[i]-1; more=1; }
                if(st[i-1]  >st[i]){ st[i  ]=st[i-1]; more=1; }
            }
            for(i=up; i>0; i--){
                if(st[i]-1>st[i-1]){ st[i-1]=st[i]-1; more=1; }
                if(st[i-1]>st[i  ]){ st[i  ]=st[i-1]; more=1; }
            }
        }
        cout<<st[up] << endl;
    }   
    return 0;
}
\end{lstlisting}
