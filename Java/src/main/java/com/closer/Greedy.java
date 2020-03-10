package com.closer;

import java.util.*;

/**
 * <p>Greedy</p>
 * <p>description</p>
 *
 * @author closer
 * @version 1.0.0
 * @date 2020-03-02 17:06
 */
public class Greedy {
    void func1() {
        Scanner input = new Scanner(System.in);
        int n, m;
        n = Integer.parseInt(input.nextLine());
        List<String> proxy = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            proxy.add(input.nextLine());
        }

        List<String> server = new ArrayList<>();
        List<Boolean> flag = new ArrayList<>();
        m = Integer.parseInt(input.nextLine());
        for (int i = 0; i < m; ++i) {
            server.add(input.nextLine());
            flag.add(false);
        }
        int ans = 0, idx = 0, k = server.size();
        boolean flags = false;
        while (true) {
            if (idx >= proxy.size()) {
                break;
            }
            for (int i = 0; i < m; ++i) {
                if (!flag.get(i) && !proxy.get(idx).equals(server.get(i))) {
                    flag.set(i, true);
                    k--;
                }
            }
            if (k == 0) {
                flags = true;
                break;
            }
            idx++;
            ans++;
        }
        if (flags) {
            System.out.println(ans);
        } else {
            System.out.println(-1);
        }
    }
}

