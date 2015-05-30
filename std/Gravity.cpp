\begin{lstlisting}
double Gravity(CPoint a[], int ct, CPoint &pt) // return area
{
    double s=0.0,t; pt.x=pt.y=0;
    for(int i=1; i<ct-1; i++) {
        s += t = cross(a[i], a[i+1],a[0]);
        pt.x += a[0].x*t + a[i].x*t + a[i+1].x*t;
        pt.y += a[0].y*t + a[i].y*t + a[i+1].y*t;
    }
    if(dcmp(s)==0) return 0; else {pt.x /= s*3, pt.y /= s*3;}
    return fabs(s/2);
}
\end{lstlisting}