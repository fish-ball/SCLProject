\begin{lstlisting}
int fail[maxlen];

void makefail( char *t, int lt )
{
    --t;
    for(int i=1,j=0;i<=lt;i++,j++){
        fail[i]=j;
        while(j>0 && t[i]!=t[j]) j=fail[j];
    }
}

// start matching pattern T in S[i..)
// return match pos or longest match length with corresponding pos
int kmp(char *s, int ls, char *t, int lt, int i,int &longest,int &lp)
{
    longest = lp = 0; --s; --t;
    for(int j=1; i<=ls; i++,j++) {  
        while( j>0 && s[i]!=t[j] ) j=fail[j];
        if( j>longest ) { longest = j; lp = i-j; }
        if( j==lt ) return i-lt;        
    }
    return -1;
}
\end{lstlisting}