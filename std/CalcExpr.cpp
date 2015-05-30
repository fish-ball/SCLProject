\begin{lstlisting}
char expr[MAX+1]; int next[MAX],stack[MAX],top;
double calc(int L, int R);

void prefix() {
    int i; top=-1;
    for ( i=0; expr[i]; ++i ) {
        next[i]=-1;
        if ( expr[i]=='(' ) stack[++top]=i;
        else if ( expr[i]==')' ) next[stack[top--]]=i;
    }
}
\end{lstlisting}
\newpage
\begin{lstlisting}
double getnum(int &L) {
    double res = 0;
    if ( expr[L]=='(' ) { res=calc(L+1, next[L]-1); L=next[L]+1; }
        else while ( isdigit(expr[L]) ) res=res*10+expr[L++]-'0';
    return res;
}

void process(double &a, double b, char op) {
    switch ( op ) {
        case '+': a += b; break;
        case '-': a -= b; break;
        case '*': a *= b; break;
        default : a /= b;
    }
}

double calc(int L, int R) {
    double a, b, c;
    char op1, op2;  
    if ( next[L] == R ) return calc(L+1, R-1);  
    a = 0; op1 =( expr[L]=='-' ? '-' : '+' );
    L = ( expr[L]=='+' || expr[L]=='-' ? L+1 : L );
    for( b = getnum(L); L<R ; ) {
        op2=expr[L++]; c=getnum(L);
        if ( op2=='+' || op2=='-' || op1=='*' || op1=='/' ) {
            process(a, b, op1); b=c; op1=op2;
        } else process(b, c, op2);
    }
    process(a, b, op1);
    return a;
}

void main() {
    scanf("%s", expr); prefix();
    printf("%.10lf\n", calc(0, strlen(expr)));
}
\end{lstlisting}