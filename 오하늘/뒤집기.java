import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

//		Scanner s = new Scanner(System.in);
//		int N = s.nextInt();
//		int M = s.nextInt();
//		
//		int[][] array = new int[N][M];
//		int[][] tmp = new int[N][M];
//		
//		String a = s.nextLine();
//		for(int i=0;i<N;i++) {
//			a = s.nextLine();
//			for(int j=0;j<M;j++) {
//				array[i][j] = a.charAt(j);
//			}
//		}
//		
//		// 각 행에 대해서 첫 칸부터 좌우 그리고 상하 비교하기 
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<M;j++) {
//				if(j+1 < M && array[i][j] != array[i][j+1]) { // 오른쪽과 비교 
//					tmp[i][j] = 1;
//					tmp[i][j+1] = 1;
//				}	
//				if(i+1 < N && array[i][j] != array[i+1][j]) { // 아래와 비교 
//					tmp[i][j] = 1;
//					tmp[i+1][j] = 1;
//				}	
//			}
//		}
//		
//		// 확정된 칸의 수 갯수 
//		int convictionNum = 0;
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<M;j++) 
//				if(tmp[i][j] == 1) convictionNum++;
//		}
//			
//		// 확신된 칸을 제외한 나머지킨에 대해 경우의 수 구함 1,000,000,007
//		long aaa = (long)Math.pow(2, N*M - convictionNum);
//		System.out.println( aaa % 1000000007);
		
		long aaa = (long)Math.pow(2, 2000);
		
		aaa = mpower(2, 4000, 1000000007);
		System.out.println( aaa);
		//System.out.println( aaa % 1000000007);

			
	}
	// b^n mod m
	public static int mpower(int b, int n, int m) {
	    if (n == 0) {
	        return 1;
	    }
	    if (n % 2 == 0) {
	        int next = mpower(b, half(n), m);
	        return square(next) % m;
	    }

	    int next = mpower(b, half(n), m);
	    return ((square(next) % m) * (b % m)) % m;
	}

	public static int half(int n) {
	    return (int) n / 2;
	}

	public static int square(int n) {
	    return n * n;
	}
}
