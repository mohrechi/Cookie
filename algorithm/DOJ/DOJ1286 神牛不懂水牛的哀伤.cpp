#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
static const double PI = acos(-1.0);

//#define DEBUG

#ifdef DEBUG
    #define DEBUG_SHUFFLE
    #define DEBUG_POKER
    #define DEBUG_SUBSEQUENCE
    #define DEBUG_POWER
    #define DEBUG_NUMBER
        #ifdef DEBUG_NUMBER
            #define DEBUG_NUMBER_FIBONACCI
            #define DEBUG_NUMBER_FACTOR
            #define DEBUG_NUMBER_CATALAN
            #define DEBUG_NUMBER_EULER
        #endif
    #define DEBUG_MATRIX
        #ifdef DEBUG_MATRIX
            #define DEBUG_MATRIX_WORK
            #define DEBUG_MATRIX_TRAVEL
        #endif
    #define DEBUG_GRAPH
        #ifdef DEBUG_GRAPH
            #define DEBUG_GRAPH_SPANNING
            #define DEBUG_GRAPH_CUT
        #endif
    #define DEBUG_GEOMETRY
        #ifdef DEBUG_GEOMETRY
            #define DEBUG_GEOMETRY_INTERSECT
            #define DEBUG_GEOMETRY_CONVEX
            #define DEBUG_GEOMETRY_TRANSFORM
        #endif
    #define DEBUG_RANDOM
#endif

class ShuffleMechine
{
public:
    static const int MAXN1 = 100;
    static const int MAXM1 = 10;

    inline int deal()
    {
        int type, a1, b1;
        if(!~scanf("%d%d", &n1, &m1))
        {
            return false;
        }
        init();
        while(m1--)
        {
            scanf("%d", &type);
            switch(type)
            {
                case 1:
                    scanf("%d", &a1);
                    shuffle1(a1);
                    break;
                case 2:
                    scanf("%d%d", &a1, &b1);
                    if(a1 > b1)
                    {
                        std::swap(a1, b1);
                    }
                    shuffle2(a1, b1);
                    break;
                case 3:
                    scanf("%d%d", &a1, &b1);
                    if(a1 > b1)
                    {
                        std::swap(a1, b1);
                    }
                    shuffle3(a1, b1);
                    break;
            }
            #ifdef DEBUG_SHUFFLE
                output();
            #endif
        }
        return true;
    }

    inline int getLength()
    {
        return n1;
    }

    inline int* getResult()
    {
        return a + 1;
    }

private:
    int n1, m1;
    int a[MAXN1];
    int b[MAXN1];

    inline void init()
    {
        for(int i=1;i<=n1;++i)
        {
            a[i] = i;
        }
    }

    #ifdef DEBUG_SHUFFLE
        inline void output()
        {
            printf("Shuffle: ");
            for(int i=1;i<=n1;++i)
            {
                printf("%d ", a[i]);
            }
            printf("\n");
        }
    #endif

    inline void copy()
    {
        for(int i=1;i<=n1;++i)
        {
            a[i] = b[i];
        }
    }

    inline void shuffle1(int a1)
    {
        for(int i=1,j=a1+1,k=1;i<=a1||j<=n1;)
        {
            if(i <= a1)
            {
                b[k++] = a[i++];
            }
            if(j <= n1)
            {
                b[k++] = a[j++];
            }
        }
        copy();
    }

    inline void shuffle2(int a1, int b1)
    {
        int j = 1;
        for(int i=a1;i<=b1;++i)
        {
            b[j++] = a[i];
        }
        for(int i=1;i<a1;++i)
        {
            b[j++] = a[i];
        }
        for(int i=b1+1;i<=n1;++i)
        {
            b[j++] = a[i];
        }
        copy();
    }

    inline void shuffle3(int a1, int b1)
    {
        int j = 1;
        for(int i=1;i<a1;++i)
        {
            b[j++] = a[i];
        }
        for(int i=b1+1;i<=n1;++i)
        {
            b[j++] = a[i];
        }
        for(int i=a1;i<=b1;++i)
        {
            b[j++] = a[i];
        }
        copy();
    }
};

class PokerGame
{
public:
    static const int MAXN2 = 50;
    static const int INF2 = 1000;

    inline void deal(int *data, int len)
    {
        divide(data, len);
        calcResult();
    }

    inline bool isWin()
    {
        return win;
    }

    inline int getLength()
    {
        return n2;
    }

