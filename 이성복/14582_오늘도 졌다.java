import java.util.Scanner;

public class baseball {

   public static void main(String[] args) {
      Scanner input = new Scanner(System.in);
      
      int[] lotte = new int[9];   //초
      int[] hanwha = new int[9];   //말
      
      int lotteScore = 0;
      int hanwhaScore = 0;
      int flag = 0;
      
      for(int i = 0; i < 9; i++) {   //초 점수 입력
         lotte[i] = input.nextInt();
      }
      for(int i = 0; i < 9; i++) {   //말 점수 입력
         hanwha[i] = input.nextInt();
      }
      
      for(int i = 0; i < 9; i++) {
         lotteScore += lotte[i];
         if(lotteScore > hanwhaScore) {   //1회초에 점수도 이기고 있는 순간으로 기록
            flag = 1;
         }
         hanwhaScore += hanwha[i];
      }
      
      if((lotteScore < hanwhaScore) && flag == 1) {
         System.out.println("Yes");
      }
      else
         System.out.println("No");
         
   }
}