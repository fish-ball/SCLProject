\begin{lstlisting}
int cc[1 << 22],m,n; // memset cc first

void update(int ii,int s,int t,int ss,int tt,bool insert) {
    if(ss>tt) return; int mid((s+t)/2);
    if(s==ss && t==tt){ if(insert) cc[ii]=t-s+1; else cc[ii]=0; return;}
    if(cc[ii]==0) if (!insert) return; else cc[ii*2]=cc[ii*2+1]=0;
    else if(cc[ii]==t-s+1) if(insert) return;
        else { cc[ii*2]=mid-s+1; cc[ii*2+1]=t-mid; }
    update(ii*2,s,mid,ss,__min(mid,tt),insert);
    update(ii*2+1,mid+1,t,__max(mid+1,ss),tt,insert);
    cc[ii]=cc[ii*2]+cc[ii*2+1];
}

int query(int ii,int s,int t,int ss,int tt) {
    if(ss>tt) return 0; int mid((s+t)/2);
    if(s==ss && t==tt) return cc[ii];
    if(cc[ii]==0) cc[ii*2] = cc[ii*2+1] = 0;
    if(cc[ii]==t-s+1) {cc[ii*2]=mid-s+1; cc[ii*2+1]=t-mid;}
    return query(ii*2,s,mid,ss,__min(mid,tt))
          +query(ii*2+1,mid+1,t,__max(mid+1,ss),tt);
}
\end{lstlisting}