    inline int* getArray1()
    {
        return a;
    }

    inline int* getArray2()
    {
        return b;
    }
private:
    int n2;
    int a[MAXN2];
    int b[MAXN2];
    bool visit[MAXN2];
    bool win;

    inline void divide(int *data, int len)
    {
        n2 = len >> 1;
        for(int i=0;i<n2;++i)
        {
            a[i] = data[i<<1];
            b[i] = data[(i<<1)+1];
        }
        #ifdef DEBUG_POKER
            printDivideResult();
        #endif
    }

    #ifdef DEBUG_POKER
        inline void printDivideResult()
        {
            printf("Divide Result: \n");
            printf("\t");
            for(int i=0;i<n2;++i)
            {
                printf("%d ", a[i]);
            }
            printf("\n");
            printf("\t");
            for(int i=0;i<n2;++i)
            {
                printf("%d ", b[i]);
            }
            printf("\n");
        }
    #endif

    void calcResult()
    {
        memset(visit, false, sizeof(visit));
        int count1 = 0;
        int count2 = 0;
        int highPos, highValue;
        int lowPos, lowValue;
        for(int i=0;i<n2;++i)
        {
            highValue = INF2;
            lowValue = INF2;
            for(int j=0;j<n2;++j)
            {
                if(!visit[j])
                {
                    if(a[j] > b[i])
                    {
                        if(a[j] - b[i] < highValue)
                        {
                            highValue = a[j] - b[i];
                            highPos = j;
                        }
                    }
                    else
                    {
                        if(a[j] < lowValue)
                        {
                            lowValue = a[j];
                            lowPos = j;
                        }
                    }
                }
            }
            if(highValue == INF2)
            {
                ++ count2;
                visit[lowPos] = true;
                #ifdef DEBUG_POKER
                    printf("Poker Process: %d %d\n", b[i], a[lowPos]);
                #endif
            }
            else
            {
                ++ count1;
                visit[highPos] = true;
                #ifdef DEBUG_POKER
                    printf("Poker Process: %d %d\n", b[i], a[highPos]);
                #endif
            }
        }
        win = count1 >= count2;
        #ifdef DEBUG_POKER
            printf("Poker Result: ");
            if(win)
            {
                printf("Win\n");
            }
            else
            {
                printf("Lose\n");
            }
        #endif
    }
};

class Subsequence
{
public:
    static const int MAXN3 = 50;

