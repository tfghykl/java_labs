package first_lab;

import java.text;
import java.text.NumberFormat;
import java.util.Scanner; 

public class Main {
	public static void main(String[] args) {
		NumberFormat formatter = NumberFormat.getNumberInstance();
		formatter.setMaximumFractionDigits(3);
		Scanner scanner = new Scanner(System.in);
		System.out.print("input x \n");
		double x = scanner.nextDouble();
		System.out.print("input epsilon \n");
		int k = scanner.nextInt();
		double result = calculation.calculate(x,k);
		System.out.printf("result is: " + result + "\n");
		System.out.println("result of Math method is: " + Math.sqrt(1+x));
		System.out.printf("result is: " + formatter.format(result) + "\n");
		System.out.println("roundded result of Math method is: " + formatter.format(Math.sqrt(1+x)));
	}
}
