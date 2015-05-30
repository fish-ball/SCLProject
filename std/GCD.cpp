\begin{lstlisting}
void gcd(int a,int b,int &d,int &x,int &y)
{
    if( b==0 ){ d=a; x=1; y=0; return; }
    gcd( b, a%b, d, y, x );
    y -= x * (a/b);
}
\end{lstlisting}
