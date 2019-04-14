import java.util.Arrays;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.List;


public class Main {


    public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N;
    N = sc.nextInt();
    System.out.println(calculator(N));

    }

    public static long calculator(int N){
        //너무 어렵게 생각해서 한번 틀렸다.
        //그냥 매번 정사각형이 만들어지므로
        //한 변의 갯수만 구하면 모든 점의 갯수를 구할수 있다.
        long line = 2;
        while(N!=0){
            N--;
            line = line*2-1;

        }

        return line*line;
    }
}
