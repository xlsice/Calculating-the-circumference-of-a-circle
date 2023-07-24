import java.util.Random;
import java.util.Scanner;

public class PiEstimation {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberOfPoints = 0;

        while (true) {
            System.out.print("请输入随机点的数量（输入'exit'退出）: ");
            String input = scanner.nextLine();

            if (input.equalsIgnoreCase("exit")) {
                break;
            }

            try {
                numberOfPoints = Integer.parseInt(input);
            } catch (NumberFormatException e) {
                System.out.println("输入错误，请输入一个整数。");
                continue;
            }

            int numberOfInCircle = 0;

            Random random = new Random();

            for (int i = 0; i < numberOfPoints; i++) {
                double x = random.nextDouble();
                double y = random.nextDouble();
                double distance = Math.sqrt(x * x + y * y);

                if (distance <= 1.0) {
                    numberOfInCircle++;
                }
            }

            double piEstimate = 4.0 * numberOfInCircle / numberOfPoints;
            System.out.println("Estimated value of Pi: " + piEstimate);
        }
    }
}
