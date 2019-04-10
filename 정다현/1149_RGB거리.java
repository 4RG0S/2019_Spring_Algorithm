import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int house = scanner.nextInt();
		
		int[][] prices = new int[house][3];
		
		for(int i = 0 ; i <  house ; i ++) {
			for(int j = 0; j <3 ; j++) {
				prices[i][j] = scanner.nextInt();
			}
		}
		
		for(int i = 0 ; i < house - 1 ; i++) {
			for(int j = 0 ; j < 3 ; j++) {
				if(j == 0) {
					if(prices[i][1] <prices[i][2] ) {
						prices[i+1][0] += prices[i][1];
					} else {
						prices[i+1][0] += prices[i][2];
					}
				}
				if(j == 1) {
					if(prices[i][0] <prices[i][2] ) {
						prices[i+1][1] += prices[i][0];
					} else {
						prices[i+1][1] += prices[i][2];
					}
				}
				if(j == 2) {
					if(prices[i][0] <prices[i][1] ) {
						prices[i+1][2] += prices[i][0];
					} else {
						prices[i+1][2] += prices[i][1];
					}
				}

			}
		}
		
		int tmp = prices[house-1][0];
		for(int i = 0 ; i < 3; i++) {
			if(tmp > prices[house-1][i]) {
				tmp = prices[house-1][i];
			}
		}
		System.out.println(tmp);
			
	}

}