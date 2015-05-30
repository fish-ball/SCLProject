\begin{lstlisting}
const double eps=1e-8;
const double pi=acos(-1.0);

#define cp complex<double>

inline int max(int a,int b){ if(a>b) return a; else return b; }
inline int dcmp(double a){ if(a<-eps) return -1; return (a>eps); }

void fft(cp *x,int n,cp *y,int bInv) // y=Wx,  w[j,k]=e^ijk
{
    if(n==1) { y[0] = x[0]; return; }
    cp *xeven = new cp[n/2], *xodd = new cp[n/2], w(1,0),
       *yeven = new cp[n/2], *yodd = new cp[n/2], wn; int i;
    if(bInv) wn=cp( cos(-2*pi/n), sin(-2*pi/n) ); 
        else wn=cp( cos( 2*pi/n), sin( 2*pi/n) );
    for(i=0; i<n/2; i++)
    {
        xeven[i] = x[i*2  ];
        xodd [i] = x[i*2+1];
    }
    fft(xeven, n/2, yeven, bInv);
    fft(xodd , n/2, yodd , bInv);
    for(i=0; i<n/2; i++)
    {
        y[i    ] = yeven[i] + w*yodd[i];
        y[i+n/2] = yeven[i] - w*yodd[i];
        w *= wn;
    }
    delete xeven; delete yeven; delete xodd; delete yodd;
}
\end{lstlisting}