    inline int calcLIS(int *data, int n)
    {
        a = 1;
        for(int i=0;i<n;++i)
        {
            dp[i] = 1;
            for(int j=0;j<i;++j)
            {
                if(data[j] < data[i])
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            a = std::max(a, dp[i]);
        }
        #ifdef DEBUG_SUBSEQUENCE
            printf("LIS: %d\n", a);
        #endif
    }

    inline int calcLDS(int *data, int n)
    {
        b = 1;
        for(int i=0;i<n;++i)
        {
            dp[i] = 1;
            for(int j=0;j<i;++j)
            {
                if(data[j] > data[i])
                {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            b = std::max(b, dp[i]);
        }
        #ifdef DEBUG_SUBSEQUENCE
            printf("LDS: %d\n", b);
        #endif
    }

    inline int getLISLength()
    {
        return a;
    }

    inline int getLDSLength()
    {
        return b;
    }

private:
    int a, b;
    int dp[MAXN3];
};

class PowerPower
{
public:
    inline int deal(int a, int b)
    {
        int mod = b * b + 1;
        result = a;
        for(int i=0;i<a;++i)
        {
            result = (result * result) % mod;
        }
        #ifdef DEBUG_POWER
            printf("Power Result: %d\n", result);
        #endif
        return result;
    }

    inline int getResult()
    {
        return result;
    }
private:
    int result;
};

class NumberFinder
{
public:
    inline void deal(int x, int b)
    {
        int mod = b * b + 1;
        int n51 = Fibonacci::getKthNumber(x - 1, mod) + 1;
        int n52 = Factor::getFactorNumber(n51);
        int n53 = Catalan::getKthNumber(n52, mod);
        result = Euler::getCoprimeNumber(n53);
        #ifdef DEBUG_NUMBER_FIBONACCI
            Fibonacci::debug();
            printf("Fibonacci: %d\n", n51);
        #endif
        #ifdef DEBUG_NUMBER_FACTOR
            Factor::debug();
            printf("Factor: %d\n", n52);
        #endif
        #ifdef DEBUG_NUMBER_CATALAN
            Catalan::debug();
            printf("Catalan: %d\n", n53);
        #endif
        #ifdef DEBUG_NUMBER_EULER
            Euler::debug();
            printf("Euler: %d\n", result);
        #endif
    }

    inline int getResult()
    {
        return result;
    }
private:
    int result;

    class Fibonacci
    {
    public:
        static int getKthNumber(int x, int mod)
        {
            if(x == 0)
            {
                return 1 % mod;
            }
            if(x == 1)
            {
                return 1 % mod;
            }
            int a = 1, b = 1, c = 2;
            for(int i=1;i<x;++i)
            {
                c = (a + b) % mod;
                a = b;
                b = c;
            }
            return c;
        }
        #ifdef DEBUG_NUMBER_FIBONACCI
            static void debug()
            {
                printf("Fibonacci Debug: \n");
                for(int i=0;i<10;++i)
                {
                    printf("%d ", getKthNumber(i, 1007));
                }
                printf("\n");
            }
        #endif
    };

    class Factor
    {
    public:
        static int getFactorNumber(int x)
        {
            if(x == 1)
            {
                return 1;
            }
            int count = 0;
            for(int i=2;i<=x;++i)
            {
                while(x % i == 0)
                {
                    ++ count;
                    x /= i;
                }
            }
            return count;
        }
        #ifdef DEBUG_NUMBER_FACTOR
            static void debug()
            {
                printf("Factor Debug: \n");
                for(int i=0;i<10;++i)
                {
                    printf("%d ", getFactorNumber(i));
                }
                printf("\n");
            }
        #endif
    };

    class Catalan
    {
    public:
        static int getKthNumber(int x, int mod)
        {
            if(x == 0)
            {
                return 1;
            }
            int res = 1;
            for(int i=1;i<=x;++i)
            {
                res = ((4 * i - 2) * (long long)res / (i + 1)) % mod;
            }
            return res;
        }
        #ifdef DEBUG_NUMBER_CATALAN
            static void debug()
            {
                printf("Catalan Debug: \n");
                for(int i=0;i<10;++i)
                {
                    printf("%d ", getKthNumber(i, 1007));
                }
                printf("\n");
            }
        #endif
    };

    class Euler
    {
    public:
        static int getCoprimeNumber(int x)
        {
            int count = 0;
            for(int i=1;i<x;++i)
            {
                if(gcd(i, x) == 1)
                {
                    ++ count;
                }
            }
            return count;
        }
        #ifdef DEBUG_NUMBER_EULER
            static void debug()
            {
                printf("Euler Debug: \n");
                for(int i=0;i<10;++i)
                {
                    printf("%d ", getCoprimeNumber(i));
                }
                printf("\n");
            }
        #endif
    private:
        static int gcd(int a, int b)
        {
            if(b == 0)
            {
                return a;
            }
            return gcd(b, a % b);
        }
    };
};

class Matrix
{
public:
    static const int MAXN6 = 20;
    static const double eps = 1e-8;

    Matrix()
    {
        r = c = 0;
    }

    Matrix(int r, int c)
    {
        this->r = r;
        this->c = c;
    }

    static Matrix UNIT(int size)
    {
        Matrix matrix(size, size);
        for(int i=0;i<size;++i)
        {
            for(int j=0;j<size;++j)
            {
                matrix.data[i][j] = 0.0;
            }
            matrix.data[i][i] = 1.0;
        }
        return matrix;
    }

    inline int rowNum() const
    {
        return r;
    }

    inline int colNum() const
    {
        return c;
    }

    inline void setDataAt(int x, int y, double value)
    {
        data[x][y] = value;
    }

    inline double getDataAt(int x, int y) const
    {
        return data[x][y];
    }

    Matrix rotateClockwise() const
    {
        Matrix result(c, r);
        for(int i=0;i<c;++i)
        {
            for(int j=0;j<r;++j)
            {
                result.data[i][j] = data[r - j - 1][i];
            }
        }
        return result;
    }

    int rank() const
    {
        Matrix res = this->copy();
        int i = 0;
        for(int j=0;i<r&&j<c;++j)
        {
            int index = i;
            for(int k=i+1;k<r;++k)
            {
                if(fabs(res.data[k][j]) > fabs(res.data[index][j]))
                {
                    index = k;
                }
            }
            if(index != i)
            {
                for(int k=j;k<c;++k)
                {
                    std::swap(res.data[index][k], res.data[i][k]);
                }
            }
            if(fabs(res.data[i][j]) > eps)
            {
                for(int k=i+1;k<r;++k)
                {
                    double temp = res.data[k][j] / res.data[i][j];
                    for(int l=j;l<c;++l)
                    {
                        res.data[k][l] -= res.data[i][l] * temp;
                    }
                }
                ++ i;
            }
        }
        return i;
    }

    inline Matrix copy() const
    {
        Matrix a(r, c);
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
            {
                a.data[i][j] = data[i][j];
            }
        }
        return a;
    }

    friend Matrix operator + (const Matrix &a, const Matrix &b)
    {
        Matrix c(a.r, a.c);
        for(int i=0;i<a.r;++i)
        {
            for(int j=0;j<a.c;++j)
            {
                c.data[i][j] = a.data[i][j] + b.data[i][j];
            }
        }
        return c;
    }

    friend Matrix operator - (const Matrix &a, const Matrix &b)
    {
        Matrix c(a.r, a.c);
        for(int i=0;i<a.r;++i)
        {
            for(int j=0;j<a.c;++j)
            {
                c.data[i][j] = a.data[i][j] - b.data[i][j];
            }
        }
        return c;
    }

    friend Matrix operator * (const Matrix &a, const Matrix &b)
    {
        Matrix c(a.r, b.c);
        for(int i=0;i<a.r;++i)
        {
            for(int j=0;j<b.c;++j)
            {
                c.data[i][j] = 0;
                for(int k=0;k<a.c;++k)
                {
                    c.data[i][j] += a.data[i][k] * b.data[k][j];
                }
            }
        }
        return c;
    }

    #ifdef DEBUG_MATRIX
        inline void output()
        {
            printf("Matrix %d %d: \n", r, c);
            for(int i=0;i<r;++i)
            {
                for(int j=0;j<c;++j)
                {
                    printf("%.3lf ", data[i][j]);
                }
                printf("\n");
            }
        }
    #endif
private:
    int r, c;
    double data[MAXN6][MAXN6];
};

class MatrixWork
{
public:
    void deal()
    {
        double value;
        scanf("%d", &n6);
        Matrix origin(n6, n6);
        for(int i=0;i<n6;++i)
        {
            for(int j=0;j<n6;++j)
            {
                scanf("%lf", &value);
                origin.setDataAt(i, j, value);
            }
        }
        Matrix mat1 = origin.rotateClockwise();
        Matrix mat2 = mat1.rotateClockwise();
        Matrix mat3 = mat2.rotateClockwise();
        Matrix mat4 = mat1 + origin;
        Matrix mat5 = mat3 - mat2;
        realMatrix = mat4 * mat5;
        #ifdef DEBUG_MATRIX_WORK
            mat1.output();
            mat2.output();
            mat3.output();
            mat4.output();
            mat5.output();
            realMatrix.output();
            printf("Rank: %d\n", realMatrix.rank());
        #endif
    }

    int getRank()
    {
        return realMatrix.rank();
    }

    Matrix getRealMatrix()
    {
        return realMatrix;
    }
private:
    int n6;
    Matrix realMatrix;
};

class MatrixTravel
{
public:
    static const int MAXN7 = 20;

    void deal(const Matrix &matrix, bool couldWin)
    {
        dp[0][0] = matrix.getDataAt(0, 0);
        for(int j=1;j<matrix.colNum();++j)
        {
            dp[0][j] = dp[0][j - 1] + matrix.getDataAt(0, j);
        }
        for(int i=1;i<matrix.rowNum();++i)
        {
            dp[i][0] = dp[i - 1][0] + matrix.getDataAt(i, 0);
            for(int j=1;j<matrix.colNum();++j)
            {
                if(couldWin)
                {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + matrix.getDataAt(i, j);
                }
                else
                {
                    dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + matrix.getDataAt(i, j);
                }
            }
        }
        result = (int)fabs(dp[matrix.rowNum() - 1][matrix.colNum() - 1]);
        #ifdef DEBUG_MATRIX_TRAVEL
            printf("Matrix Travel Result: %d\n", result);
        #endif
    }

    inline int getResult()
    {
        return result;
    }
private:
    double dp[MAXN7][MAXN7];
    int result;
};

class Graph
{
public:
    static const int MAXN9 = 200;
    static const int MAXM9 = MAXN9 * MAXN9 * 2;

    void deal()
    {
        int n, m, u, v, w, s, t;
        scanf("%d%d", &n, &m);
        Edges *edgesTree = new Edges();
        Edges *edgesCut = new Edges();
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            edgesTree->addEdge(u, v, w);
            edgesCut->addEdge(u, v, w);
            edgesCut->addEdge(v, u, 0);
        }
        scanf("%d%d", &s, &t);
        SpanningTree spanningTree;
        int n91 = spanningTree.getMinimumSpanningTree(n, *edgesTree);
        #ifdef DEBUG_GRAPH_SPANNING
            printf("Minimum Spanning Tree: %d\n", n91);
        #endif
        Cut cut;
        int n92 = cut.getMinimumCut(s, t, *edgesCut);
        #ifdef DEBUG_GRAPH_CUT
            printf("Minimum Cut: %d\n", n92);
        #endif
        result = n91 + n92;
        delete edgesTree;
        delete edgesCut;
    }

    inline int getResult()
    {
        return result;
    }
protected:
    int result;

    class Edges
    {
    public:
        class Edge
        {
        public:
            int u, v, w, next;
            bool operator < (const Edge &edge) const
            {
                return w < edge.w;
            }
        } edge[MAXM9];
        int edgeNumber, head[MAXN9];

        Edges()
        {
            clearEdge();
        }

        inline void clearEdge()
        {
            edgeNumber = 0;
            memset(head, -1, sizeof(head));
        }

        inline void addEdge(int u, int v, int w)
        {
            edge[edgeNumber].u = u;
            edge[edgeNumber].v = v;
            edge[edgeNumber].w = w;
            edge[edgeNumber].next = head[u];
            head[u] = edgeNumber ++;
        }
    };

    class SpanningTree
    {
    public:
        int getMinimumSpanningTree(int n, Edges &edges)
        {
            int ans = 0;
            std::sort(edges.edge, edges.edge + edges.edgeNumber);
            set.init(n);
            int count = 0;
            for(int i=0;i<edges.edgeNumber;++i)
            {
                int u = edges.edge[i].u;
                int v = edges.edge[i].v;
                int w = edges.edge[i].w;
                if(set.find(u) != set.find(v))
                {
                    set.combine(u, v);
                    ans += w;
                    if(++ count >= n - 1)
                    {
                        break;
                    }
                }
            }
            return ans;
        }
    private:
        class DisjointSet
        {
        public:
            inline void init(int n)
            {
                for(int i=0;i<=n;++i)
                {
                    father[i] = i;
                }
            }

            int find(int x)
            {
                if(x == father[x])
                {
                    return x;
                }
                return father[x] = find(father[x]);
            }

            inline void combine(int x, int y)
            {
                father[find(x)] = find(y);
            }
        private:
            int father[MAXN9];
        } set;
    };

    class Cut
    {
    public:
        static const int INF = 0x3f3f3f3f;

        int getMinimumCut(int s, int t, Edges &edges)
        {
            this->s = s;
            this->t = t;
            this->edges = edges;
            int ans = 0;
            while(bfs())
            {
                int temp = 0;
                while(temp = dfs(s, INF))
                {
                    ans += temp;
                }
            }
            return ans;
        }
    private:
        Edges edges;
        int queue[MAXM9];
        int mark[MAXN9];
        int s, t;

        bool bfs()
        {
            memset(mark, -1, sizeof(mark));
            int front = 0, rear = 1;
            queue[0] = s;
            mark[s] = 0;
            while(front < rear)
            {
                int u = queue[front++];
                for(int i=edges.head[u];i!=-1;i=edges.edge[i].next)
                {
                    int v = edges.edge[i].v;
                    if(edges.edge[i].w && mark[v] == -1)
                    {
                        mark[v] = mark[u] + 1;
                        queue[rear++] = v;
                        if(v == t)
                        {
                            return true;
                        }
                    }
                }
            }
            return false;
        }

        int dfs(int u, int flow)
        {
            if(u == t)
            {
                return flow;
            }
            int ret = 0;
            for(int i=edges.head[u];i!=-1;i=edges.edge[i].next)
            {
                int v = edges.edge[i].v;
                int w = 0;
                if(mark[v] == mark[u] + 1 && edges.edge[i].w && (w = dfs(v, std::min(flow - ret, edges.edge[i].w))))
                {
                    edges.edge[i].w -= w;
                    edges.edge[i^1].w += w;
                    ret += w;
                    if(ret == flow)
                    {
                        return ret;
                    }
                }
            }
            if(ret == 0)
            {
                mark[u] = -1;
            }
            return ret;
        }
    };
};

class Geometry
{
public:
    static const int MAXN10 = 50;
    static const int MAXM10 = 10000;
    static const double eps = 1e-8;

