package SRM144;

public class Time 
{
    public String whatTime(int seconds)
    {
        String time;
        time = ":" + seconds%60;
        seconds /= 60;
        time = ":" + seconds%60 + time;
        seconds /= 60;
        time = seconds + time;
        return time;
    }
}
