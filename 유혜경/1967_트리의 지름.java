import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Stack;

public class Main {
	private static class Node {
		private int child;
		private int len;
		public Node(int child, int len) {
			this.child = child;
			this.len = len;
		}
	}
	public static class Graph{
		ArrayList<Node>[] graph;
		boolean[] visit;
		int[] digit;
		public Graph(int size) {
			visit = new boolean[size];
			digit = new int[size];
			Arrays.fill(digit, 0);
			graph = new ArrayList[size];
			for(int i = 0; i < size; i++)
				graph[i] = new ArrayList<Node>();
		}
		public void add(int root, int child, int length) {
			graph[root-1].add(new Node(child-1, length));
		}
		public void find_length(int n, int cnt) {
			Stack stack = new Stack();
			stack.push(null);
			stack.push(n);
			visit[n] = true;
			int i = 0, j;
			while(stack.peek()!=null) {
				i = (int)stack.pop();
				for(j = 0; j < graph[i].size(); j++)
					if(!visit[((Node)graph[i].get(j)).child]) {
						visit[((Node)graph[i].get(j)).child] = true;
						digit[((Node)graph[i].get(j)).child] = digit[i]+((Node)graph[i].get(j)).len;
						stack.push(((Node)graph[i].get(j)).child);
					}
			}
			cnt++;
			if(cnt==2) {
				Arrays.sort(digit);
				int num = digit[digit.length-1];
				System.out.println(num);
				return;
				}
			else {
				int num=0;
				for(int a = 0; a < digit.length; a++)
					if(digit[num]<=digit[a]) num = a;
				Arrays.fill(digit, 0);
				Arrays.fill(visit, false);
				find_length(num, cnt);
			}
		}
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);// TODO Auto-generated method stub
		int N = in.nextInt();
		Graph g = new Graph(N);
		int root,child,length;
		for(int i = 0; i < N; i++) {
			root = in.nextInt();
			while(true) {
				child = in.nextInt();
				if(child == -1) break;
				length = in.nextInt();
				g.add(root, child, length);
			}
		}
		g.find_length(0, 0);
	}
}
