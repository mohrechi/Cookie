#include <cstdio>
static const int MAXN = 30;

int n;
int block[MAXN][MAXN];
int top[MAXN];
int position[MAXN];
char s[128];

int main()
{
    int a, b;
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            block[i][0] = i;
            top[i] = 1;
            position[i] = i;
        }
        while(scanf("%s", s), s[0] != 'q')
        {
            if(s[0] == 'm')
            {
                scanf("%d%s%d", &a, s, &b);
                if(a == b || position[a] == position[b])
                {
                    continue;
                }
                while(block[position[a]][top[position[a]] - 1] != a)
                {
                    block[block[position[a]][top[position[a]] - 1]][0] = block[position[a]][top[position[a]] - 1];
                    top[block[position[a]][top[position[a]] - 1]] = 1;
                    position[block[position[a]][top[position[a]] - 1]] = block[position[a]][top[position[a]] - 1];
                    -- top[position[a]];
                }
                if(s[1] == 'n')
                {
                    while(block[position[b]][top[position[b]] - 1] != b)
                    {
                        block[block[position[b]][top[position[b]] - 1]][0] = block[position[b]][top[position[b]] - 1];
                        top[block[position[b]][top[position[b]] - 1]] = 1;
                        position[block[position[b]][top[position[b]] - 1]] = block[position[b]][top[position[b]] - 1];
                        -- top[position[b]];
                    }
                }
                block[position[b]][top[position[b]]++] = a;
                -- top[position[a]];
                position[a] = position[b];
            }
            else
            {
                scanf("%d%s%d", &a, s, &b);
                if(a == b || position[a] == position[b])
                {
                    continue;
                }
                if(s[1] == 'n')
                {
                    while(block[position[b]][top[position[b]] - 1] != b)
                    {
                        block[block[position[b]][top[position[b]] - 1]][0] = block[position[b]][top[position[b]] - 1];
                        top[block[position[b]][top[position[b]] - 1]] = 1;
                        position[block[position[b]][top[position[b]] - 1]] = block[position[b]][top[position[b]] - 1];
                        -- top[position[b]];
                    }
                }
                int tempTop = top[position[a]];
                int tempPosition = position[a];
                while(block[position[a]][--top[position[a]]] != a);
                for(int i=top[position[a]];i<tempTop;++i)
                {
                    block[position[b]][top[position[b]]++] = block[tempPosition][i];
                    position[block[tempPosition][i]] = position[b];
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            printf("%d:", i);
            for(int j=0;j<top[i];++j)
            {
                printf(" %d", block[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
