#include<stdio.h>
#include<list>
#define MAX_N 5005
using namespace std;
int maxSeqLen[MAX_N + 1];
int maxTailVal[MAX_N + 1], maxTailLen;
int val[MAX_N + 1], n;
list<int> maxLenSets[MAX_N + 1];
int countv[MAX_N + 1];
int main()
{
    int i;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &val[i]);
        int l = 1, r = maxTailLen;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            if(maxTailVal[mid] <= val[i]) r = mid - 1;
            else l = mid + 1;
        }
        maxTailVal[l] = val[i];
        maxSeqLen[i] = l;
        if(l > maxTailLen)
            maxTailLen = l;
    }
    countv[1] = 1;
    maxLenSets[1].push_back(1);
    val[n + 1] = -1;
    maxSeqLen[n + 1] = maxTailLen + 1;
    for(i = 2; i <= n + 1; i++)
    {
        int d = maxSeqLen[i];
        list<int>::iterator iter = maxLenSets[d].begin();
        for(; iter != maxLenSets[d].end(); ++iter) if(val[*iter] == val[i])
        {
                maxLenSets[d].erase(iter);
                break;
        }
        maxLenSets[d].push_back(i);
        if(d == 1)
        {
            countv[i] = 1;
            continue;
        }
        iter = maxLenSets[d - 1].begin();
        for(; iter != maxLenSets[d - 1].end(); ++iter) if(val[*iter] > val[i])
            countv[i] += countv[*iter];
    }
    printf("%d %d\n", maxTailLen, countv[n + 1]);
    return 0;
}
