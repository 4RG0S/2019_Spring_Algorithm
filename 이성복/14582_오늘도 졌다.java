import java.util.Scanner;

public class baseball {

   public static void main(String[] args) {
      Scanner input = new Scanner(System.in);
      
      int[] lotte = new int[9];   //��
      int[] hanwha = new int[9];   //��
      
      int lotteScore = 0;
      int hanwhaScore = 0;
      int flag = 0;
      
      for(int i = 0; i < 9; i++) {   //�� ���� �Է�
         lotte[i] = input.nextInt();
      }
      for(int i = 0; i < 9; i++) {   //�� ���� �Է�
         hanwha[i] = input.nextInt();
      }
      
      for(int i = 0; i < 9; i++) {
         lotteScore += lotte[i];
         if(lotteScore > hanwhaScore) {   //1ȸ�ʿ� ������ �̱�� �ִ� �������� ���
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