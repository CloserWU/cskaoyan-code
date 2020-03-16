package com.closer.contest;

import java.util.*;

/**
 * <p>Practice59</p>
 * <p>description</p>
 *
 * @author closer
 * @version 1.0.0
 * @date 2020-03-16 14:55
 */
public class Practice59 {
    void func1() {
        Scanner input = new Scanner(System.in);
        String str1 = "XiaoQiao";
        String str2 = "XiaoHuiHui";
        boolean flag1 = false;
        boolean flag2 = false;
        String str = input.next();
        int idx = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str1.charAt(idx) == str.charAt(i)) idx++;
            if (idx == 8) {
                flag1 = true;
                break;
            }
        }
        idx = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str2.charAt(idx) == str.charAt(i)) idx++;
            if (idx == 10) {
                flag2 = true;
                break;
            }
        }
        if (flag1 && flag2) {
            System.out.println("Happy");
        } else {
            System.out.println("emm");
        }
    }



    /**
     * https://ac.nowcoder.com/acm/contest/4915/B
     *
     */
    void func2() {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        List<Long> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            long x = input.nextLong();
            long y = input.nextLong();
            list.add(x * x * y + y * y * (y - 2 * x));
        }
        list.sort(new Comparator<Long>() {
            @Override
            public int compare(Long o1, Long o2) {
                return Long.compare(o1, o2);
            }
        });
        long ans = 0;
        for (int i = 1; i < n; i++) {
            ans += list.get(i) - list.get(i - 1);
        }
        System.out.println(ans);
    }

    public static void main(String[] args) {
        Practice59 obj = new Practice59();
        obj.func2();
    }
}

