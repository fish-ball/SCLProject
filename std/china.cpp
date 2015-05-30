\qquad$extended\_euclid(a,b)=ax+by$
\begin{lstlisting}
int extended_euclid(int a,int b,int &x,int &y)
{
    if (b==0){ x=1,y=0; return a; } else {
        int res=extended_euclid(b,a%b,x,y);
        int t=x; x=y; y=t-(a/b)*y;
        return res;
    }
}
\end{lstlisting}

$ax \equiv  b$ (mod $n$) , $n>0$ 
\begin{lstlisting}
void modular_linear_equation_solver(int a,int b,int n)
{
    int d,x,y,e,i;
    d=extended_euclid(a,n,x,y);
    if (b%d!=0) cout<<"No answer!"; else {
        e=x*(b/d)%n;    // x=e is a basic solution
        for(i=0;i<d;i++) cout<<(e+i*(n/d))%n<<endl;
    }
}
\end{lstlisting}

Given $b_i$ , $w_i$ , $i=0\cdots len-1$ which $w_i>0$ , $i=0\cdots len-1$ and $(w_i,w_j)=1$ , $i\not = j$ 
\\Find an $x$ which satisfies: $ x \equiv b_i$ (mod $w_i$), $i=0\cdots len-1$

\begin{lstlisting}
int china(int b[],int w[],int len)
{
    int i,d,x,y,x,m,n;
    x=0; n=1; for(i=0;i<len;i++) n*=w[i];
    for(i=0;i<len;i++){
        m=n/w[i];
        d=extended_euclid(w[i],m,x,y);
        x=(x+y*m*b[i])%n;
    }
    return (n+x%n)%n;
}
\end{lstlisting}
