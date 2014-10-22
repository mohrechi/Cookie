

import java.util.*;
import java.io.*;

public class Main 
{
    private static int[][] puzzle = new int[5][6];
    private static int[][] answer = new int[5][6];
    private static void setArrayValue(int i, int j, int value)
    {
        if(i>=0 && i<5 && j>=0 && j<6)
        {
            answer[i][j]=value;
        }
    }
    private static int getArrayValue(int i, int j, int type)
    {
        if(i>=0 && i<5 && j>=0 && j<6)
        {
            if(type == 0)
            {
                return puzzle[i][j];
            }
            else
            {
                return answer[i][j];
            }
        }
        return 0;
    }
    private static void findAnswer()
    {
        while(true)
        {
            establishAnswer();
            if(isAnswer())
            {
                return;
            }
            answer[0][0]++;
            for(int i=0;i<5;i++)
            {
                if(answer[0][i]>1)
                {
                    answer[0][i]=0;
                    answer[0][i+1]++;
                }
            }
        }
    }
    private static void establishAnswer()
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<6;j++)
            {
                int temp = getArrayValue(i, j, 1) + getArrayValue(i, j-1, 1) + getArrayValue(i, j+1, 1) + getArrayValue(i-1, j, 1) + getArrayValue(i, j, 0);
                if(temp==1 || temp==3 || temp==5)
                {
                    setArrayValue(i+1, j, 1);
                }
                else
                {
                    setArrayValue(i+1, j, 0);
                }
            }
        }
    }
    public static boolean isAnswer()
    {
        for(int i=0;i<6;i++)
        {
            int temp = getArrayValue(4, i, 0) + getArrayValue(4, i, 1) + getArrayValue(4, i-1, 1) + getArrayValue(4, i+1, 1) + getArrayValue(3, i, 1);
            if(temp==1 || temp==3 || temp==5)
            {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int times, t;
        times = cin.nextInt();
        for(t = 1; t <= times; t++)
        {
            for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 6; j++)
                {
                    puzzle[i][j] = cin.nextInt();
                    answer[i][j] = 0;
                }
            }
            findAnswer();
            System.out.println("PUZZLE #" + t);
            for(int i = 0; i < 5; i++)
            {
                System.out.print(answer[i][0]);
                for(int j = 1; j < 6; j++)
                {
                    System.out.print(" " + answer[i][j]);
                }
                System.out.println();
            }
        }
    }
}
