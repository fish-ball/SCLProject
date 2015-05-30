\subsection*{SuffixSort : input $s[0..n)$ , output $id[0..n)$}
\begin{lstlisting}
#define nb next     // "new bucket" overlaid on "next"
#define head height // head is never used when computing height
#define rank b      // after SuffixSort, "rank" overlaid on "bucket"

char s[maxn]; int n, id[maxn], height[maxn], b[maxn], next[maxn]; 

bool cmp(const int &i,const int &j){ return s[i]<s[j]; }

void SuffixSort()
{
    int i,j,k,h;
    for(i=0; i<n; i++) id[i]=i;
    std::sort(id,id+n,cmp);
    for(i=0; i<n; i++) 
        if(i==0 || s[id[i]]!=s[id[i-1]] ) b[id[i]] = i;
            else b[id[i]]=b[id[i-1]]; 
    for(h=1; h<n; h<<=1)
    {
        for(i=0;i<n;i++) head[i]=next[i]=-1;
        for(i=n-1; i>=0; i--) if(id[i]) 
        {
            j = id[i]-h; if( j<0 ) j+=n;
            next[j] = head[b[j]]; head[b[j]] = j;
        }
        j=n-h; next[j] = head[b[j]]; head[b[j]] = j;                
        for(i=k=0; i<n; i++) if( head[i]>=0 )
            for(j=head[i]; j>=0; j=next[j]) id[k++]=j;          
        for(i=0; i<n; i++) if( i>0 && id[i]+h<n && id[i-1]+h<n
            && b[id[i]] == b[id[i-1]] && b[id[i]+h] == b[id[i-1]+h] )
                 nb[id[i]] = nb[id[i-1]]; else nb[id[i]] = i;
        for(i=0; i<n; i++) b[i] = nb[i];
    }
}
\end{lstlisting}
\subsection*{GetHeight : $height[i] = LCP( s[id[i]], s[id[i]-1]$ }
\begin{lstlisting}
void GetHeight() 
{
    int i, j, h; height[0] = 0;
    for(i=0; i<n; i++) rank[ id[i] ] = i;
    for( h=0, i=0; i<n; i++ ) if( rank[i] > 0 )
    {
        j = id[ rank[i] -1 ];
        while( s[i+h] == s[j+h] ) ++h;
        height[ rank[i] ] = h;
        if( h>0 ) --h;
    }
}
\end{lstlisting}