import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Solution {

	public static void main(String arg[]) {
		// TODO Auto-generated constructor stub
		Scanner cin = new Scanner(System.in);
		int a = cin.nextInt();
		int b = cin.nextInt();
		System.out.println(BigInteger.valueOf(a).pow(b).subtract(BigInteger.valueOf(b).pow(a)));
	}

}
