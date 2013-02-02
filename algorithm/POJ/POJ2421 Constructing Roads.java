import java.io.*;
import java.util.*;

public class Main
{
    private static int father[], temp[][];
    private static int n, u[],v[],w[],t,edgeNum,answer;
    private static void init()
    {
        for(int i=0;i<n;i++)
        {
            father[i]=i;
        }
    }
    private static int find(int x)
    {
        if(father[x]==x) return x;
        return father[x]=find(father[x]);
    }
    private static void union(int x ,int y)
    {
        x=find(x);
        y=find(y);
        father[x]=y;
    }
    private static void sort(int start, int end)
    {
        if(start == end) return;
        int mid=(start+end)/2;
        if(end-start>1)
        {
            sort(start, mid);
            sort(mid, end);
        }
        int i=start, j=mid, k=0;
        while(i<mid && j<end)
        {
            if(w[i]<=w[j])
            {
                temp[k][0]=u[i];
                temp[k][1]=v[i];
                temp[k++][2]=w[i++];
            }
            else
            {
                temp[k][0]=u[j];
                temp[k][1]=v[j];
                temp[k++][2]=w[j++];
            }
        }
        if(i<mid)
        {
            for(;i<mid;)
            {
                temp[k][0]=u[i];
                temp[k][1]=v[i];
                temp[k++][2]=w[i++];
            }
        }
        else
        {
            for(;j<end;)
            {
                temp[k][0]=u[j];
                temp[k][1]=v[j];
                temp[k++][2]=w[j++];
            }
        }
        k=0;
        for(i=start;i<end;)
        {
            u[i]=temp[k][0];
            v[i]=temp[k][1];
            w[i++]=temp[k++][2];
        }
    }
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        temp = new int[100005][3];
        father = new int[105];
        u = new int[100005];
        v = new int[100005];
        w = new int[100005];
        edgeNum=0;
        answer=0;
        n = cin.nextInt();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                t = cin.nextInt();
                if(j>i)
                {
                    u[edgeNum]=i;
                    v[edgeNum]=j;
                    w[edgeNum]=t;
                    edgeNum++;
                }
            }
        }
        init();
        sort(0,edgeNum);
        t = cin.nextInt();
        while(t-->0)
        {
            int x,y;
            x=cin.nextInt();
            y=cin.nextInt();
            union(x,y);
        }
        for(int i=0;i<edgeNum;i++)
        {
            if(find(u[i])!=find(v[i]))
            {
                union(u[i],v[i]);
                answer += w[i];
            }
        }
        System.out.println(answer);
    }
}
