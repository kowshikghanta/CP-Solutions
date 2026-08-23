import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0) {
            double n = sc.nextDouble();
			double k = sc.nextDouble();
			double x = sc.nextDouble();
			double min = k * (k + 1) / 2;
			double max = k * (2 * n - k + 1) / 2;
			
			if (max >= x && min <= x) {
				System.out.println("YES");
			} else {
				System.out.println("NO");
			}
        }
    }
}