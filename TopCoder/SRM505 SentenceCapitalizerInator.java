package SRM505;

public class SentenceCapitalizerInator 
{
    public String fixCaps(String input)
    {
        boolean upper = true;
        String output="";
        for(int i=0;i<input.length();i++)
        {
            if(upper && isAlpha(input.charAt(i)))
            {
                upper = false;
                output+=(char)(input.charAt(i)+'A'-'a');
            }
            else if(input.charAt(i)=='.')
            {
                upper=true;
                output+=input.charAt(i);
            }
            else
            {
                output+=input.charAt(i);
            }
        }
        return output;
    }
    
    public boolean isAlpha(char ch)
    {
        return ch>='a' && ch<='z';
    }
}
