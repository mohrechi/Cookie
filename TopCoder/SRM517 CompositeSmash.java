package SRM517;

public class CompositeSmash 
{
    public String thePossible(int N, int target)
    {
        if(N == target || search(N, target))
        {
            return "Yes";
        }
        return "No";
    }
    
    private boolean search(int N, int target)
    {
        int number, firstFactor, secondFactor;
        number = 0;
        firstFactor = 1;
        for(int i=2;i<N/2;++i)
        {
            if(N % i == 0)
            {
                number ++;
                firstFactor = i;
            }
        }
        if(number>1)
        {
            for(int i=2;i<N/2;++i)
            {
                if(N % i == 0)
                {
                    firstFactor = i;
                    secondFactor = N / firstFactor;
                    if(search(firstFactor, target) || search(secondFactor, target))
                    {
                        return true;
                    }
                }
            }
        }
        else
        {
            secondFactor = N / firstFactor;
            if(firstFactor == target || secondFactor == target)
            {
                return true;
            }
        }
        return false;
    }
}
//206.98/255
