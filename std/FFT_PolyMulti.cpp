\begin{lstlisting}
void PolyMulti(double *a,int na,double *b,int nb,double *c,int &nc)
{
    int i,j,n=(na>nb)?na:nb;
    n=1<<((int)ceil(log(2*n)/log(2)-eps));
    cp *x=new cp[n], *ya=new cp[n], *yb=new cp[n], *yc=new cp[n];
    for(i=0;i<n;i++) x[i]=(i<na)?a[i]:0;    fft(x,n,ya,0); 
    for(i=0;i<n;i++) x[i]=(i<nb)?b[i]:0;    fft(x,n,yb,0);
    for(i=0;i<n;i++) yc[i]=ya[i]*yb[i];     fft(yc,n,x,1);
    for(i=0;i<n;i++) c[i]=x[i].real()/n;
    for(nc=n; nc>0 && dcmp(c[nc-1])==0; nc--);
    delete x; delete ya; delete yb; delete yc;
}
\end{lstlisting}