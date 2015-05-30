{\rm P} must be convex in ccw order and no trhee points on an edge
and will be changed after computing it's convex hull
\begin{lstlisting}
double Diameter(CPoint *p, int n)
{
    Convex( p, n, p, n );       
    if( n==1 ) return 0;
    if( n==2 ) return dis( p[0], p[1] );
    int u, nu, v, nv, k; double ret = 0;
    p[n] = p[0];
    for( u=0,v=1;  u<n;  u=nu )
    {
        nu = u+1;
        while(1) {
            nv = (v+1)%n;
            k = dcmp(  (p[nu].x-p[u].x) * (p[nv].y-p[v].y)
                     - (p[nv].x-p[v].x) * (p[nu].y-p[u].y) );
            if( k<=0 ) break;
            v=nv;           
        }               
        ret = max( ret, dis(p[u],p[v]) ); 
        if( k==0 ) ret = max( ret, dis(p[u],p[nv]) );
    }
    return ret;
}
\end{lstlisting}