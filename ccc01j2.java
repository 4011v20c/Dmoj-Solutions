import java.util.*;

public class ccc01j2 {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int x = s.nextInt();
        int m = s.nextInt();
        for(int n = 1; n < m; n++) {
            if((x * n) % m == 1) {
                System.out.println(n);
                break;
            }

            if(n == m - 1){
                System.out.println("No such integer exists.");
            }
        }
    }
}