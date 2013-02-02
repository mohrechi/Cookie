package SRM513;

public class TrainingCamp 
{
    public String[] determineSolvers(String[] attendance, String[] problemTopics)
    {
        String result[] = new String[attendance.length];
        boolean permit[] = new boolean[attendance.length];
        for(int i=0;i<attendance.length;i++)
        {
            result[i] = "";
        }
        for(int i=0;i<problemTopics.length;i++)
        {
            for(int j=0;j<permit.length;j++)
            {
                permit[j] = true;
            }
            for(int j=0;j<attendance[0].length();j++)
            {
                for(int k=0;k<attendance.length;k++)
                {
                    if(permit[k] && problemTopics[i].charAt(j) == 'X')
                    {
                        if(attendance[k].charAt(j) == '-')
                        {
                            permit[k] = false;
                        }
                    }
                }
            }
            for(int j=0;j<attendance.length;j++)
            {
                if(permit[j])
                {
                    result[j] += 'X';
                }
                else
                {
                    result[j] += '-';
                }
            }
        }
        return result;
    }
}
//204.74/250