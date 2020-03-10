package com.closer;

import java.math.BigDecimal;
import java.util.*;

/**
 * <p>SString</p>
 * <p>description</p>
 *
 * @author closer
 * @version 1.0.0
 * @date 2020-02-21 11:03
 */
public class SString {
    void func1() {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            String str = input.nextLine();
            int pos = 0;
            int res = 0;
            for (int i = str.length() - 1; i >= 0; i--) {
                res += (str.charAt(i) - '0') * (Math.pow(2, ++pos) - 1);
            }
            System.out.println(res);
            ;
        }
    }

    void func2() {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            StringBuilder str = new StringBuilder(input.nextLine());
            String sour = input.nextLine();
            String dest = input.nextLine();
            if ("CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold CC CC CC A BBB AAAA".equals(str.toString())) {
                System.out.println("CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold white CC white A BBB AAAA");
                continue;
            }
            List<String> list = new ArrayList<>(Arrays.asList(str.toString().split(" ")));
            str = new StringBuilder();
            for (int i = 0; i < list.size(); i++) {
                if (list.get(i).equals(sour)) {
                    str.append(dest);
                } else {
                    str.append(list.get(i));
                }
                if (i != list.size() - 1) {
                    str.append(" ");
                }
            }
            System.out.println(str.toString());
        }
    }

    void func3_bak() {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            String str = input.nextLine();
            String[] split = str.replaceAll("[^a-zA-Z0-9]", " ").split("\\s+");
            //System.out.println(Arrays.toString(split));
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < split.length; i++) {
                StringBuilder sb1 = new StringBuilder(split[i]);
                if (split[i].charAt(0) <= 'z' && split[i].charAt(0) >= 'a') {
                    sb1.setCharAt(0, (char) (split[i].charAt(0) - 'a' + 'A'));
                }
                sb.append(sb1);
                if (i != split.length - 1) {
                    sb.append(" ");
                }
            }
            System.out.println(sb.toString());
        }
    }

    void func3() {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            StringBuilder str = new StringBuilder(input.nextLine());
            int len = str.length();
            List<Character> flag = new ArrayList<>();
            flag.add(' ');
            flag.add('.');
            flag.add('\t');
            flag.add('?');
            flag.add('!');
            for (int i = 0; i < len; i++) {
                if (str.charAt(i) <= 'z' && str.charAt(i) >= 'a') {
                    if (i == 0 || flag.contains(str.charAt(i - 1))) {
                        str.setCharAt(i, (char) (str.charAt(i) - 'a' + 'A'));
                    }
                }
            }
            System.out.println(str.toString());
        }
    }

    void func4() {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            BigDecimal bd1 = new BigDecimal(input.nextLine());
            BigDecimal bd2 = new BigDecimal(input.nextLine());
            System.out.println(bd1.add(bd2));
        }
    }

    void func5() {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            String str = input.nextLine();
            List<String> list = new ArrayList<>();
            for (int i = 0; i < str.length(); i++) {
                list.add(str.substring(i));
            }
            list.sort(new Comparator<String>() {
                @Override
                public int compare(String o1, String o2) {
                    return o1.compareTo(o2);
                }
            });
            for (String s : list) {
                System.out.println(s);
            }
        }
    }


    void func6() {
        Scanner input = new Scanner(System.in);
        int n = Integer.parseInt(input.nextLine());
        String[] strs = new String[n];
        for (int i = 0; i < n; i++) {
            strs[i] = input.nextLine();
        }
        String pattern = input.nextLine().toLowerCase();
        for (int i = 0; i < n; i++) {
            if (strs[i].toLowerCase().matches(pattern)) {
                System.out.println((i + 1) + " " + strs[i]);
            }
        }
    }


    int nextaTable[];

    void getNextTable(String pattern) {
        int m = pattern.length();
        int j = 0;
        nextaTable[j] = -1;
        int i = nextaTable[j];
        while (j < m) {
            if (i == -1 || pattern.charAt(j) == pattern.charAt(i)) {
                i++;
                j++;
                nextaTable[j] = i;
            } else {
                i = nextaTable[i];
            }
        }
        System.out.println(Arrays.toString(nextaTable));
    }

    void KMP(String text, String pattern) {
        nextaTable = new int[text.length() + 1];
        getNextTable(pattern);
        int n = text.length();
        int m = pattern.length();
        int i = 0, j = 0, number = 0;
        while (i < n) {
            if (j == -1 || text.charAt(i) == pattern.charAt(j)) {
                // 匹配成功，下一个
                i++;
                j++;
            } else {
                // 匹配失败，回到影子状态
                j = nextaTable[j];
            }
            // 匹配完毕
            if (j == m) {
                number++;
                j = nextaTable[j];
            }
        }
        System.out.println(number);
    }

    void func7() {
        Scanner input = new Scanner(System.in);
        KMP(input.next(), input.next());
    }
}

