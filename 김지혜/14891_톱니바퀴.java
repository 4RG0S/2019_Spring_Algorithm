import java.util.Scanner;

public class Main {
	
	public static class Gear{
		
		String t;
		int now;
		int left;
		int right;
		
		public Gear(String t)
		{
			this.t = t;
			this.now = 0;
			this.left = 6;
			this.right = 2;
		}
		public void actGear(int d)
		{
			if(d==-1)
			{
				this.now = (this.now+1)%8;
				this.left = (this.left+1)%8;
				this.right = (this.right+1)%8;
			}
			else
			{
				this.now = (this.now+7)%8;
				this.left = (this.left+7)%8;
				this.right = (this.right+7)%8;
			}
		}
		public char leftchar()
		{
			return t.charAt(this.left);
		}
		public char rightchar()
		{
			return t.charAt(this.right);
		}
		public int nowchar()
		{
			return Integer.parseInt(t.substring(this.now, this.now+1));
		}
	}
	static Gear[] g = new Gear[4];
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		//Åé´Ï¹ÙÄû

		for(int i=0;i<4;i++)
		{
			String a = scan.next();
			g[i]=new Gear(a);
		}
		
		int n = scan.nextInt();
		//°¢ Åé´Ï¹ÙÄûÀÇ ÇöÀç 12½Ã¹æÇâÀÇ À§Ä¡
		
		for(int i=0;i<n;i++)
		{
			int pickt = scan.nextInt();
			int dist = scan.nextInt();	
			result(pickt, dist);
		}
		System.out.println(g[0].nowchar()+g[1].nowchar()*2+g[2].nowchar()*4+g[3].nowchar()*8);
		
	}
	public static void result(int pickt, int dist)
	{
		char leftchar = g[pickt-1].leftchar();
		char rightchar = g[pickt-1].rightchar();
		g[pickt-1].actGear(dist);
		
		if(pickt>=2 && leftchar!=g[pickt-2].rightchar()) 
			resultreculeft(pickt-1, -dist);
		if(pickt<=3 && rightchar!=g[pickt].leftchar()) 
			resultrecuright(pickt+1, -dist);
	}
	public static void resultreculeft(int pickt, int dist)
	{
		char leftchar = g[pickt-1].leftchar();
		g[pickt-1].actGear(dist);
		
		if(pickt>=2 && leftchar!=g[pickt-2].rightchar()) 
			resultreculeft(pickt-1, -dist);
	}
	public static void resultrecuright(int pickt, int dist)
	{
		char rightchar = g[pickt-1].rightchar();
		g[pickt-1].actGear(dist);
		
		if(pickt<=3 && rightchar!=g[pickt].leftchar()) 
			resultrecuright(pickt+1, -dist);
	}
		

}