    void deal()
    {
        int n;
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            point[i].input();
        }
        Intersect intersect;
        int n101 = intersect.deal(n, point);
        #ifdef DEBUG_GEOMETRY_INTERSECT
            printf("Intersect: %d\n", n101);
        #endif
        Convex convex;
        int n102 = convex.deal(n, point);
        #ifdef DEBUG_GEOMETRY_CONVEX
            printf("Convex: %d\n", n102);
        #endif
        Transform transform;
        int n103 = transform.deal(n, point);
        #ifdef DEBUG_GEOMETRY_TRANSFORM
            printf("Geometry: %d\n", n103);
        #endif
        result = n101 + n102 + n103;
    }

    inline int getResult()
    {
        return result;
    }

    class Point
    {
    public:
        double x, y;

        friend bool operator < (const Point &a, const Point &b)
        {
            if(fabs(a.y - b.y) < eps)
            {
                return a.x < b.x;
            }
            return a.y < b.y;
        }

        inline Point copy() const
        {
            Point point;
            point.x = x;
            point.y = y;
            return point;
        }

        inline void input()
        {
            scanf("%lf%lf", &x, &y);
        }

        #ifdef DEBUG_GEOMETRY
            inline void output()
            {
                printf("%lf %lf\n", x, y);
            }
        #endif

