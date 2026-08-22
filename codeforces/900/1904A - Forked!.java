import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int kx = sc.nextInt();
            int ky = sc.nextInt();
            int qx = sc.nextInt();
            int qy = sc.nextInt();

            int[][] dirs = {{a, b}, {a, -b}, {-a, b}, {-a, -b}, {b, a}, {b, -a}, {-b, a}, {-b, -a}};

			Set<String> king = new HashSet<>();
			Set<String> queen = new HashSet<>();

			for (int[] d : dirs) {
				king.add((kx + d[0]) + "," + (ky + d[1]));
				queen.add((qx + d[0]) + "," + (qy + d[1]));
			}

			int ans = 0;
			for (String s : king) {
				if (queen.contains(s)) {
					ans++;
				}
			}

			System.out.println(ans);
        }
    }
}