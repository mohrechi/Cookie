import java.io.BufferedInputStream;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.Scanner;

class Fraction
{
	public BigInteger high = BigInteger.ZERO;
	public BigInteger low = BigInteger.ONE;

	public boolean isZero()
	{
		return high.compareTo(BigInteger.ZERO) == 0;
	}

	public void simplify()
	{
		BigInteger g = low.gcd(high);
		low = low.divide(g);
		high = high.divide(g);
	}

	public void print()
	{
		System.out.print(high.toString() + "/" + low.toString() + " ");
	}

	public void printDecimal()
	{
		DecimalFormat df = new DecimalFormat("0.00");
		double a = high.doubleValue();
		double b = low.doubleValue();
		System.out.print(df.format(a / b) + " ");
	}

	public Fraction copy()
	{
		Fraction r = new Fraction();
		r.high = new BigInteger(high.toString());
		r.low = new BigInteger(low.toString());
		return r;
	}
}

public class Main
{
	private static Fraction[][] mat = new Fraction[500][500];
	private static int n, nn, m, k;
	private static Fraction[] ans = new Fraction[500];

	private static Fraction fracAdd(Fraction a, Fraction b)
	{
		Fraction c = new Fraction();
		c.low = a.low.multiply(b.low);
		c.high = b.low.multiply(a.high).add(a.low.multiply(b.high));
		c.simplify();
		return c;
	}

	private static Fraction fracSubtract(Fraction a, Fraction b)
	{
		Fraction c = new Fraction();
		c.low = a.low.multiply(b.low);
		c.high = b.low.multiply(a.high).subtract(a.low.multiply(b.high));
		c.simplify();
		return c;
	}

	private static Fraction fracMultiply(Fraction a, Fraction b)
	{
		Fraction c = new Fraction();
		c.low = a.low.multiply(b.low);
		c.high = a.high.multiply(b.high);
		c.simplify();
		return c;
	}

	private static Fraction fracDivide(Fraction a, Fraction b)
	{
		Fraction c = new Fraction();
		c.low = a.low.multiply(b.high);
		c.high = a.high.multiply(b.low);
		c.simplify();
		return c;
	}

	private static int getPos(int x, int y)
	{
		return x * n + y;
	}

	private static void setMatrix(int x0, int y0, int x1, int y1, int high, int low)
	{
		Fraction f = new Fraction();
		f.high = BigInteger.valueOf(high);
		f.low = BigInteger.valueOf(low);
		if(x1 == m)
		{
			if(y1 == 0)
			{
				mat[getPos(x0, y0)][nn] = fracAdd(mat[getPos(x0, y0)][nn], f);
			}
		}
		else
		{
			mat[getPos(x0, y0)][getPos(x1, y1)] = fracSubtract(mat[getPos(x0, y0)][getPos(x1, y1)], f);
		}
	}

	private static void build()
	{
		for(int i=0;i<=nn;++i)
		{
			for(int j=0;j<=nn;++j)
			{
				mat[i][j] = new Fraction();
			}
		}
		for(int i=0;i<m;++i)
		{
			for(int j=0;j<n;++j)
			{
				setMatrix(i, j, i, j, -1, 1);
			}
			setMatrix(i, 0, i+1, 0, 1, 4);
			setMatrix(i, 0, 1, n-3, 3, 4);
			setMatrix(i, 1, i+1, n-3, 1, 4);
			setMatrix(i, 2, i+1, n-2, 1, 4);
			setMatrix(i, 3, i+1, n-1, 1, 4);
			setMatrix(i, 1, 1, 0, 1, 4);
			setMatrix(i, 2, 1, 0, 1, 4);
			setMatrix(i, 3, 1, 0, 1, 4);
			setMatrix(i, 1, 1, n-2, 2, 4);
			setMatrix(i, 2, 1, n-2, 1, 4);
			setMatrix(i, 2, 1, n-1, 1, 4);
			setMatrix(i, 3, 1, n-1, 2, 4);
			for(int j=4;j<n;++j)
			{
				setMatrix(i, j, i+1, j-3, 1, 4);
				setMatrix(i, j, 1, j-3, 3, 4);
			}
		}
	}

	private static void solve()
	{
		int i=0;
		for(int j=0;j<nn;++j)
		{
			for(int k=nn;k>=j;--k)
			{
				mat[i][k] = fracDivide(mat[i][k], mat[i][j]);
			}
			for(int k=i+1;k<nn;++k)
			{
				for(int l=j+1;l<=nn;++l)
				{
					mat[k][l] = fracSubtract(mat[k][l], fracMultiply(mat[i][l], mat[k][j]));
				}
			}
			++ i;
		}
		for(--i;i>=0;--i)
		{
			ans[i] = mat[i][nn].copy();
			for(int j=i+1;j<nn;++j)
			{
				ans[i] = fracSubtract(ans[i], fracMultiply(mat[i][j], ans[j]));
			}
			ans[i] = fracDivide(ans[i], mat[i][i]);
		}
		printAnswer(getPos(0, k-1));
	}

	private static void printAnswer(int pos)
	{
		DecimalFormat df = new DecimalFormat("0.000000");
		ans[pos].simplify();
		double a = ans[pos].high.doubleValue();
		double b = ans[pos].low.doubleValue();
		System.out.println(df.format(a / b));
	}

	public static void main(String args[]) {
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int t = cin.nextInt();
		for(int cas=1;cas<=t;++cas)
		{
			n = cin.nextInt();
			m = cin.nextInt();
			k = cin.nextInt();
			nn = m * n;
			build();
			System.out.print("Case #" + cas + ": ");
			solve();
		}
	}
}