        friend Point operator + (const Point &a, const Point &b)
        {
            Point c;
            c.x = a.x + b.x;
            c.y = a.y + b.y;
            return c;
        }

        friend Point operator - (const Point &a, const Point &b)
        {
            Point c;
            c.x = a.x - b.x;
            c.y = a.y - b.y;
            return c;
        }

        friend double operator * (const Point &a, const Point &b)
        {
            return a.x * b.x + a.y * b.y;
        }

        friend double operator ^ (const Point &a, const Point &b)
        {
            return a.x * b.y - a.y * b.x;
        }

        double cross(const Point &a, const Point &b) const
        {
            return (a - *this) ^ (b - *this);
        }
    } point[MAXN10];

    class Segment
    {
    public:
        Point u, v;

        double getLength()
        {
            return sqrt((v.x - u.x) * (v.x - u.x) + (v.y - u.y) * (v.y - u.y));
        }

        static double dblcmp(double x)
        {
            if(fabs(x) < eps)
            {
                return 0;
            }
            return x > 0 ? 1 : -1;
        }

        friend Point operator * (const Segment &a, const Segment &b)
        {
            Point c;
            double area1 = fabs(b.v.cross(a.u, b.u));
            double area2 = fabs(b.v.cross(a.v, b.u));
            c.x = a.u.x + (a.v.x - a.u.x) * area1 / (area1 + area2);
            c.y = a.u.y + (a.v.y - a.u.y) * area1 / (area1 + area2);
            return c;
        }

