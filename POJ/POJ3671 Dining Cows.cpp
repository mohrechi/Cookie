#include <iostream>
using namespace std ;

const int MaxSize = 30000+10 ;
int num[MaxSize], best[MaxSize] ;

inline int max( int a, int b )
{
    return a>b ? a:b ;
}

int LAS( int numcnt )
{
    int i, j, ans=0 ;
    best[0] = num[0] ;
    for( i=0; i<numcnt; ++i )
    {
        for( j=0; j<ans; ++j )
        {
            if( num[i] < best[j] )
            {
                best[j] = num[i] ;
                break ;
            }
        }
        if( j == ans )
        {
            best[j] = num[i] ;
            ++ans ;
        }
    }
    return ans ;
}

int main()
{
    int numcnt, i ;
    while( cin >> numcnt )
    {
        for( i=0; i<numcnt; ++i )
        {
            cin >> num[i] ;
            best[i] = -1 ;
        }
        cout << numcnt-LAS( numcnt ) << endl ;
    }
    return 0 ;
}
