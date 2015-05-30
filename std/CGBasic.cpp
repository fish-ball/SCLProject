\begin{lstlisting}
const double eps = 1e-8;
const double pi  = acos(-1.0);

struct CPoint{ double x,y; };

double min(double x,double y){ if( x<y ) return x; else return y; }

double max(double x,double y){ if( x>y ) return x; else return y; }

double sqr(double x){ return x*x; }

int dcmp(double x)
{
    if(x<-eps) return -1; else return (x>eps);
}

double cross(CPoint p0,CPoint p1,CPoint p2)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

double dot(CPoint p0,CPoint p1,CPoint p2)
{
    return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}

double dissqr(CPoint p1,CPoint p2)
{
    return sqr(p1.x-p2.x)+sqr(p1.y-p2.y);
}

double dis(CPoint p1,CPoint p2)
{
    return sqrt(sqr(p1.x-p2.x)+sqr(p1.y-p2.y));
}

int PointEqual(const CPoint &p1,const CPoint &p2)
{
    return dcmp(p1.x-p2.x)==0 && dcmp(p1.y-p2.y)==0;
}
\end{lstlisting}
