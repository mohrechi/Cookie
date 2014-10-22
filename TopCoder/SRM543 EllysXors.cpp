class EllysXors
{
public:
    long long getXor(long long L,long long R)
    {
        --L;
        long long ans=0;
        for(long long i=0;(1LL<<i)<=R;++i)
            ans+=((R/(1LL<<(i+1))*(1LL<<i)+((R%(1LL<<(i+1))>=(1LL<<i))?(R%(1LL<<(i+1)))-(1LL<<i)+1:0))-(L/(1LL<<(i+1))*(1LL<<i)+((L%(1LL<<(i+1))>=(1LL<<i))?(L%(1LL<<(i+1)))-(1LL<<i)+1:0)))&1?1LL<<i:0;
        return ans;
    }
};
