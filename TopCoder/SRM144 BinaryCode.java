package SRM144;

public class BinaryCode 
{
    public String[] decode(String message)
    {
        String output[] = new String[2];
        message= "0" + message + "0";
        output[0] = calcCode(message, 0);
        output[1] = calcCode(message, 1);
        return output;
    }
    
    public String calcCode(String message, int first)
    {
        String output = "";
        int i, temp[] = new int[100];
        temp[0] = 0;
        temp[1] = first;
        temp[message.length()] = 0;
        for(i=1;i<message.length()-1;i++)
        {
            int t = temp[i-1] + temp[i];
            int ch = message.charAt((i)) - '0';
            if(ch==t+1)
            {
                if(i==message.length()-2)
                {
                    break;
                }
                temp[i+1] = 1;
            }
            else if(ch==t)
            {
                temp[i+1] = 0;
            }
            else
            {
                break;
            }
        }
        if(i<message.length()-1)
        {
            output = "NONE";
        }
        else
        {
            for(i=1;i<message.length()-1;i++)
            {
                output += temp[i];
            }
        }
        return output;
    }
}