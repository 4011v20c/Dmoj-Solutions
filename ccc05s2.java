import java.util.*;

public class ccc05s2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String[] ar = s.split(" ");
        int c = Integer.parseInt(ar[0]);
        int r = Integer.parseInt(ar[1]);
        int moveX = 0;
        int moveY = 0;
        int x = 0;
        int y = 0;
        while(true) {
            s = sc.nextLine();
            if(s.equals("0 0")) {
                break;
            }else {
                ar = s.split(" ");
                moveX = Integer.parseInt(ar[0]);
                moveY = Integer.parseInt(ar[1]);


                if(x+moveX <= c & x+moveX >= 0 ) {
                    x += moveX;
                }else if(x+moveX > c) {
                    x = c;
                }else {
                    x = 0;
                }


                if(y+moveY <= r & y+moveY >= 0 ) {
                    y += moveY;
                }else if(y+moveY > r) {
                    y = r;
                }else {
                    y = 0;
                }

                System.out.println(x + " " + y);
            }
        }

    }
}