import java.util.Scanner;
public class ccc06j2 {
    public static void main (String [] args) {
        Scanner sc = new Scanner(System.in);
        int die1 = sc.nextInt();
        int die2 = sc.nextInt();
        int min = Math.min(die1,die2);
        int max = Math.max(die1,die2);
        int ways = 0;
        //max = 5
        //min = 3
        for(int i = max; i >0; i--) {
            for(int a = 1; a <= min; a++) {
                if ((i+a) == 10) {
                    ways +=1;
                }
            }
        }
        if (ways == 1) {
            System.out.println("There is "+ ways + " way to get the sum 10.");
        } else{
            System.out.println("There are "+ ways + " ways to get the sum 10.");
        }
    }
}