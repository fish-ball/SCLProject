\begin{lstlisting}
// INPUT: (242, 89), (212, 185), (71, 128), OUTPUT: (158.0885, 115.4652)
void Circumcenter(CPoint p0,CPoint p1,CPoint p2,CPoint &cp)
{
    double a1=p1.x-p0.x, b1=p1.y-p0.y, c1=(sqr(a1)+sqr(b1))/2 ;
    double a2=p2.x-p0.x, b2=p2.y-p0.y, c2=(sqr(a2)+sqr(b2))/2 ; 
    double d = a1 * b2 - a2 * b1;
    cp.x = p0.x + (c1*b2 - c2*b1) / d;
    cp.y = p0.y + (a1*c2 - a2*c1) / d;
}
\end{lstlisting}

\begin{lstlisting}
// INPUT: (242, 89), (212, 185), (71, 128), OUTPUT: (189.5286, 137.4987)
double Incenter(CPoint A, CPoint B, CPoint C, CPoint &cp)
{
    double s, p , r, a, b, c;
    a = dis(B, C), b = dis(C, A), c = dis(A, B); p = ( a + b + c ) / 2; 
    s = sqrt( p * (p-a) * (p-b) * (p-c) );       r = s / p;
    cp.x = ( a*A.x + b*B.x + c*C.x ) / ( a + b + c );
    cp.y = ( a*A.y + b*B.y + c*C.y ) / ( a + b + c );
    return r;   
}
\end{lstlisting}

\begin{lstlisting}
// INPUT: (242, 89), (212, 185), (71, 128), OUTPUT: (208.8229, 171.0697)
void Orthocenter(CPoint A, CPoint B, CPoint C, CPoint &cp)
{
    Circumcenter(A, B, C, cp);
    cp.x = A.x + B.x + C.x - 2 * cp.x;
    cp.y = A.y + B.y + C.y - 2 * cp.y;
}
\end{lstlisting}

\subsection*{Find three numbers $r,s,t$ which make $P=rA+sB+tC$ and $r+s+t=1$}
\begin{lstlisting}
void Parametric( CPoint P, CPoint A , CPoint B , CPoint C ,
                           double &r, double &s, double &t )
{
    double d;
    d = cross( A, B, C);
    r = cross( P, B, C) / d;
    s = cross( A, P, C) / d;
    t = cross( A, B, P) / d;
}
\end{lstlisting}

\begin{lstlisting}
void PolygonCentroids(CPoint p[], int n, CPoint &cp)
{
    double sum=0, s=0; cp.x=0; cp.y=0;
    for( int i=1; i<n-1; i++,sum+=s )
    {
        s= cross( p[0], p[i], p[i+1] );
        cp.x += s*( p[0].x + p[i].x + p[i+1].x );
        cp.y += s*( p[0].y + p[i].y + p[i+1].y );
    }       
    cp.x/=sum*3; cp.y/=sum*3;
}
\end{lstlisting}
