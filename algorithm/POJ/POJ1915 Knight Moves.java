

import java.io.*;
import java.util.*;

public class Main 
{
    private static int[][] stage = new int[305][305];
    private static int size;
    private static int x,y;
    private static final int max = 2100000000;
    private static void setValue(int i, int j, int value)
    {
        if(i>=0 && i<size)
        {
            if(j>=0 && j<size)
            {
                if(-1==stage[i][j])
                {
                    stage[i][j] = value;
                }
            }
        }
    }
    private static boolean searchTarget(int num)
    {
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(stage[i][j]==num)
                {
                    if(i==x && j==y)
                    {
                        return true;
                    }
                    setValue(i-2, j-1, num+1);
                    setValue(i+2, j-1, num+1);
                    setValue(i-2, j+1, num+1);
                    setValue(i+2, j+1, num+1);
                    setValue(i-1, j-2, num+1);
                    setValue(i+1, j-2, num+1);
                    setValue(i-1, j+2, num+1);
                    setValue(i+1, j+2, num+1);
                }
            }
        }
        return false;
    }
    public static void main(String args[])
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int times;
        times = cin.nextInt();
        for(int t=0;t<times;t++)
        {
            size = cin.nextInt();
            for(int i=0;i<size;i++)
            {
                for(int j=0;j<size;j++)
                {
                    stage[i][j] = -1;
                }
            }
            x = cin.nextInt();
            y = cin.nextInt();
            stage[x][y] = 0;
            x = cin.nextInt();
            y = cin.nextInt();
            if(0==stage[x][y])
            {
                System.out.println(0);
                continue;
            }
            int i = 0;
            while(searchTarget(i++)==false);
            System.out.println(stage[x][y]);
        }
    }
}
