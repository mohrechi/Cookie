#include<stdio.h>
#include<string.h>

int n,num[25][1024],m;
int main( )
{
    int t;
    scanf( "%d",&t );
    while( t-- )
    {
        scanf( "%d%d",&n,&m );
        memset( num,0,sizeof( num ) );
        for( int i = 1; i <= n; ++i )
            for( int j = 1; j <= m; ++j )
                scanf( "%d",&num[i][j] );
        for( int i = n; i; --i )
            for( int j = m; j; --j )
            {
                int max = -1111;
                if( i == n&& j == m )
                    max  = 0;
                if( i < n )
                    if( num[i+1][j] > max )
                        max = num[i+1][j];
                if( j < m )
                    if( num[i][j+1] > max )
                        max = num[i][j+1];
            int c = j + j;
            while( c <= m )
            {
                if( num[i][c] > max )
                    max = num[i][c];
                c += j;
            }
            num[i][j] += max;
        }
        printf( "%d\n",num[1][1] );
    }
    return 0;
}
