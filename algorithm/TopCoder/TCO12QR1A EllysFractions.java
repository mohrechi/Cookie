package TCO12QR1A;

public class EllysFractions {
	boolean prime[] = new boolean[251];
	
	private void getPrime()
	{
		for(int i=2;i<=250;++i){
			prime[i] = true;
		}
		prime[0] = prime[1] = false;
		for(int i=4;i<=250;i+=2){
			prime[i] = false;
		}
		for(int i=3;i<=250;i+=2){
			for(int j=3;i*j<=250;j+=2){
				prime[i*j] = false;
			}
		}
	}
	
	private long getNumber(int n){
		int primeArray[] = new int[n];
		int time[] = new int[n];
		int primeNumber = 0;
		for(int i=2;i<=n;++i){
			if(prime[i]){
				primeArray[primeNumber] = i;
				time[primeNumber++] = 1;
			}
		}
		return (long)Math.pow(2, primeNumber - 1) + 1;
	}
	
	public long getCount(int N){
		long ans = 0;
		getPrime();
		for(int i=2;i<=N;++i){
			ans += getNumber(i);
		}
		return ans;
	}
}//500/274.31
