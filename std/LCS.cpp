\subsection*{$O(N\log N)$, using Suffix Sort with LCP information}
\begin{lstlisting}
int LCS(char *s1, int l1, char *s2, int l2, int &i1, int &i2)
{
    strcpy(s, s1);       s[l1]='$';
    strcpy(s+l1+1, s2);  n=l1+l2+1;
    SuffixSort();        GetHeight();   // s[l1]=0;
    int i, j, l=0; i1 = i2 = 0;
    for(i=1; i<n; i++)
    {
        if( height[i]>=l && id[i-1]<l1 && id[i]>l1 )
            { l = height[i]; i1 = id[i-1];  i2 = id[i]-l1-1; }
        if( height[i]>=l && id[i]<l1 && id[i-1]>l1 )
            { l = height[i]; i1 = id[i];  i2 = id[i-1]-l1-1; }          
    }
    return l;
}
\end{lstlisting}
\subsection*{$O(N^2)$, using KMP}
\begin{lstlisting}
int LCS(char *s1, int l1, char *s2, int l2, int &ansi, int &ansj)
{
    int i,j,k,l,ans=0; ansi=0; ansj=0;
    for(i=0; i<l1-ans; i++)
    {
        makefail( s1+i, l1-i );
        kmp( s2, l2, s1+i, l1-i, 0, l, j);
        if(l>ans) { ans=l; ansi=i; ansj=j; }
    }
    return ans;
}
\end{lstlisting}
\subsection*{Example Part}
\begin{lstlisting}
char s1[maxlen],s2[maxlen]; int l1,l2;

int main()
{
    ifstream cin("input.txt");
    cin>>s1>>s2; l1=strlen(s1); l2=strlen(s2);
    int i1,i2,i,l = LCS(s1,l1,s2,l2,i1,i2);
    cout<<l<<" "<<i1<<" "<<i2<<endl;
    for(i=0;i<l;i++) cout<<s1[i1+i]; cout<<endl;
    for(i=0;i<l;i++) cout<<s2[i2+i]; cout<<endl;    
    return 0;
}
\end{lstlisting}

\subsection*{$M^{th}$ Longest Common Substring}
\begin{lstlisting}
#define h next // h[i] = Longest Common Substring of s1+0 and s2+i
int mk[maxn];  // already found a common substring = s2[i..mk[i])
struct CAnswer{ int pos,len; } ans[maxn];

bool newcmp(const CAnswer &a, const CAnswer &b)
{
    if(a.len != b.len ) return a.len>b.len;
    return a.pos<b.pos;     
}
\end{lstlisting}
\newpage
\begin{lstlisting}
void LCS(char *s1, int l1, char *s2, int l2,int m)
{
    strcpy(s, s1);       s[l1]='$';
    strcpy(s+l1+1, s2);  n=l1+l2+1;
    SuffixSort();        GetHeight();   // s[l1]=0;
    int i, j, k, p, u, v;   
    // computing longest common prefix between s1+0 and s2+i     
    memset(h,0,sizeof(h)); 
    for(i=0; i<n; i++) if( i<n-1 && id[i]<l1 && id[i+1]>l1 ) {      
        k=maxlen;
        for(j=i+1; j<n; j++) 
            { if(id[j]<l1) break; if(height[j]<k) k=height[j]; h[j]=k; }
        i=j-1;
    }   
    for(i=n-1; i>0; i--) if( id[i]<l1 && id[i-1]>l1) {
        k=maxlen;
        for(j=i-1; j>=0; j--) {
            if(id[j]<l1) break; if(height[j+1]<k) k=height[j+1];
            if(k>h[j]) h[j]=k;
        }
        i=j+1;
    }
    num=0;  // Collect Non-Position-Covering Answer
    for(i=0;i<n;i++)
        if( h[rank[i]]!=0 && (i==0 || h[rank[i-1]]<=h[rank[i]]) ) 
            { k=rank[i]; ans[num].pos=id[k]; ans[num].len=h[k]; num++;}
    std::sort(ans,ans+num,newcmp);  
    memset(mk,0,sizeof(mk));
    for(i=j=0; i<num && j<m; i++) {
        k=rank[ans[i].pos];  // Check Non-Substring-Covering 
        if( mk[k]>=h[k] ) continue;
        int ok=1;
        for(u=maxlen, p=k+1; p<n; p++) {
            if( height[p]<u ) u=height[p];
            if(u<h[k]) break;
            if(mk[p]>=h[k]) { ok=0; break; }
        }
        if(!ok) continue;
        for(u=maxlen,p=k-1; p>=0; p--) {
            if( height[p+1]<u ) u=height[p+1];
            if(u<h[k]) break;
            if(mk[p]>=h[k]) { ok=0; break; }            
        }
        if(!ok) continue;       
        j++; // Check Passed, Set Already Found Substring
        for(v=0; v<h[k]; v++)
            if( mk[rank[id[k]+v]] < h[k]-v ) mk[rank[id[k]+v]] = h[k]-v;
        // LENGTH h[rank[ans[i].pos]] POSITION ans[i].pos-l1-1
        char ch = s[ans[i].pos + h[rank[ans[i].pos]]];
        s[ans[i].pos + h[rank[ans[i].pos]]] = 0;
        cout << s+ans[i].pos << endl;
        s[ans[i].pos + h[rank[ans[i].pos]]] = ch;
    }
}
\end{lstlisting}