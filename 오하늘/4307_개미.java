import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		int K = s.nextInt();
		
		ArrayList<Integer> array = new ArrayList<Integer>();
		ArrayList<Integer> buf = new ArrayList<>();
		
		for(int i=0; i<N; i++)
			array.add(i+1);

		int start = 0, i_remove = 0; // index
		while(array.size() != 0) {
			i_remove = index(start + (K - 1), array.size());
			buf.add(array.get(i_remove));
			array.remove(i_remove);
			start = index(i_remove, array.size()); // 지우고 나서의 인덱스 
			
		}
			
		System.out.print("<");
		for(int i=0;i<N;i++)
			if(i != N-1)
				System.out.print(buf.get(i)+", ");
			else
				System.out.print(buf.get(i));
		System.out.print(">");
	}
	
	public static int index(int i, int array_size) {
		if(array_size == 1) return 0;
		
		if(i >= array_size) 
			i = i - array_size;
		
		return i;
	}

}
