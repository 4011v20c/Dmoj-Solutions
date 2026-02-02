import java.util.*;

public class ccc07j2 {

    public static void main(String[] args) {
        Map<String, String> map = new HashMap<>();
        map.put("CU", "see you");
        map.put(":-)", "I'm happy");
        map.put(":-(", "I'm unhappy");
        map.put(";-)", "wink");
        map.put(":-P", "stick out my tongue");
        map.put("(~.~)", "sleepy");
        map.put("TA", "totally awesome");
        map.put("CCC", "Canadian Computing Competition");
        map.put("CUZ", "because");
        map.put("TY", "thank-you");
        map.put("YW", "you're welcome");
        map.put("TTYL", "talk to you later");
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        while (!s.equals("TTYL")) {
            if(map.containsKey(s)){
                System.out.println(map.get(s));
            }else{
                System.out.println(s);
            }
            s = sc.nextLine();
        }
        System.out.println("talk to you later");
    }
}
