\subsection*{Crossing of $|P-P_0|=r$ and $ax+by+c=0$ }
\begin{lstlisting}
int CircleCrossLine_1( CPoint p0, double r, 
    double a, double b, double c, CPoint &cp1, CPoint &cp2)
{
    double aa = a * a, bb = b * b, s = aa + bb;
    double d = r*r*s - sqr(a*p0.x+b*p0.y+c);
    if( d+eps<0 ) return 0; 
    if( d<eps ) d = 0; else d = sqrt( d );
    double ab = a * b, bd = b * d, ad = a * d;
    double xx = bb * p0.x - ab * p0.y - a * c;
    double yy = aa * p0.y - ab * p0.x - b * c;
    cp2.x = ( xx + bd ) / s;  cp2.y = ( yy - ad ) / s;
    cp1.x = ( xx - bd ) / s;  cp1.y = ( yy + ad ) / s;
    if( d>eps ) return 2; else return 1;
}
\end{lstlisting}
\newpage
\subsection*{Crossing of $|P-P_0|=r$ and $\overrightarrow{P_1P_2}$ }
\begin{lstlisting}
int CircleCrossLine_2( CPoint p0, double r, 
                CPoint p1, CPoint p2, CPoint &cp1, CPoint &cp2)
{
    double d, d12, dx, dy;
    d = fabs(PointToLine( p0, p1, p2, cp1 ));    
    if( dcmp(d-r) >0 ) return 0;                 
    if( dcmp(d-r)==0 ) { cp2 = cp1; return 1; }  
    d = sqrt( r*r - d*d ) / dis( p1, p2 );       
    dx = ( p2.x - p1.x ) * d;                    
    dy = ( p2.y - p1.y ) * d;                    
    cp2.x = cp1.x + dx;  cp2.y = cp1.y + dy;     
    cp1.x = cp1.x - dx;  cp1.y = cp1.y - dy;     
    return 2;
}
\end{lstlisting}

\subsection*{Crossing of $|P-P_1|=r_1$ and $|P-P_2|=r_2$ }
\begin{lstlisting}
int CircleCrossCircle_1( CPoint p1, double r1, CPoint p2, double r2, 
        CPoint &cp1, CPoint &cp2 )
{
    double mx = p2.x-p1.x, sx = p2.x+p1.x, mx2 = mx*mx;
    double my = p2.y-p1.y, sy = p2.y+p1.y, my2 = my*my;
    double sq = mx2 + my2, d = -(sq-sqr(r1-r2))*(sq-sqr(r1+r2));
    if( d+eps<0 ) return 0; if( d<eps ) d = 0; else d = sqrt(d);
    double x = mx*( (r1+r2)*(r1-r2) + mx*sx ) + sx*my2;
    double y = my*( (r1+r2)*(r1-r2) + my*sy ) + sy*mx2;
    double dx = mx*d, dy = my*d;  sq *= 2;
    cp1.x = ( x - dy ) / sq;  cp1.y = ( y + dx ) / sq;
    cp2.x = ( x + dy ) / sq;  cp2.y = ( y - dx ) / sq;
    if( d>eps ) return 2; else return 1;
}
\end{lstlisting}

\subsection*{Crossing of $|P-P_1|=r_1$ and $|P-P_2|=r_2$ }
\begin{lstlisting}
int CircleCrossCircle_2( CPoint p1, double r1, CPoint p2, double r2, 
        CPoint &cp1, CPoint &cp2 )
{
    double a, b, c; CommonAxis( p1, r1, p2, r2, a, b, c);
    return CircleCrossLine_1( p1, r1, a, b, c, cp1, cp2);
}
\end{lstlisting}

\subsection*{Common Axis of $|P-P_1|=r_1$ and $|P-P_2|=r_2$ of the $ax+by+c=0$ form}
\begin{lstlisting}
void CommonAxis(CPoint p1, double r1, CPoint p2, double r2,
                           double &a, double &b, double &c )
{
    double sx = p2.x + p1.x, mx = p2.x - p1.x;
    double sy = p2.y + p1.y, my = p2.y - p1.y;  
    a = 2*mx; b = 2*my; c = - sx*mx - sy*my - (r1+r2)*(r1-r2);   
}
\end{lstlisting}
