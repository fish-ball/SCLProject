\begin{lstlisting}
#define maxlen 100
#define maxsize 1000000
#define DataType int

char tree[maxsize],s[maxlen];
int son[maxsize],bro[maxsize],num,k,n;
DataType data[maxsize];

DataType find(const char*s)
{
    int i,j=0;
    for(i=0;s[i];i++) {
        j=son[j];
        while(j && tree[j]!=s[i]) j=bro[j];
        if(!j) return -1;
    }
    return data[j];
}

void add(const char*s,DataType x)
{
    int i,j=0,p;
    for(i=0;s[i];i++) {
        p=j;  j=son[j]; 
        while(j && tree[j]!=s[i]) j=bro[j];
        if(!j) { 
            tree[++num]=s[i]; son[num]=0;
            bro[num]=son[p];  son[p]=num;
            data[num]=-1;     j=num;
        }       
    }
    data[j]=x;
}

void init()
{ num=0; bro[num]=0; son[num]=0; data[0]=-1; }
\end{lstlisting}