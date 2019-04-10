import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		in.nextLine(); //개행문자 때문에
		String st;// TODO Auto-generated method stub
		for(int i = 0; i < T; i++) {
			st = in.nextLine();
			Stack<Character> stack = new Stack<Character>();
			for(int n = 0; n < st.length(); n++) {
				if(st.charAt(n)=='(') stack.push(st.charAt(n));
				if(st.charAt(n)==')') {
					if(stack.isEmpty()) {
						stack.push(st.charAt(n));
						break;
					}
					else
						stack.pop();
				}
			}
			if(stack.isEmpty()) System.out.println("YES");
			else System.out.println("NO");
		}
	}
}