        friend bool operator & (const Segment &a, const Segment &b)
        {
            return dblcmp(b.v.cross(a.u, b.u)) * dblcmp(b.v.cross(a.v, b.u)) < 0 &&
                    dblcmp(a.v.cross(b.u, a.u)) * dblcmp(a.v.cross(b.v, a.u)) < 0;
        }
    };

private:
    int result;

    class Intersect
    {
    public:
        int deal(int n, Point* point)
        {
            std::set<Point> pointSet;
            Segment segment1;
            Segment segment2;
            for(int i=0;i<n;++i)
            {
                segment1.u = point[i];
                for(int j=i+1;j<n;++j)
                {
                    segment1.v = point[j];
                    for(int k=0;k<n;++k)
                    {
                        segment2.u = point[k];
                        for(int l=k+1;l<n;++l)
                        {
                            segment2.v = point[l];
                            if(segment1 & segment2)
                            {
                                pointSet.insert(segment1 * segment2);
                            }
                        }
                    }
                }
            }
            #ifdef DEBUG_GEOMETRY_INTERSECT
                printf("Intersect Points: \n");
            #endif
            int ans = 0;
            double lastX = 1e100;
            double lastY = 1e100;
            for(std::set<Point>::iterator it=pointSet.begin();it!=pointSet.end();++it)
            {
                if(dblcmp(it->x - lastX) || dblcmp(it->y - lastY))
                {
                    ++ ans;
                    #ifdef DEBUG_GEOMETRY_INTERSECT
                        printf("%lf %lf\n", it->x, it->y);
                    #endif
                }
                lastX = it->x;
                lastY = it->y;
            }
            return ans;
        }
    private:
        double dblcmp(double x)
        {
            if(fabs(x) < eps)
            {
                return 0;
            }
            return x > 0 ? 1 : -1;
        }
    };

