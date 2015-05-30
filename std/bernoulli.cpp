Note: \emph{fraction.h} contains a \emph{Fraction Class} (Section \ref{fraction_class} on Page \pageref{fraction_class})
\begin{lstlisting}
#include<fraction.h>

Fraction a[22];
int c[22][22];

int main()
{
    int i,j,k,m;
    c[0][0] = 1;
    for (i=1;i<=21;i++) {
        c[i][0] = 1; c[i][i] = 1;
        for (j=1;j<i;j++) c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
    a[0] = 0;
    while( cin>>k ) {
        a[k+1] = Fraction(1,k+1);  m = k+1;
        for (i=k;i>=1;i--) {
            a[i] = 0;
            for (j=i+1;j<=k+1;j++)
                if ((j-i+1)%2==0) a[i] = a[i]+a[j]*c[j][j-i+1];
                    else a[i] = a[i]-a[j]*c[j][j-i+1];
            a[i] = a[i] * Fraction(1,i);
            m = lcm(m,a[i].get_denominator());
        }
        cout << m << ' ';
        for (i=k+1;i>0;i--) cout << a[i] * m<< ' ';
        cout << 0 << endl;
    }
    return 0;
}
\end{lstlisting}
