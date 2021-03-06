import java.util.Scanner;

public class Main {
    static int N,M;
    static int D[] = new int[1001];//가로등 위치
    static int W[] = new int[1001];//전력소비량
    static int W_Sum[] = new int[1001];//전력 총 소비량
    static int DP[][][] = new int[1001][1001][2];//DP[][][0]은 왼쪽 최솟값, DP[][][1]은 오른쪽 최솟값
    static int min = Integer.MAX_VALUE;
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner in = new Scanner(System.in);
        N = in.nextInt();//가로등의 개수
        M = in.nextInt();//처음 위치한 가로등 번호

        for(int i = 1; i <= N; i++) {
            D[i] = in.nextInt();
            W[i] = in.nextInt();
            W_Sum[i] = W_Sum[i-1]+W[i];
        }//입력받기
        for(int i = 0; i < N+1; i++) {
            for(int j = 0; j < N+1;j++) {
                for (int w = 0; w <2; w++) {
                    DP[i][j][w] = -1;
                }
            }
        }
        System.out.println(minW(M,M,0));

    }
    public static int minW(int left, int right, int select) {
        int now;
        if(select==0) now = left;
        else now = right;
        if(left==1&&right==N) return 0; // 왼쪽 오른쪽 다 돌았으므로
        if(DP[left][right][select] != -1) {
            return DP[left][right][select];
        }//원래 최솟값 구해놓은게 있다면 그 값을 return

        if(left-1 >=1)
            min = Math.min(min,minW(left-1,right,0)+(D[now]-D[left-1])*(W_Sum[N]-W_Sum[right]+W_Sum[left-1]));
        if(right+1 <=N)
            min = Math.min(min,minW(left,right+1,1)+(D[right+1]-D[now])*(W_Sum[N]-W_Sum[right]+W_Sum[left-1]));
        DP[left][right][select] = min;
        return min;
    }
}
