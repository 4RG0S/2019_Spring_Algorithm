import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;


public class Main {
    private static int[] visited = new int[100001];


    public static void main(String[] args) throws IOException {
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(buffer.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        ArrayList<Integer>[] arr = new ArrayList[N+1];
        for( int i=0; i<N+1; i++){
            ArrayList array = new ArrayList();
            arr[i] = array;
        }
        while(M>0){
            st = new StringTokenizer(buffer.readLine());
            int first = Integer.parseInt(st.nextToken());
            int last = Integer.parseInt(st.nextToken());

            arr[last].add(first);
            M--;
        }
       find(arr,N);


    }
    public static int search(ArrayList<Integer>[] arr, int target){
        visited[target]=1;//방문했다는 증거
        if(arr[target].size()==0){
            return 1;
        }
        else{
            int sum =1;

            for( int i=0; i<arr[target].size();i++){
                if(visited[arr[target].get(i)]==0)//list.contains쓰니깐 넘 느림
                sum+= search(arr,arr[target].get(i));//인접리스트에 대한 계속 방문
            }
            return sum;
        }
    }
     public static void find(ArrayList<Integer>[] arr,int N) throws IOException {
        List<Integer> result = new ArrayList<>();


        int max =0;
        int sum=0;
        for( int i=1; i<=N; i++){//모든 번호를 돌아본다.

                sum+=search(arr,i);
            if(sum>max){//현재 max보다 크다면 재설정
                max = sum;
                result = new ArrayList<>();
                result.add(i);
            }
            else if( sum==max){//현재 max와 동일하면 진행
                result.add(i);
            }
            visited = new int[100001];//방문한곳은 다시 초기화 해준다
            sum=0;
        }

         BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
            String a="";
         for( int i=0; i<result.size();i++){
            if(i+1==result.size()){
              a = a+result.get(i);
               break;
            }
            a = a +result.get(i)+" ";
        }
         bw.write(a);
         bw.flush();
         bw.close();
    }

}
