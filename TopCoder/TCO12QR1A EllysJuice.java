package TCO12QR1A;

public class EllysJuice {
	public String[] getWinners(String[] players){
		String[] xingming = new String[players.length];
		int[] cishu = new int[players.length];
		String[] jieguo = new String[players.length];
		int renshu = 0;
		int jieguoshu = 0;
		for(int i=0;i<players.length;++i)
		{
			int j;
			for(j=0;j<renshu;++j)
			{
				if(xingming[j].compareTo(players[i]) == 0)
				{
					break;
				}
			}
			if(j==renshu){
				xingming[renshu] = players[i];
				cishu[renshu++] = 1;
			}else{
				cishu[j] ++;
			}
		}
		for(int i=0;i<renshu;++i)
		{
			for(int j=i+1;j<renshu;++j){
				if(cishu[i] < cishu[j]){
					int temp = cishu[j];
					cishu[j] = cishu[i];
					cishu[i] = temp;
					String ts = xingming[j];
					xingming[j] = xingming[i];
					xingming[i] = ts;
				}
			}
		}
		for(int i=0;i<renshu;++i){
			double zhujue = 0.0;
			double a = 1.0, b = 1.0;
			int j;
			for(j=1;j<=cishu[i];++j)
			{
				if((j&1)>0){
					a/=2;
					zhujue += a;
				}else{
					b/=2;
					zhujue += b;
				}
			}
			System.out.println(zhujue);
			int k;
			for(k=0;k<renshu;++k){
				double peijue = 0.0;
				if(i!=k){
					for(int l=0;l<cishu[k];++l)
					{
						if((j&1)>0){
							a/=2;
							peijue += a;
						}else{
							b/=2;
							peijue += b;
						}
					}
				}
				System.out.println(k + " " + peijue);
				if(peijue >= zhujue){
					break;
				}
			}
			if(k == renshu){
				jieguo[jieguoshu++] = xingming[i];
			}
		}
		String[] daan = new String[jieguoshu];
		for(int i=0;i<jieguoshu;++i)
		{
			daan[i] = jieguo[i];
		}
		for(int i=0;i<daan.length;++i){
			for(int j=i+1;j<daan.length;++j){
				if(daan[i].compareTo(daan[j])>0){
					String temp = daan[i];
					daan[i] = daan[j];
					daan[j] = temp;
				}
			}
		}
		return daan;
	}
}//250/143.11
