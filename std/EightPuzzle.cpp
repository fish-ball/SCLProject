Input: $012345678$\quad $123456780$ Output: $STEP=22$
\subsection*{Common Part}
\begin{lstlisting}
#define maxlen 10
#define size 362880+1

const int link[9][5]={ {2,1,3}, {3,0,2,4}, {2,1,5}, {3,0,4,6},
    {4,1,3,5,7}, {3,2,4,8}, {2,3,7}, {3,4,6,8}, {2,5,6} };

int s[maxlen],p[maxlen],mk[size],open[size],cur,tail;

void encode(int *s,int len,int &x)
{
    int i,j,k,l; for(x=0,i=len-1; i>=0; x+=k*p[i--])
    for(k=s[i],j=i+1; j<len; j++) if(s[j]<s[i]) k--;
}

void decode(int *s,int len,int x)
{
    int i,j,k,l; for(i=len-1; i>=0; i--){ s[i]=x/p[i]; x%=p[i]; }
    for(i=0; i<len; i++) for(j=0; j<i; j++) if(s[j]>=s[i]) s[j]++;
}

void print(int *s,int len)
{
	for(int i=0;i<len;i++)
		cout<<s[i];
	cout<<endl;
}
\end{lstlisting}
\newpage
\begin{lstlisting}
int main()
{
    ifstream cin("input.txt");
    char ch; int i,src,dst;
    for(p[0]=i=1; i<maxlen; i++) p[i]=p[i-1]*i;
    for(i=0;i<9;i++) { cin>>ch; s[i]=ch-'0'; } encode(s,9,src);
    for(i=0;i<9;i++) { cin>>ch; s[i]=ch-'0'; } encode(s,9,dst);
    solve(src,dst); cout<<cur<<" "<<tail<<endl;
    return 0;
}
\end{lstlisting}
\subsection*{ Simple Breadth First Search }
\begin{lstlisting}
void output(int pos,int num)
{
    if(pos==1) cout<<"Total number of steps = "<<num<<endl;
        else output(mk[open[pos]],num+1);
    decode(s,9,open[pos]); print(s,9);  
}

void solve(int src,int dst)
{
    int i,j,k,x,l,ps;
    if(src==dst){ cout<<"SRC DST is the same!"<<endl; return; }
    cur=0; tail=1; open[1]=src; mk[src]=1;
    while(++cur<=tail){
        decode(s,9,open[cur]); for(ps=0; s[ps]; ps++);
        for(k=1; k<=link[ps][0]; k++) {
            std::swap(s[ps],s[link[ps][k]]); encode(s,9,x);
            if(!mk[x]){
                mk[x]=cur; open[++tail]=x;
                if(x==dst) { output(tail,0); return; }
            }
            std::swap(s[ps],s[link[ps][k]]);
        }
    }   
    cout<<"No solution!"<<endl; 
}
\end{lstlisting}
\subsection*{ Heuristic Breadth First Search }
\begin{lstlisting}
int d[size],heap[size],hlen,h[size],dsts[maxlen];
int cmp(const int &i,const int &j){ return h[i]>h[j]; }

void calch(int pos)
{
    int i,j,k;  h[pos]=d[pos];
    for(i=0;i<9;i++) if(s[i]!=dsts[i]) h[pos]++;
}

void output(int pos,int num)
{
    if(pos==1) cout<<"Total number of steps = "<<num<<endl;
        else output(mk[open[pos]],num+1);
    decode(s,9,open[pos]); print(s,9);  
}
\end{lstlisting}
\newpage
\begin{lstlisting}
void solve(int src,int dst)
{
    int i,j,k,x,l,ps;
    if(src==dst){ cout<<"SRC DST is the same!"<<endl; return; }
    tail=1; open[1]=src; mk[src]=1; hlen=1; heap[0]=1; d[1]=0;
    decode(s,9,src); decode(dsts,9,dst); calch(1);
    while(hlen>0){
        cur=heap[0]; std::pop_heap(heap,heap+(hlen--),cmp);
        decode(s,9,open[cur]); for(ps=0; s[ps]; ps++);
        for(k=1; k<=link[ps][0]; k++) {
            std::swap(s[ps],s[link[ps][k]]); encode(s,9,x);
            if(!mk[x]){ 
                mk[x]=cur; open[++tail]=x; d[tail]=d[cur]+1; calch(tail);
                heap[hlen++]=tail; std::push_heap(heap,heap+hlen,cmp);
                if(x==dst) { output(tail,0); return; }
            }
            std::swap(s[ps],s[link[ps][k]]);
        }
    }   
    cout<<"No solution!"<<endl; 
}
\end{lstlisting}
\subsection*{ Double Breadth First Search }
\begin{lstlisting}
int step,di[size];

void out1(int pos)
{
    if(pos>2) out1(mk[open[pos]]); step++;
    decode(s,9,open[pos]); print(s,9);  
}

void out2(int pos)
{
    decode(s,9,open[pos]); print(s,9);  
    if(pos>2) out2(mk[open[pos]]); step++;  
}

void solve(int src,int dst)
{
    int i,j,k,x,l,ps;
    if(src==dst){ cout<<"SRC DST is the same!"<<endl; return; }
    open[1]=src; mk[src]=1; di[src]=1; cur=0;
    open[2]=dst; mk[dst]=2; di[dst]=2; tail=2;
    while(++cur<=tail){
        decode(s,9,open[cur]); for(ps=0; s[ps]; ps++);
        for(k=1; k<=link[ps][0]; k++) {
            std::swap(s[ps],s[link[ps][k]]); encode(s,9,x);
            if(!mk[x]){ mk[x]=cur; open[++tail]=x; di[x]=di[open[cur]]; }
                else if(di[x]!=di[open[cur]]){
                    step=0;
                    if(di[x]==1) { out1(mk[x]); out2(cur); }
                        else     { out1(cur);   out2(mk[x]); }
                    cout<<"Total number of steps = "<<step<<endl;
                    return;
                }
            std::swap(s[ps],s[link[ps][k]]);
        }
    }   
    cout<<"No solution!"<<endl; 
}
\end{lstlisting}
