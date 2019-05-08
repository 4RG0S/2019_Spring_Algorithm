import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

import static java.lang.StrictMath.sqrt;


public class Main {


    public static void main(String[] args) throws IOException {
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(buffer.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] arr = new int[N];

        st = new StringTokenizer(buffer.readLine());
        for(int i=0; i<N;i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        double correct = Double.MAX_VALUE;

        while(K<=N){

            for(int i=0;i<=N-K;i++){

                double average = average(i,K,arr);

                double deviation = Deviation(i,K,arr,average);

                correct = Math.min(correct,deviation);

            }
            K++;
        }
        double newResult = Double.parseDouble(String.format("%.11f", correct));
        System.out.println(correct);

    }

    static double average(int first,int num,int[] arr){
        double result =0;

        for(int i=first; i<first+num;i++){
            result+= arr[i];
        }
        return result/(num);
    }
    static double Deviation(int first,int num, int[] arr, double avr){
        double result =0;
        for(int i=first; i<first+num;i++){
            result+= (arr[i]-avr)*(arr[i]-avr);
        }
        return sqrt(result/(num));
    }

}