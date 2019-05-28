import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	
	protected Node[] a;
	public Main(Node[] array) {
		a = array;
	}
	
	static class Node {
		int parent;
		public Node(int parent) {
			this.parent = parent;
		}
	}
	
	protected int find(int i) {
		
		if(i != a[i].parent) {
			a[i].parent = find(a[i].parent);
		}
		
		return a[i].parent;
	}
	
	public void union(int i, int j) {
		
		int iroot = find(i);
		int jroot = find(j);
		
		if(iroot == jroot) {
			return;
		}
		else{
            a[jroot].parent = i;
        }
		
	}
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		int m = input.nextInt();
		
		Node[] node = new Node[n + 1];
		for(int i = 0; i <= n; i++) {
			node[i] = new Node(i);
		}
		
		Main uf  = new Main(node);
		for(int i = 0; i < m; i++) {
			int a = input.nextInt();
			int b = input.nextInt();
			int c = input.nextInt();
			
			if(a == 0) {
				uf.union(b,c);
			}
			else if(a == 1) {
				if(uf.find(b) == uf.find(c)) {
					System.out.println("YES");
				}
				else {
					System.out.println("NO");
				}
			}
		}
	}
}
