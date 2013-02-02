import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(new BufferedInputStream(System.in));
        String s;
        while(cin.hasNext())
        {
        	s=cin.next();
        	if(s.length()==1&s.charAt(0)=='0')
        	{
        		System.out.println("such number is impossible!");
        		continue;
        	}
        	int min=0;
        	for(int i=0;i<s.length();i++)
        	{
        		if(s.charAt(i)>='0'&s.charAt(i)<='9')
        		{
        			int t=s.charAt(i)-47;
        			if(t>min)min=t;
        		}
        		if(s.charAt(i)>='A'&s.charAt(i)<='Z')
        		{
        			int t=s.charAt(i)-54;
        			if(t>min)min=t;
        		}
        		if(s.charAt(i)>='a'&s.charAt(i)<='z')
        		{
        			int t=s.charAt(i)-60;
        			if(t>min)min=t;
        		}
        	}
        	int i;
        	for(i=min;i<63;i++)
        	{
        		int t=0;
        		for(int j=s.length()-1;j>=0;j--)
        		{
        			if(s.charAt(j)>='0'&s.charAt(j)<='9')
            		{
        				t+=(s.charAt(j)-48);
            		}
        			if(s.charAt(j)>='A'&s.charAt(j)<='Z')
            		{
        				t+=(s.charAt(j)-55);
            		}
        			if(s.charAt(j)>='a'&s.charAt(j)<='z')
            		{
        				t+=(s.charAt(j)-61);
            		}
        		}
        		if(t%(i-1)==0) break;
        	}
        	if(i==63)System.out.println("such number is impossible!");
        	else System.out.printf("%d\n",i);
        }
    }
}
