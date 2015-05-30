\begin{lstlisting}
typedef struct { int x, y; } point;

int cmp(const void* e1, const void* e2) {
   const point* p1 = (const point*)e1;
   const point* p2 = (const point*)e2;
   if (p1->x != p2->x) return p1->x - p2->x;
   return p1->y - p2->y;
}

int n;
point p[MAX];

void initialize() {
   int i;
   for (scanf("%d", &n), i = 1; i <= n; i++)
      scanf("%d%d", &p[i].x, &p[i].y);

   qsort(&p[1], n, sizeof(point), cmp);
   p[0].x = p[0].y = 0;
}

int deg[MAX] = {0}, queue[MAX];
int maxlevel, level[MAX] = {0};
int left[MAX] = {0}, right[MAX] = {0}, mark[MAX] = {0};

\end{lstlisting}
\newpage
\begin{lstlisting}
void local_chain() {
   int i, j;
   for (i = 1; i <= n; i++)
      for (j = i + 1; j <= n; j++)
         if (p[i].y <= p[j].y)
            deg[i]++;
            
   for (queue[0] = 0, i = 1; i <= n; i++)
      if (deg[i] == 0)
         queue[++queue[0]] = i;    
   for (i = 1, maxlevel = -1; i <= queue[0]; i++)
      for (j = 1; j < queue[i]; j++)
         if (p[j].y <= p[queue[i]].y)
            if (--deg[j] == 0) {
               queue[++queue[0]] = j, level[j] = level[queue[i]] + 1;
               if (level[j] > maxlevel) maxlevel = level[j];
            }
   for (maxlevel++, i = 1; i <= n; i++)
      level[i] = maxlevel - level[i];
   
   for (mark[0] = n + 1, i = 1; i <= n; i++) {
      for (j = 0; j < i; j++)
         if (mark[j] && level[j] == level[i] - 1 && p[j].y <= p[i].y)
            break;
      if (j < i) {
         if (left[level[i]] == 0) left[level[i]] = i, mark[i] = n + 1;
         mark[right[level[i]]]--;
         mark[right[level[i]] = i]++;
      }
   }
}

int index[MAX], value[MAX] = {0}, levvalue[MAX];

int index_cmp(const void* e1, const void* e2) {
   return level[*(const int*)e1] - level[*(const int*)e2];
}

void calc_value() {
   int q, i, j, lev;
   for (i = 1; i <= n; i++)
      index[i] = i;
   qsort(index, n, sizeof(int), index_cmp);
   
   for (q = 1; q <= n; q++) {
      lev = level[i = index[q]];
      
      if (left[lev] == i && right[lev] == i)
         value[i] = levvalue[lev - 1] + 1;
      else if (left[lev] == i || right[lev] == i)
         value[i] = levvalue[lev - 1] + 2;
      else 
         for (j = 0; j < i; j++) {
            if (mark[j]) value[j] = levvalue[level[j]];
            if (p[j].y <= p[i].y && value[j] + level[i] - level[j] + 1 > value[i])
               value[i] = value[j] + level[i] - level[j] + 1;
         }
       
      if (value[i] > levvalue[lev])
         levvalue[lev] = value[i];
   }
}

void put_answer() {
   int i, max = 0;
   for (i = 1; i <= n; i++)
      if (value[i] > max)
         max = value[i];
   printf("%d\n", max);
}

void main() {
   initialize();
   local_chain();
   calc_value();
   put_answer();
}
\end{lstlisting}
