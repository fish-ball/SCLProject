\subsection*{Smart Edition}
\begin{lstlisting}
const int ff[10] = {1, 1, 2, 6, 4, 4, 4, 8, 4, 6 };

int fact(int n)
{
    int i,x;
    if(n<5) return ff[n];
    x = ( ff[n%10] * 6 ) %10;
    for( i=1; i<=(n/5)%4; i++)
        if( x==6 || x==2 ) x=(x+10)/2; else x/=2;
    return ( fact(n/5) * x ) % 10;
}
\end{lstlisting}
\subsection*{High Precision Edition}
\begin{lstlisting}
int a[10] = {6,1,2,6,4,4,4,8,4,6};
int b[ 4] = {1,8,4,2};

void divide(char s[],int &len)
{
    int i;
    char temp[200];
    for(i=0; i<len; i++) temp[i] = s[i]*2; temp[len] = 0;
    for(i=0; i<len; i++) if ( temp[i]>9 ){ temp[i]-=10; temp[i+1]++; }
    for(i=0; i<len; i++) s[i] = temp[i+1];
    if( temp[len]==0 ) len--;
}

int fact(char s[])
{
    int resulent=1,power=0,len=strlen(s),i;
    char temp;
    if (len==1&&s[0]=='0') return 1;
    for(i=0;i<len;i++) s[i]-='0';
    for(i=0;i<len/2;i++){ temp=s[i]; s[i]=s[len-1-i]; s[len-1-i]=temp; }
    while(len){
        resulent=resulent*a[s[0]%10]%10;
        divide(s,len);
        power+=(s[1]*10+s[0])%4;
    }
    resulent=resulent*b[power%4]%10;
    return resulent;
}
\end{lstlisting}
