//#define METHOD1
#define METHOD2

#ifdef METHOD1

#include<cstdio>
#include<cstring>
#include<cmath>

#define DEBUG

#ifdef DEBUG
    #define Loop_Test
    #define Record_Test
    #define Inside_Test
#endif

static const int MAXN = 205;
static const double eps = 1e-6;
static const double PI = 3.1415926;

struct Point
{
    int x, y;
    Point()
    {
        x = 0, y = 0;
    }
    Point(int _x, int _y)
    {
        x = _x, y = _y;
    }
}vertexPosition[MAXN];

const int RECORDSIZE = 7;
struct Record
{
    int d[RECORDSIZE];
}record[100000];
int recordNumber;

int vertexNumber;
int edge[MAXN][MAXN];
int requestSize;

int stack[MAXN];
int start, end;
bool visited[MAXN];

int min(const int &a, const int &b)
{
    return a<b?a:b;
}

void clearRecord(Record &rec)
{
    for(int i=0;i<RECORDSIZE;++i)
    {
        rec.d[i] = 0;
    }
}

void setRecord(Record &rec)
{
    int index, bit;
    clearRecord(rec);
    for(int i=start;i<end;++i)
    {
        index = stack[i] / 30;
        bit = stack[i] % 30;
        rec.d[index] |= (1<<bit);
    }
}

void addRecord()
{
    setRecord(record[recordNumber++]);
}

bool equalRecord(Record &ra, Record &rb)
{
    for(int i=0;i<RECORDSIZE;++i)
    {
        if(ra.d[i] != rb.d[i])
        {
            return false;
        }
    }
    return true;
}

bool findRecord()
{
    Record temp;
    setRecord(temp);
    for(int i=0;i<recordNumber;++i)
    {
        if(equalRecord(temp, record[i]))
        {
            return true;
        }
    }
    return false;
}

inline double getAngle(const Point &a)
{
    return atan2((double)a.y, (double)a.x);
}

inline double abs(double x)
{
    if(x < 0)
    {
        x = -x;
    }
    return x;
}

inline double getAngle(const Point &a, const Point &b, const Point &o)
{
    double ans = abs(getAngle(Point(a.x - o.x, a.y - o.y)) - getAngle(Point(b.x - o.x, b.y - o.y)));
    if(ans > PI)
    {
        ans = 2 * PI - ans;
    }
    return ans;
}

inline int crossProduct(const Point &a, const Point &b, const Point &o)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

void input()
{
    scanf("%d",&vertexNumber);
    for(int i=1;i<=vertexNumber;++i)
    {
        scanf("%d",&i);
        scanf("%d",&vertexPosition[i].x);
        scanf("%d",&vertexPosition[i].y);
        scanf("%d",&edge[i][0]);
        for(int j=1;j<=edge[i][0];++j)
        {
            scanf("%d",&edge[i][j]);
        }
    }
    scanf("%d",&requestSize);
    recordNumber = 0;
}

#ifdef Record_Test
    void printRecord(Record &rec)
    {
        for(int i=0;i<RECORDSIZE;++i)
        {
            printf("%d ",rec.d[i]);
        }
        printf("\n");
    }
#endif

bool inLoop(Record &rec, int vertexIndex)
{
    int index = vertexIndex / 30;
    int bit = vertexIndex % 30;
    return (rec.d[index] & (1<<bit)) > 0;
}

int dblcmp(double x)
{
    if(fabs(x) < eps)
    {
        return 0;
    }
    if(x > 0)
    {
        return 1;
    }
    return -1;
}

bool findInside()
{
    Record temp;
    setRecord(temp);
    for(int i=1;i<=vertexNumber;++i)
    {
        if(!inLoop(temp, i))
        {
            double totalAngle = getAngle(vertexPosition[stack[end]], vertexPosition[stack[start]], vertexPosition[i]);
            for(int i=start+1;i<end;++i)
            {
                totalAngle += getAngle(vertexPosition[stack[i-1]], vertexPosition[stack[i]], vertexPosition[i]);
            }
            #ifdef Inside_Test
                printf("%d %lf %lf\n",i, PI * 2, totalAngle);
            #endif
            if(dblcmp(totalAngle - PI * 2) == 0)
            {
                return true;
            }
        }
    }
    return false;
}

