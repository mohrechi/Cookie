#include<iostream>
//NOT MINE
using namespace std;

const int nine[9][2][2] = { //每个九宫图的起点终点
        {{1,1},{3,3}},
        {{1,4},{3,6}},
        {{1,7},{3,9}},
        {{4,1},{6,3}},
        {{4,4},{6,6}},
        {{4,7},{6,9}},
        {{7,1},{9,3}},
        {{7,4},{9,6}},
        {{7,7},{9,9}},
};

const int s = 45;
int main()
{
//        freopen("data.txt","r",stdin);
        int map[10][10];
        int T;
        int i,j,k;
        char c;
        int sum;
        int zero;
        int z_p;
        int z_time;
        int zz[2];
        int cas = 1;

        cin>>T;

        while(T--)
        {
                cout<<"Scenario #"<<cas++<<":"<<endl;
                getchar();
                zero = 0;
                for(i = 1;i <= 9; ++i)
                {
                        for(j = 1;j <= 9; ++j)
                        {
                                scanf("%c",&c);
                                map[i][j] = c -'0';
                                if(c == '0')zero++;
                        }
                        getchar();
                }
                while(zero != 0)
                {
                        for(i = 1; i <= 9; i++)
                        {
                                sum = 0;
                                z_time = 0;
                                for(j = 1;j <= 9; ++j)
                                {
                                        sum += map[i][j];
                                        if(map[i][j] == 0){z_p = j;z_time++;}
                                }
                                if(z_time == 1 )
                                {
                                        map[i][z_p] = s - sum;
                                        zero--;
                                        if(zero == 0)goto print;
                                }
                                sum = 0;
                                z_time = 0;
                                for(j = 1;j <= 9; ++j)
                                {
                                        sum += map[j][i];
                                        if(map[j][i] == 0){z_p = j;z_time++;}
                                }
                                if(z_time == 1 )
                                {
                                        map[z_p][i] = s - sum;
                                        zero--;
                                        if(zero == 0)goto print;
                                }
                        }
                        for(i = 0; i <= 8; i++)
                        {
                                sum = 0;
                                z_time = 0;
                                for(j = nine[i][0][0]; j <= nine[i][1][0]; j++)
                                        for(k = nine[i][0][1]; k <= nine[i][1][1]; k++)
                                        {
                                                sum += map[j][k];
                                                if(map[j][k] == 0){zz[0] = j,zz[1] = k; z_time++;}
                                        }
                                if(z_time == 1 )
                                {
                                        map[zz[0]][zz[1]] = s - sum;
                                        zero--;
                                        if(zero == 0)goto print;
                                }
                        }
                }
print:
                for(i = 1;i <= 9; ++i)
                {
                        for(j = 1;j <= 9; ++j)cout<<map[i][j];
                        cout<<endl;
                }
                cout<<endl;
        }
        return 0;
}
