

import java.io.*;
import java.util.*;

public class Main 
{
    private static int[] answer = new int[46];
    private static void initAnswer()
    {
        answer[0] = 1;
        answer[1] = 2;
        for(int i=2;i<45;i++)
        {
            answer[i] = answer[i-1] + answer[i-2];
        }
    }
    public static void main(String args[])
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        int times;
        times = cin.nextInt();
        initAnswer();
        for(int t=1;t<=times;t++)
        {
            int temp = cin.nextInt();
            System.out.println("Scenario #" + t + ":");
            System.out.println(answer[temp]);
            System.out.println();
        }
    }
}
