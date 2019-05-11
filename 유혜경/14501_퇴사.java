import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		int T[] = new int[20];
		int P[] = new int[20];
		int dp[] = new int [20];
		int max = 0;
		for(int i = 1; i < N+1; i++) {
			T[i] = in.nextInt();
			P[i] = in.nextInt();
			dp[i] = P[i];
		}
		for(int i = 1; i < N+1; i++) {
			if(T[i]+i<=N+1) {
				max = max>=P[i]?max:P[i];
				for(int j = 1; j < i; j++) {
					if(i>=j+T[j]&&i!=j) {
						dp[i] = P[i]+dp[j] >= dp[i] ? P[i]+dp[j]:dp[i];
						max = max >= dp[i]?max:dp[i];
					}
				}
			}
		}
		System.out.println(max);
	}
}