#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int k;
    string name1, name2;
    int HP[8];
    int sha[8];
    int shan[8];
    int plus[8];
    int minus[8];
    scanf("%d", &k);
    while(k--)
    {
        map<string, int> nameMap;
        for(int i=0;i<8;++i)
        {
            cin >> name1;
            nameMap[name1] = i;
            scanf("%d%d%d%d%d", &HP[i], &sha[i], &shan[i], &plus[i], &minus[i]);
        }
        int n, index1, index2;
        scanf("%d", &n);
        while(n--)
        {
            cin >> name1 >> name2;
            index1 = nameMap[name1];
            index2 = nameMap[name2];
            bool flag = true;
            if(index1 == index2)
            {
                flag = false;
            }
            else
            {
                if(HP[index1] == 0)
                {
                    flag = false;
                }
                else
                {
                    if(HP[index2] == 0)
                    {
                        flag = false;
                    }
                    else
                    {
                        if(sha[index1] == 0)
                        {
                            flag = false;
                        }
                        else
                        {
                            int len1 = 1, len2 = 1;
                            int i = index1;
                            while(true)
                            {
                                ++ i;
                                if(i >= 8)
                                {
                                    i = 0;
                                }
                                if(i == index2)
                                {
                                    break;
                                }
                                if(HP[i])
                                {
                                    ++ len1;
                                }
                            }
                            i = index1;
                            while(true)
                            {
                                -- i;
                                if(i < 0)
                                {
                                    i = 7;
                                }
                                if(i == index2)
                                {
                                    break;
                                }
                                if(HP[i])
                                {
                                    ++ len2;
                                }
                            }
                            int l = min(len1, len2);
                            if(plus[index2]) ++l;
                            if(minus[index1]) --l;
                            if(l > 1)
                            {
                                flag = false;
                            }
                        }
                    }
                }
            }
            if(flag)
            {
                -- sha[index1];
                if(shan[index2])
                {
                    -- shan[index2];
                    printf("0\n");
                }
                else
                {
                    -- HP[index2];
                    printf("1\n");
                }
            }
            else
            {
                printf("-1\n");
            }
        }
        printf("\n");
    }
    return 0;
}