    class Convex
    {
    public:
        int deal(int n, Point* point)
        {
            graham(n, point);
            #ifdef DEBUG_GEOMETRY_CONVEX
                printf("Convex: \n");
                for(int i=0;i<top;++i)
                {
                    point[stack[i]].output();
                }
            #endif
            double ans = 0;
            for(int i=2;i<top;++i)
            {
                ans += fabs(point[stack[0]].cross(point[stack[i-1]], point[stack[i-2]]));
            }
            return (int)(ans * 0.5);
        }
    private:
        int top;
        int stack[MAXN10];

        double dblcmp(double x)
        {
            if(fabs(x) < eps)
            {
                return 0;
            }
            return x > 0 ? 1 : -1;
        }

        void graham(int n, Point* point)
        {
            std::sort(point, point + n);
            stack[0] = 0;
            stack[1] = 1;
            top = 2;
            for(int i=2;i<n;++i)
            {
                while(top > 1 && dblcmp(point[i].cross(point[stack[top-1]], point[stack[top-2]])) < 0)
                {
                    -- top;
                }
                stack[top ++] = i;
            }
            int temp = top;
            stack[top++] = n - 2;
            for(int i= n-3;i>=0;--i)
            {
                while(top > temp && dblcmp(point[i].cross(point[stack[top-1]], point[stack[top-2]])) < 0)
                {
                    -- top;
                }
                stack[top ++] = i;
            }
        }
    };

    class Transform
    {
    public:
        int deal(int n, Point *point)
        {
            int m, type;
            double x, y, z, angle;
            scanf("%d", &m);
            Matrix world = Matrix::UNIT(4);
            while(m--)
            {
                scanf("%d", &type);
                switch(type)
                {
                    case 1:
                        scanf("%lf%lf%lf", &x, &y, &z);
                        world = world * getTranslationMatrix(x, y, z);
                        break;
                    case 2:
                        scanf("%lf", &angle);
                        angle = angle / 180.0 * PI;
                        world = world * getRotateXMatrix(-angle);
                        break;
                    case 3:
                        scanf("%lf", &angle);
                        angle = angle / 180.0 * PI;
                        world = world * getRotateYMatrix(-angle);
                        break;
                    case 4:
                        scanf("%lf", &angle);
                        angle = angle / 180.0 * PI;
                        world = world * getRotateZMatrix(-angle);
                        break;
                    case 5:
                        scanf("%lf", &x);
                        world = world * getScaleMatrix(x);
                        break;
                }
            }
            double ans = 0.0;
            Matrix vector(1, 4);
            for(int i=0;i<n;++i)
            {
                vector.setDataAt(0, 0, point[i].x);
                vector.setDataAt(0, 1, point[i].y);
                vector.setDataAt(0, 2, 0.0);
                vector.setDataAt(0, 3, 1.0);
                vector = vector * world;
                #ifdef DEBUG_GEOMETRY_TRANSFORM
                    printf("Vector: %lf %lf %lf\n", vector.getDataAt(0, 0), vector.getDataAt(0, 1), vector.getDataAt(0, 2));
                #endif
                ans += vector.getDataAt(0, 2);
            }
            return (int)fabs(ans / n);
        }
    private:
        Matrix getTranslationMatrix(double x, double y, double z)
        {
            Matrix matrix = Matrix::UNIT(4);
            matrix.setDataAt(3, 0, x);
            matrix.setDataAt(3, 1, y);
            matrix.setDataAt(3, 2, z);
            #ifdef DEBUG_GEOMETRY_TRANSFORM
                printf("Translation ");
                matrix.output();
            #endif
            return matrix;
        }

