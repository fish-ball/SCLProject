Given $n>0$, find distinct positive numbers $a_1+a_2+...+a_k=n$ that maximize $a_1\cdot a_2\cdot ...\cdot a_k$.
\begin{lstlisting}
int main()
{
    int n,k,p,i,caseno;
    for(cin>>caseno; caseno--; ){ cin>>n;
        for(p=n, k=2; p>=k; k++) p-=k; k--;
        if(p<=1){ for(i=2;i<k;i++) cout<<i<<" "; cout<<k+p<<endl;  } else
        if(p==k){ for(i=3;i<=k;i++) cout<<i<<" "; cout<<k+2<<endl; } else
            {   for(i=2+(p==k-1);i<=k;i++) if(i!=k-p+1) cout<<i<<" ";
                cout<<k+1<<endl; }
        if(caseno) cout<<endl;       
    }
    return 0;
}
\end{lstlisting}
