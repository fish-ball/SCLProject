Use C colors to color L-bead necklace , the non-isomorphic number of the necklaces is : \\

\mbox{If L is odd ,} \[ f(C,L)= \frac{1}{2L} (LC^{\frac{L+1}{2}} + \sum_{K=1}^{L} C^{(K,L)})\]  \\

\mbox{If L is even,} \[ f(C,L)= \frac{1}{2L} (\frac{L}{2}(C^{\frac{L}{2}}+C^{\frac{L}{2}+1}) + \sum_{K=1}^{L} C^{(K,L)})\] \\

\begin{lstlisting}
int ans,n,m,mk[maxn],id[maxn],num;

int main()
{
    int i,j,k,l,d,u,p[maxn];
    while(cin>>n>>m && n && m){
        for(p[0]=i=1; i<=m;i++) p[i]=p[i-1]*n;
        for(ans=num=i=0;i<m;i++) id[i]=i;
        for(l=0;l<2;l++){
            for(i=0;i<m;i++) {
                memset(mk,0,sizeof(mk));
                for(k=j=0;j<m;j++) if(!mk[id[j]])
                    for(k++, u=id[j];!mk[u];u=id[(u+i)%m]) mk[u]=1; 
                num++; ans+=p[k];
            }
            std::reverse(id,id+m);
        }   cout<<ans/num<<endl;
    }   
    return 0;   
}
\end{lstlisting}
