import java.util.Scanner;
import java.util.List;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
	public static void main (String args[]) throws NumberFormatException, IOException {
		
		Scanner sc = new Scanner(System.in);
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(reader.readLine());
	    //입력을 받았습니다.
		System.out.println(calculator(n));
	}
	
	public static long calculator(long N ) {
		int pisano = 1500000;
        //피사노 주기를 사용했습니다.
        //피사노 주기란 피보나치의 나머지는 항상 어떠한 주기를 가지며
        //그 주기를 구하는 공식은 아래와 같습니다.
		//M = 10k 일 때, k > 2 라면, 주기는 항상 15 × 10k-1
        //고로 이번문제의 피사노 주기는 1500000 입니다.
		int[] array = new int[pisano];
		array[0]=0;
		array[1]=1;
	
		for(int i=2; i<pisano;i++) {
			array[i] = (array[i-1]+array[i-2])%1000000;
		}
        //나머지는 피보나치 수열 구할때와 동일하게 하면 됩니다.
		return array[(int)(N%pisano)];
	}
}