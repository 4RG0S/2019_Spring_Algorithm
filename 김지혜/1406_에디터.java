import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;

public class Main {
	
	public static class doubleLinkedList{
		
		dNode head;
		dNode cursor;
	
		public class dNode{
			dNode prev;
			dNode next;
			char v;
		
			public dNode(dNode prev, dNode next, char v) {
				this.prev=prev;
				this.next=next;
				this.v=v;
			}
		}
		public doubleLinkedList()
		{
			head=new dNode(null, null, '.');
			cursor=head;
		}
		public void moveleft()
		{
			if(cursor.prev!=null)
				cursor=cursor.prev;
		}
		public void moveright()
		{
			if(cursor.next!=null)
				cursor=cursor.next;
		}
		public void add(char v)
		{
			if(head==cursor)
			{
				head.next=new dNode(null, null, v);
				cursor=head.next;
				cursor.prev=head;
			}
			else
			{
				dNode temp =new dNode(head, head.next, v);
				head.next.prev = temp;
				head.next=temp;
			}
		}
		public void addOfCursor(char v)
		{
			dNode temp=new dNode(cursor, cursor.next, v);
			
			if(cursor.next==null)
			{
				cursor.next=temp;
				temp.prev = cursor;
				cursor = temp;
			}
			else
			{
				cursor.next.prev=temp;
				cursor.next=temp;
				cursor=temp;
			}
		}
		public void removeOfCursor()
		{
			if(cursor!=head)
			{
				if(cursor.next==null)//cursor가 가리키는 노드가 마지막 노드
				{
					cursor=cursor.prev;
					cursor.next=null;
				}
				else
				{
					dNode removed = cursor;
					dNode removedpr = removed.prev;
					dNode removednx = removed.next;
				
					removedpr.next = removednx;
					removednx.prev = removedpr;
					
					cursor = removedpr;
					
				}
			}
		}
		public StringBuffer nodeString()
		{
			StringBuffer nodeString = new StringBuffer();
			dNode p = head.next;
			
			while(p!=null)
			{
				nodeString.append(p.v);
				p=p.next;
			}
			return nodeString;
		}

	}
	public static void main(String[] args) throws IOException
	{
		BufferedReader scan = new BufferedReader(new InputStreamReader(System.in));
		String inputStr=scan.readLine();
		
		doubleLinkedList li = new doubleLinkedList();

		for(int i=inputStr.length()-1;i>=0;i--)
		{
			li.add(inputStr.charAt(i));
		}
		int n = Integer.parseInt(scan.readLine());
		
		for(int i=0;i<n;i++)
		{
			String input = scan.readLine();
			
			if(input.charAt(0)=='L')
			{
				li.moveleft();
			}
			else if(input.charAt(0)=='D')
			{
				li.moveright();
			}
			else if(input.charAt(0)=='P')
			{
				li.addOfCursor(input.charAt(2));
			}
			else if(input.charAt(0)=='B')
			{
				li.removeOfCursor();
			}
		}
		BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));

		wr.write(li.nodeString().toString());
		
		wr.flush();
		wr.close();

	}
		

}