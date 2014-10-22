#include<iostream>
using namespace std;
const int Max = 1050;
int N, D, K, ans;
int bi[16], cow[Max];

void dfs(int dep, int pre, int w)
{
    if(D - dep + 1 < K - pre)
    {
        return;
    }
    if(pre == K)
    {
        int i, ma = 0;
        for(i = 0; i < N; i ++)
        {
            if(cow[i] == (cow[i] & w))
            {
                ma ++;
            }
        }
        if(ma > ans) ans = ma;
        return;
    }
    dfs(dep + 1, pre, w);
    dfs(dep + 1, pre + 1, w |= bi[dep]);
}

int main()
{
    int i, cou, w;
    for(i = 0; i < 16; i ++)
    bi[i] = 1 << i;
    cin >> N >> D >> K;
    for(i = 0; i < N; i ++)
    {
        cin >> cou;
        while(cou --)
        {
            cin >> w;
            cow[i] |= bi[w];
        }
    }
    ans = 0;
    dfs(1, 0, 0);
    cout << ans << endl;
    return 0;
}
