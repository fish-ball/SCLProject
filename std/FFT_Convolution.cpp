$r_k = \sum_{i=0}^{n-1} a[i]*b[i-k]$
\begin{lstlisting}
void Convolution1(int *a,int *b,int *c,int n)
{
    int m,i,j,*rb=new int[n]; rb[0]=b[0];
    for(i=1;i<n;i++) rb[i]=b[n-i];
    PolyMulti1(a,n,rb,n,c,m);
    for(i=0;i<n;i++) c[i]+=c[i+n];  
    delete[] rb;
}

\\ N must be power of 2
void Convolution2(int *a,int *b,int *c,int n)
{
    int i,j;
    cp *x=new cp[n], *ya=new cp[n], *yb=new cp[n], *yc=new cp[n];
    x[0]=b[0];
    for(i=1;i<n;i++) x[i]=(i<n)?b[n-i]:0;   fft(x,n,yb,0);
    for(i=0;i<n;i++) x[i]=(i<n)?a[i  ]:0;   fft(x,n,ya,0); 
    for(i=0;i<n;i++) yc[i]=ya[i]*yb[i];     fft(yc,n,x,1);
    for(i=0;i<n;i++) c[i]=int(x[i].real()/n+0.5);
    delete x; delete ya; delete yb; delete yc;
}
\end{lstlisting}