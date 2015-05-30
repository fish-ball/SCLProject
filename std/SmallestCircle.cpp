\subsection*{$O(N^3)$, compute Convex Hull first! or it will be quite slow!}
\begin{lstlisting}
double GetCos(CPoint p0,CPoint p1,CPoint p2)
{ return dot(p0,p1,p2)/dis(p0,p1)/dis(p0,p2); }

int allin(CPoint p[],int n,int i,int j,int k)
{
    for(int l=0; l<n; l++) if(l!=i && l!=j && l!=k) {
        if( (cross(p[i],p[j],p[k])>0)^(cross(p[i],p[j],p[l])>0) &&
          dcmp(GetCos(p[k],p[i],p[j])+GetCos(p[l],p[i],p[j]))>0) return 0;          
        if( (cross(p[j],p[k],p[i])>0)^(cross(p[j],p[k],p[l])>0) &&
          dcmp(GetCos(p[i],p[k],p[j])+GetCos(p[l],p[k],p[j]))>0) return 0;          
        if( (cross(p[i],p[j],p[k])>0)^(cross(p[i],p[l],p[k])>0) &&
          dcmp(GetCos(p[j],p[k],p[i])+GetCos(p[l],p[k],p[i]))>0) return 0;
    }
    return 1;
}

double SmallestEnclosingCircle(CPoint p[],int n,CPoint &cp)
{   
    int i,j,k; double di,cos1,cos2,co,si,r=0;
    if( n == 1 ) { cp = p[0]; return 0; }
    if( n == 2 ) 
    { 
        cp.x = ( p[0].x + p[1].x )/2; 
        cp.y = ( p[0].y + p[1].y )/2;
        return dis(p[0],p[1])/2;
    }
    for(i=0; i<n; i++) for(j=i+1; j<n; j++)
    {
        di = dis(p[i],p[j]);  cos1 = cos2 = -2;
        if( dcmp(di-r*2)>0 ) r = di/2;
        for(k=0; k<n; k++) if( k!=i && k!=j ) 
        {
            co = GetCos(p[k],p[i],p[j]);
            if( dcmp(cross(p[i],p[j],p[k]))>0 )
                { if( co>cos1 ) cos1=co; }
            else  if( co>cos2 ) cos2=co;
        }
        if( dcmp(cos1)<=0 && dcmp(cos2)<=0 ) 
        {
            cp.x = ( p[i].x + p[j].x )/2; 
            cp.y = ( p[i].y + p[j].y )/2;
            return di/2;
        }
    }
    r = 1e30;
    for(i=0; i<n; i++) for(j=i+1; j<n; j++) {
        di = dis( p[i], p[j] );
        for(k=j+1; k<n; k++) {
            co = GetCos( p[k], p[j], p[i] );
            si = sqrt(1-sqr(co));
            if( dcmp(di/si/2-r)<0 && allin(p,n,i,j,k) ) {
                r=di/si/2;
                GetCircleCenter(p[i],p[j],p[k],cp);
            }
        }
    }
    return r;
}
\end{lstlisting}