import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static point base;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List<point> points = new ArrayList<>();
		Stack<point> ValidPoints = new Stack<>();
		Scanner sc = new Scanner(System.in);
		int n;
		point p = new point(Integer.MAX_VALUE, Integer.MAX_VALUE);

		n = sc.nextInt();
		for (int i = 0; i < n; i++)
			points.add(new point(sc.nextInt(), sc.nextInt()));

		for (int i = 0; i < n; i++) {
			if (p.y > points.get(i).y)
				p = points.get(i);
			else if (p.y == points.get(i).y)
				if (p.x > points.get(i).x)
					p = points.get(i);
		}

		base = points.remove(points.indexOf(p));
		Collections.sort(points, new Comparator<point>() {
			@Override
			public int compare(point o1, point o2) {
				long ccwvalue = ccw(base, o1, o2);
				
				if (ccwvalue == 0) {
					double dist1 = dist(base, o1);
					double dist2 = dist(base, o2);
					if (base.x < o1.x) {
						if (dist1 > dist2) return 1;
						else return -1;
					} else {
						if (dist1 < dist2) return 1;
						else return -1;
					}
				} else {
					if (ccwvalue > 0) return -1;
					else return 1;
				}
			}
		});

		
		ValidPoints.push(base);
		ValidPoints.push(points.remove(0));
		while (!points.isEmpty()) {
			point second = ValidPoints.pop();
			point first = ValidPoints.pop();
			point next = points.remove(0);

			double ccwComp = ccw(first, second, next);
			if (ccwComp > 0) {
				ValidPoints.push(first);
				ValidPoints.push(second);
				ValidPoints.push(next);
			} else {
				ValidPoints.push(first);
				ValidPoints.push(next);
				if (ValidPoints.size() == 2)
					continue;
				while (true) {
					next = ValidPoints.pop();
					second = ValidPoints.pop();
					first = ValidPoints.pop();
					ccwComp = ccw(first, second, next);
					if (ccwComp > 0) {
						ValidPoints.push(first);
						ValidPoints.push(second);
						ValidPoints.push(next);
						break;
					} else {
						ValidPoints.push(first);
						ValidPoints.push(next);
					}
				}
			}
		}
		
		while (true) {
			point next = ValidPoints.firstElement();
			point second = ValidPoints.pop();
			point first = ValidPoints.pop();
			long ccwComp = ccw(first, second, next);
			if (ccwComp > 0) {
				ValidPoints.push(first);
				ValidPoints.push(second);
				break;
			} else {
				ValidPoints.push(first);
			}
		}

		System.out.println(ValidPoints.size());
	}

	public static long ccw(point first, point second, point next) {
		long tmp1 = ((long) second.x - first.x) * ((long) next.y - first.y);
		long tmp2 = ((long) second.y - first.y) * ((long) next.x - first.x);
		return tmp1 - tmp2;
	}

	public static double dist(point p1, point p2) {
		return Math.sqrt(Math.pow(p1.x - p2.x, 2) + Math.pow(p1.y - p2.y, 2));
	}
	
	public static class point {
		int x, y;

		public point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
}