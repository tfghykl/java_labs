package first_lab;

public class calculation extends Main {
	public static double calculate(double x, int k) {
		if (x <= -1 || x >= 1) {
			throw new IllegalArgumentException("invalid x value: (-1,1) required " + x + " is not in this range");
		}
		if (k <= 0) {
			throw new IllegalArgumentException("invalid k value: natural required " + x + " is not in this range");
		}
		double epsilon = Math.pow(10, k*(-1));
		double result = 1;
		double prev_result = 0;
		int n = 1;
		double term = 1;
		while (Math.abs(prev_result - result) >= epsilon) 
		{
			prev_result = result;
			term *= (-1) * x * (2*n - 3) / (2.0*n);
			result += term;
			n++;
		}
		return result;
	}
}
