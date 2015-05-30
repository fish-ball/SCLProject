\subsection*{Graham Scan, $O(N\log N)$}
\begin{lstlisting}
CPoint bp; // for polar sorting

int PolarCmp(const CPoint &p1,const CPoint &p2)
{
    int u=dcmp(cross(bp,p1,p2));
    return u>0 || ( u==0 && dcmp(dissqr(bp,p1)-dissqr(bp,p2))<0 );
}

void GrahamScan(CPoint pin[], int n, CPoint ch[], int &m)
{
    int i,j,k,u,v;
    memcpy(ch, pin, n*sizeof(CPoint));
    for(i=k=0; i<n; i++)
    {       
        u = dcmp( ch[i].x - ch[k].x );
        v = dcmp( ch[i].y - ch[k].y );
        if( v<0 || (v==0 && u<0) ) k=i;
    }           
    bp = ch[k];
    std::sort(ch, ch+n, PolarCmp);
    n = std::unique(ch, ch+n, PointEqual)-ch;
    if( n<=1 ) { m = n; return; }
    if( dcmp(cross(ch[0],ch[1],ch[n-1]))==0 ) 
        { m=2; ch[1]=ch[n-1]; return; } 
    ch[n++]=ch[0];
    for(i=1,j=2; j<n; j++)
    {
        while( i>0 && dcmp(cross(ch[i-1],ch[i],ch[j]))<=0 ) i--;
        ch[++i] = ch[j];
    }
    m=i;
}

void GrahamScanReserved(CPoint pin[], int n, CPoint ch[], int &m)
{
    int i,j,k,u,v;
    memcpy(ch, pin, n*sizeof(CPoint));
    for(i=k=0; i<n; i++)
    {       
        u = dcmp( ch[i].x - ch[k].x );
        v = dcmp( ch[i].y - ch[k].y );
        if( v<0 || (v==0 && u<0) ) k=i;
    }           
    bp = ch[k];
    std::sort(ch, ch+n, PolarCmp);
    n = std::unique(ch, ch+n, PointEqual)-ch;
    if( n>0 && dcmp(cross(ch[0],ch[1],ch[n-1])) )
    {
        for(i=n-1; dcmp(cross(ch[0],ch[n-1],ch[i]))==0; i--);
        std::reverse(ch+i+1,ch+n);
    }
    for(m=0,i=0; i<n; i++)
    {
        while( m>=2 && dcmp(cross(ch[m-2],ch[m-1],ch[i]))<0 ) m--;
        ch[m++] = ch[i];
    }
}
\end{lstlisting}

\subsection*{Montone Chain, $O(N\log N)$}
\begin{lstlisting}
int VerticalCmp(const CPoint &p1,const CPoint &p2)
{
    return p1.y+eps<p2.y || (p1.y<p2.y+eps && p1.x+eps<p2.x);
}

void MontoneChain(CPoint pin[], int n, CPoint ch[], int &m)
{
    int i,k; CPoint *p = new CPoint[n]; 
    memcpy(p, pin, n*sizeof(CPoint));
    std::sort(p,p+n,VerticalCmp);
    n = std::unique(p,p+n,PointEqual)-p;
    for( m=i=0; i<n; i++ ) 
    {
        while( m>1 && dcmp(cross(ch[m-2],ch[m-1],p[i]))<=0 ) m--;
        ch[m++]=p[i];
    }
    k=m;
    for( i=n-2; i>=0; i-- ) 
    {
        while( m>k && dcmp(cross(ch[m-2],ch[m-1],p[i]))<=0 ) m--;
        ch[m++]=p[i];
    }
    if(n>1) m--; 
    delete p; 
}

void MontoneChainReserved(CPoint pin[], int n, CPoint ch[], int &m)
{
    int i,k;
    CPoint *p = new CPoint[n]; memcpy(p, pin, n*sizeof(CPoint));
    std::sort(p,p+n,VerticalCmp);
    n = std::unique(p,p+n,PointEqual)-p;
    for( m=i=0; i<n; i++ ) 
    {
        while( m>1 && dcmp(cross(ch[m-2],ch[m-1],p[i]))<0 ) m--;
        ch[m++]=p[i];
    }
    if( n==m ) return;
    k=m;
    for( i=n-2; i>=0; i-- ) 
    {
        while( m>k && dcmp(cross(ch[m-2],ch[m-1],p[i]))<0 ) m--;
        ch[m++]=p[i];
    }
    if(n>1) m--;
    delete p;
}
\end{lstlisting}

\newpage

\subsection*{Javis March, $O(N\,H)$}
\begin{lstlisting}
int ConvexJavisMarchCmp(CPoint p0,CPoint p1,CPoint pnew)
{
    int u=dcmp(cross(p0,p1,pnew));
    return (u<0 || (u==0 && dcmp(dissqr(pnew,p0)-dissqr(p1,p0))>0));        
}

void ConvexJavisMarch(CPoint pin[], int n, CPoint ch[], int &m)
{
    int i,j,k,u,v;
    char *mk = new char[n];
    CPoint *p = new CPoint[n];
    memcpy(p,pin,n*sizeof(CPoint));
    memset(mk,0,n);
    for(i=k=0;i<n;i++)
    {       
        u=dcmp(p[i].x-p[k].x);
        v=dcmp(p[i].y-p[k].y);
        if( v<0 || (v==0 && u<0) ) k=i;
    }           
    for(m=0; !mk[k]; m++)
    {
        mk[k]=1; ch[m]=p[k];
        for(j=k=0;j<n;j++) if(ConvexJavisMarchCmp(ch[m],p[k],p[j])) k=j;
    }
    delete p;
    delete mk;
}
\end{lstlisting}