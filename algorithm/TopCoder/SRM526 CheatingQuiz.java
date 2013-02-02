package SRM526;

public class CheatingQuiz 
{
    public int[] howMany(String answers)
    {
        boolean A = false;
        boolean B = false;
        boolean C = false;
        int number = 0;
        int[] result = new int[answers.length()];
        for(int i=answers.length()-1;i>=0;--i)
        {
            switch(answers.charAt(i))
            {
                case 'A':
                    if(!A)
                    {
                        A = true;
                        ++number;
                    }
                    break;
                case 'B':
                    if(!B)
                    {
                        B = true;
                        ++number;
                    }
                    break;
                case 'C':
                    if(!C)
                    {
                        C = true;
                        ++number;
                    }
                    break;
            }
            result[i] = number;
        }
        return result;
    }
}
//233.99/250