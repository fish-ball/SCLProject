\begin{lstlisting}
#define for if(0); else for
const double pi = acos(-1.0);
const int MFB = 16;
int **bt = 0;

struct cp { double re,im;} ;

inline int ReverseBits(int index, int bitnum) {
    int ret = 0;
    for(int i=0; i<bitnum; ++i, index >>= 1) 
        ret = (ret << 1) | (index & 1);
    return ret;
}
\end{lstlisting}
\newpage
\begin{lstlisting}
void InitFFT() {
    bt = new int *[MFB]; int i,j,length;
    for(i=1, length=2; i<=MFB; ++i, length<<=1) {
        bt[i-1] = new int[length];
        for(j=0; j<length; ++j) bt[i-1][j] = ReverseBits(j, i);
    }
}

inline int FRB(int i, int bitnum) {
    return bitnum <= MFB ? bt[bitnum - 1][i] : ReverseBits(i, bitnum);
}

void FFT(cp *in, cp *out,int n,bool bInv)
{
    int i, j, k, ed, len, bitnum=0;  if(!bt) InitFFT();
    while( !((1<<bitnum)&n) ) bitnum++;
    for(i=0; i<n; ++i) out[FRB(i, bitnum)] = in[i];
    double basicangle = pi * (bInv ? -2 : 2);
    cp a0,a1,a2,a,b;
    for(ed = 1, len = 2; len <= n; len <<= 1) {
        double delta_angle = basicangle / len;
        double sin1 = sin(-delta_angle), sin2 = sin(-delta_angle * 2);
        double cos1 = cos(-delta_angle), cos2 = cos(-delta_angle * 2);
        for(i=0; i<n; i+=len) {
            a1.re=cos1; a1.im=sin1; a2.re=cos2; a2.im=sin2;
            for(j=i, k=0; k<ed; ++j, ++k) {
                a0.re=2*cos1*a1.re-a2.re;  a0.im=2*cos1*a1.im-a2.im;
                a2 = a1; a1 = a0; b=out[j+ed];
                a.re = a0.re*b.re - a0.im*b.im;
                a.im = a0.im*b.re + a0.re*b.im;
                out[j+ed].re=out[j].re-a.re;
                out[j+ed].im=out[j].im-a.im;
                out[j].re+=a.re;
                out[j].im+=a.im;
            }
        }
        ed = len;
    }
    if (bInv) for (int i = 0; i < n; ++i) { out[i].re/= n; out[i].im/=n; }
}

// n must be power of 2
void convolution(double *a, double *b,double *r,int n) {
    int i;
    cp *s=new cp[n], *d1=new cp[n], *d2=new cp[n], *y=new cp[n];
    s[0].im=b[0]; s[0].re=0;
    for(i=1; i<n; ++i) s[i].re=b[n-i],s[i].im=0;    FFT(s, d2, n, false);
    for(i=0; i<n; ++i) s[i].re=a[i  ],s[i].im=0;    FFT(s, d1, n, false);
    for(i=0; i<n; ++i) {
        y[i].re = d1[i].re*d2[i].re - d1[i].im*d2[i].im;
        y[i].im = d1[i].re*d2[i].im + d1[i].im*d2[i].re;
    }
    FFT(y, s , n, true);
    for(i=0; i<n; ++i) r[i] = s[i].re;
    delete s; delete d1; delete d2; delete y;
}
\end{lstlisting}