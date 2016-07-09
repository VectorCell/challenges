/*
 * Brandon Smith
 * CS 109 - Competitive Programming - Spring 2016
 * 
 * Problem Set 6 - Codeforces 166E
 */

import java.util.Scanner;
import java.math.BigInteger;

public class PS6Codeforces166E
{
	public static final BigInteger PRIME = new BigInteger("1000000007");
	public static final BigInteger THREE = new BigInteger("3");

	public static BigInteger solve(int n)
	{
		BigInteger d[] = new BigInteger[n + 1];
		for (int k = 0; k < d.length; ++k)
			d[k] = BigInteger.ZERO;
		BigInteger c = THREE;
		for (int i = 3; i < n + 1; ++i) {
			d[i] = c.subtract(d[i - 1]).mod(PRIME);
			c = c.multiply(THREE);
		}
		if (n <= 1) {
			return BigInteger.ZERO;
		} else {
			return c.subtract(d[n]).mod(PRIME);
		}
	}

	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		System.out.println(solve(scan.nextInt()));
	}
}
