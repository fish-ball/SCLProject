\begin{lstlisting}
struct rect{int x1,y1,x2,y2;} r[maxm];
int mk[maxm];

int intersect(rect a,const rect &b,rect out[4]) // b cut a
{
    if( b.x2<=a.x1 || b.x1>=a.x2 || b.y2<=a.y1 || b.y1>=a.y2) return 0;
    if( b.x1<=a.x1 && b.x2>=a.x2 && b.y1<=a.y1 && b.y2>=a.y2) return -1;    
    rect t; int nout=0;
    if( b.x1>a.x1 ){ t=a;  t.x2=b.x1;  a.x1=b.x1;  out[nout++]=t; }
    if( b.x2<a.x2 ){ t=a;  t.x1=b.x2;  a.x2=b.x2;  out[nout++]=t; }
    if( b.y1>a.y1 ){ t=a;  t.y2=b.y1;  a.y1=b.y1;  out[nout++]=t; }
    if( b.y2<a.y2 ){ t=a;  t.y1=b.y2;  a.y2=b.y2;  out[nout++]=t; }
    return nout;
}

int main()
{
    rect curr,t[4]; int i,j,k,nn,nr,ans,rr,n;
    cin>>n; rr=0;
    for(i=0;i<n;i++){
        cin >> curr.x1 >> curr.y1 >> curr.x2 >> curr.y2;
        nr=rr; mk[rr]=1; r[rr++]=curr;
        for(j=0; j<nr; j++) { 
            mk[j]=1; nn=intersect(r[j],curr,t); if(!nn) continue;
            if( nn<0 ) mk[j] = 0; else { r[j] = t[--nn]; 
                while(nn) { mk[rr] = 1; r[rr++] = t[--nn]; }
            }
        }
        for(k=j=0; j<rr; j++) if(mk[j]) r[k++]=r[j]; rr=k;
    }
    for(ans=i=0; i<rr; i++) ans+=(r[i].x2-r[i].x1)*(r[i].y2-r[i].y1);
    cout<<ans<<endl;
    return 0;
}
\end{lstlisting}