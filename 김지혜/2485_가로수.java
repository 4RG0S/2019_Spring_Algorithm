import java.util.Arrays;
import java.util.LinkedList;
import java.util.Scanner;

public class Main {

   
   public static void main(String[] args) {
      
	   Scanner scan = new Scanner(System.in);
	   
	   int n = scan.nextInt();
	   int[] now = new int[n];
	   
	   for(int i=0;i<n;i++) now[i]=scan.nextInt();
	   
	   Arrays.sort(now);
	   
	   int[] space = new int[n-1];
	   for(int i=1;i<n;i++)
	   {
		   space[i-1]=now[i]-now[i-1];
	   }
	   
	   int ngcd=gcd(space[0], space[1]);
	   
	   for(int i=2;i<n-1;i++)
		   ngcd=gcd(ngcd, space[i]);
	   
	   int answer=0;
	   
	   for(int i=now[0];i<=now[now.length-1];i=i+ngcd)
		  answer++;
	   
	   answer-=n;
	   
	   System.out.println(answer);
	   
   }

   public static int gcd(int a, int b)
   {
	   int big, small;
	   if(a>b) {big=a; small=b;}
	   else {big=b; small=a;}
	   
	   while(small>0)
	   {
		   int rem = big%small;
		   big=small; small=rem;
	   }
	   return big;
   }

   
}