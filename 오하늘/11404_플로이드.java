import java.util.Scanner;

public class Main {

	final static int INF = 100000000; // infinite
	public static void main(String[] args) {

		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		
		int[][] fw = new int[n][n];
		
		for(int i=0;i<n;i++) { 	// 인접행렬 초기화 
			for(int j=0;j<n;j++) {
				fw[i][j] = (i == j ? 0 : INF);
			}
		}
		
		for(int i=0;i<m;i++) {	
			int v1 = s.nextInt() - 1;
			int v2 = s.nextInt() - 1;
			int cost = s.nextInt();

			if(fw[v1][v2] > cost)
				fw[v1][v2] = cost;
		}
		
		// 최단 경로 구하기 
		for(int k=0;k<n;k++) {
			for(int a=0;a<n;a++) {
				for(int b=0;b<n;b++) {
					if(fw[a][b] > fw[a][k] + fw[k][b])
						fw[a][b] =  fw[a][k] + fw[k][b];
				}
			}
		}
		
		
		// 출력하기
		for(int i=0;i<n;i++) {	
			for(int j=0;j<n;j++) {
				if(fw[i][j] == INF)
					System.out.print(0 + " ");
				else
					System.out.print(fw[i][j] + " ");
			}
			System.out.println();
		}
		
		
	}

}