        Matrix getRotateXMatrix(double angle)
        {
            Matrix matrix = Matrix::UNIT(4);
            matrix.setDataAt(1, 1, cos(angle));
            matrix.setDataAt(1, 2, -sin(angle));
            matrix.setDataAt(2, 1, sin(angle));
            matrix.setDataAt(2, 2, cos(angle));
            #ifdef DEBUG_GEOMETRY_TRANSFORM
                printf("Rotate X ");
                matrix.output();
            #endif
            return matrix;
        }

        Matrix getRotateYMatrix(double angle)
        {
            Matrix matrix = Matrix::UNIT(4);
            matrix.setDataAt(0, 0, cos(angle));
            matrix.setDataAt(0, 2, -sin(angle));
            matrix.setDataAt(2, 0, sin(angle));
            matrix.setDataAt(2, 2, cos(angle));
            #ifdef DEBUG_GEOMETRY_TRANSFORM
                printf("Rotate Y ");
                matrix.output();
            #endif
            return matrix;
        }

        Matrix getRotateZMatrix(double angle)
        {
            Matrix matrix = Matrix::UNIT(4);
            matrix.setDataAt(0, 0, cos(angle));
            matrix.setDataAt(0, 1, -sin(angle));
            matrix.setDataAt(1, 0, sin(angle));
            matrix.setDataAt(1, 1, cos(angle));
            #ifdef DEBUG_GEOMETRY_TRANSFORM
                printf("Rotate Z ");
                matrix.output();
            #endif
            return matrix;
        }

        Matrix getScaleMatrix(double x)
        {
            Matrix matrix = Matrix::UNIT(4);
            matrix.setDataAt(0, 0, x);
            matrix.setDataAt(1, 1, x);
            matrix.setDataAt(2, 2, x);
            #ifdef DEBUG_GEOMETRY_TRANSFORM
                printf("Scale X ");
                matrix.output();
            #endif
            return matrix;
        }
    };
};

class Random
{
public:
    void deal(int A, int B, int C, int D)
    {
        #ifdef DEBUG_RANDOM
            printf("Random: %d %d %d %d\n", A, B, C, D);
        #endif
        randomGenerator.srand(A, B, C, D + 1);
        int n, m, a;
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            scanf("%d", &m);
            for(int i=0;i<m;++i)
            {
                scanf("%d", &a);
                a = ((a + randomGenerator.rand()) % 100) + 32;
                putchar(a);
            }
            printf("\n");
        }
    }

    #ifdef DEBUG_RANDOM
        void generateData(int A, int B, int C, int D, const char *s)
        {
            randomGenerator.srand(A, B, C, D + 1);
            printf("%d ", strlen(s));
            for(int i=0;s[i];++i)
            {
                int ch = s[i];
                ch -= 32;
                ch -= randomGenerator.rand();
                while(ch < 0)
                {
                    ch += 100;
                }
                printf("%d ", ch);
            }
        }
    #endif
private:
    class RandomGenerator
    {
    public:
        void srand(int A, int B, int C, int D)
        {
            this->A = A;
            this->B = B;
            this->C = C;
            this->D = D;
        }

        int rand()
        {
            return A = (A * B + C) % D;
        }

    private:
        int A, B, C, D;
    } randomGenerator;
};

int main()
{
    ShuffleMechine shuffleMechine;
    while(shuffleMechine.deal())
    {
        PokerGame pokerGame;
        pokerGame.deal(shuffleMechine.getResult(), shuffleMechine.getLength());
        Subsequence subsequence;
        subsequence.calcLIS(pokerGame.getArray1(), pokerGame.getLength());
        subsequence.calcLDS(pokerGame.getArray2(), pokerGame.getLength());
        PowerPower powerPower;
        powerPower.deal(subsequence.getLISLength(), subsequence.getLDSLength());
        NumberFinder numberFinder;
        numberFinder.deal(powerPower.getResult(), subsequence.getLDSLength());
        int A = numberFinder.getResult();
        MatrixWork matrixWork;
        matrixWork.deal();
        MatrixTravel matrixTravel;
        matrixTravel.deal(matrixWork.getRealMatrix(), pokerGame.isWin());
        int B = matrixTravel.getResult() + matrixWork.getRank();
        Graph graph;
        graph.deal();
        int C = graph.getResult();
        Geometry geometry;
        geometry.deal();
        int D = geometry.getResult();
        Random random;
        random.deal(A, B, C, D);
        printf("\n");
    }
    return 0;
}
