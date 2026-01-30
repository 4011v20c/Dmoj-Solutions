import java.io.*;
import java.util.*;

public class ccc02s4 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = readNonEmptyLine(br);
        if (line == null) {
            return;
        }
        int m = Integer.parseInt(line.trim());

        line = readNonEmptyLine(br);
        if (line == null) {
            return;
        }
        int n = Integer.parseInt(line.trim());

        String[] names = new String[n];
        long[] t = new long[n];
        for (int i = 0; i < n; i++) {
            line = readNonEmptyLine(br);
            if (line == null) {
                return;
            }
            String name = line.trim();

            line = readNonEmptyLine(br);
            if (line == null) {
                return;
            }
            String timeStr = line.trim();
            names[i] = name;
            t[i] = Long.parseLong(timeStr);
        }

        // dp[i] = minimum time to get first i people across
        // each group of size <= m crosses together, time = max in group
        long[] dp = new long[n + 1];
        int[] prev = new int[n + 1];
        Arrays.fill(dp, Long.MAX_VALUE / 4);
        dp[0] = 0L;

        for (int i = 1; i <= n; i++) {
            // try all possible last group sizes
            long maxTime = 0;
            for (int j = i; j >= 1 && i - j + 1 <= m; j--) {
                maxTime = Math.max(maxTime, t[j - 1]);
                long candidate = dp[j - 1] + maxTime;
                if (candidate < dp[i]) {
                    dp[i] = candidate;
                    prev[i] = j - 1;
                }
            }
        }

        StringBuilder out = new StringBuilder();
        out.append("Total Time: ").append(dp[n]).append('\n');

        ArrayList<String> groups = new ArrayList<>();
        int idx = n;
        while (idx > 0) {
            int start = prev[idx];
            StringBuilder group = new StringBuilder();
            for (int i = start; i < idx; i++) {
                if (i > start) group.append(' ');
                group.append(names[i]);
            }
            groups.add(group.toString());
            idx = start;
        }

        for (int i = groups.size() - 1; i >= 0; i--) {
            out.append(groups.get(i));
            if (i > 0) out.append('\n');
        }
        System.out.print(out.toString());
    }

    private static String readNonEmptyLine(BufferedReader br) throws IOException {
        String line;
        while ((line = br.readLine()) != null) {
            if (!line.trim().isEmpty()) {
                return line;
            }
        }
        return null;
    }
}