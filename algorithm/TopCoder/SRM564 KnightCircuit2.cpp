#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

class KnightCircuit2
{
public:
    int maxSize(int col, int row)
    {
        if (row > col) swap(row, col);
		if (row == 3)
		    if(col == 3)
                return 8;
            else if(col < 3)
                return 1;
		if (row == 2)
            return (col + 1) >> 1;
		if (row == 1)
            return 1;
		return row * col;
    }
}; //249.36