void findLoop(int vertex, int depth)
{
    stack[depth++] = vertex;
    visited[vertex] = true;
    for(int i=1;i<=edge[vertex][0];++i)
    {
        if(visited[edge[vertex][i]])
        {
            if(stack[depth - requestSize] == edge[vertex][i])
            {
                start = depth - requestSize;
                end = depth;
                if(!findRecord())
                {
                    #ifdef Loop_Test
                        for(int i=depth-requestSize;i<depth;++i)
                        {
                            printf("%d ",stack[i]);
                        }
                        printf("\n");
                    #endif
                    if(!findInside())
                    {
                        addRecord();
                        #ifdef Inside_Test
                            for(int i=depth-requestSize;i<depth;++i)
                            {
                                printf("%d ",stack[i]);
                            }
                            printf("\n");
                        #endif
                    }
                }

            }
        }
        else
        {
            findLoop(edge[vertex][i], depth);
        }
    }
    visited[vertex] = false;
}

int main(int argc, char* argv[])
{
    #ifdef Inside_Test
        printf("%lf\n",getAngle(Point(2,1), Point(0,1), Point(1,1)));
        printf("%lf\n",getAngle(Point(1,0), Point(1,2), Point(1,1)));
        printf("%lf\n",getAngle(Point(2,1), Point(1,2), Point(1,1)));
        printf("%lf\n",getAngle(Point(1,0), Point(0,1), Point(1,1)));
    #endif
    int caseNumber;
    scanf("%d",&caseNumber);
    while(caseNumber--)
    {
        input();
        memset(visited, false, sizeof(visited));
        for(int i=1;i<=vertexNumber;++i)
        {
            findLoop(i, 0);
        }
        #ifdef Record_Test
            printf("Record Test, Total Record: %d\n",recordNumber);
            for(int i=0;i<recordNumber;++i)
            {
                printRecord(record[i]);
            }
        #endif
    }
    return 0;
}

#endif

#ifdef METHOD2
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int x[200],y[200];
int connect[200][10];
int arrive[200];
int loop[40];
int endNode;
int depth;

bool iMask[200][200];

double Angle(int x1,int y1,int x2,int y2)
{
    return (atan2((double)(x1*y2-x2*y1),x1*x2+y1*y2));
}

double Area()
{
    int i;
    double s=0.0;
    for(i=0;i<depth;i++)
        s+=x[loop[i+1]]*y[loop[i]]-y[loop[i+1]]*x[loop[i]];
    return s/2;
}

int isInside(int i,int k)
{
    int k1=loop[0],k2=loop[depth-2];
    int si,next,flag=0;
    double d2,d1=Angle(x[k2]-x[i],y[k2]-y[i],x[k1]-x[i],y[k1]-y[i]);
    for(si=1;si<=k;si++)
    {
        if(si!=k1&&si!=k2)
        {
            next=connect[i][si];
            d2=Angle(x[next]-x[i],y[next]-y[i],x[k1]-x[i],y[k1]-y[i]);
            if(d2<0&&d2>d1)
            {
                flag=1;
                break;
            }
        }
    }
    return flag;
}

int isLoop(int a,int b)
{
    int i,j,xx,yy,bs;
    double minAngle,tempAngle;
    loop[depth++]=b;
    if(iMask[a][b])
        return 0;
    if(arrive[b])
        return 0;
    arrive[b]=1;
    iMask[a][b]=1;
    if(b==endNode)
        return 1;
    xx=x[b]-x[a];
    yy=y[b]-y[a];
    minAngle=999;
    bs=-1;
    for(i=1;i<=connect[b][0];i++)
    {
        if(connect[b][i]!=a)
        {
            j=connect[b][i];
            tempAngle=Angle(x[j]-x[b],y[j]-y[b],xx,yy);
            if(minAngle>tempAngle)
            {
                minAngle=tempAngle;
                bs=connect[b][i];
            }
        }
    }
    if(bs==-1)
        return 0;
    else
        return isLoop(b,bs);
}

int main()
{
    int i,j,k,n,di,node,ncase,ncount,properSize;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d",&n);
        memset(iMask,0,sizeof(iMask));
        for(i=0;i<n;i++)
        {
            scanf("%d",&node);
            node--;
            scanf("%d%d%d",&x[node],&y[node],&k);
            connect[node][0]=k;
            for(j=1;j<=k;j++)
            {
                scanf("%d",&di);
                connect[node][j]=(--di);
            }
        }
        scanf("%d",&properSize);
        if(properSize<3)
        {
            printf("0\n");
            continue;
        }
        ncount=0;
        for(i=0;i<n;i++)
        {
            endNode=i;
            k=connect[i][0];
            for(j=1;j<=k;j++)
            {
                depth=0;
                memset(arrive,0,sizeof(arrive));
                if(isLoop(i,connect[i][j]))
                {
                    loop[depth]=connect[i][j];
                    if(Area()<0&&isInside(i,k)==0&&depth==properSize)
                        ncount++;
                }
            }
        }
        printf("%d\n",ncount);
    }
    return 0;
}
#endif
