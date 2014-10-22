package SRM504_5;

public class TheNumbersWithLuckyLastDigit 
{
    public int find(int n)
    {
        switch(n%10)
        {
            case 0: return n>10?5:-1;
            case 1: return n>10?2:-1;
            case 2: return n>10?3:-1;
            case 3: return n>20?5:-1;
            case 4: return 1;
            case 5: return n>10?3:-1;
            case 6: return n>10?4:-1;
            case 7: return 1;
            case 8: return 2;
            case 9: return n>10?4:-1;
        }
        return -1;
    }
}
