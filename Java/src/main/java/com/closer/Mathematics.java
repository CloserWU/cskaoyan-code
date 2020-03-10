package com.closer;


import java.math.BigInteger;
import java.util.*;

/**
 * <p>Mathematics</p>
 * <p>description</p>
 *
 * @author closer
 * @version 1.0.0
 * @date 2020-02-25 10:41
 */
public class Mathematics {
    void func1() {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            List<Integer> list = new ArrayList<>();
            int n = input.nextInt();
            while (n != 0) {
                list.add(n % 8);
                n /= 8;
            }
            for (int i = list.size() - 1; i >= 0; i--) {
                System.out.printf("%d", list.get(i));
            }
            System.out.println();
        }
    }

    void func2() {
        Scanner input = new Scanner(System.in);
        int m, A, B;
        m = input.nextInt();
        while (m != 0) {
            A = input.nextInt();
            B = input.nextInt();
            long res = A + B;
            List<Integer> list = new ArrayList<>();
            if (res == 0) {
                list.add( 0);
            }
            while (res != 0) {
                list.add((int) (res % m));
                res /= m;
            }
            for (int i = list.size() - 1; i >= 0; i--) {
                System.out.printf("%d", list.get(i));
            }
            System.out.println();
            m = input.nextInt();
        }
    }

    void func3() {
        Scanner input = new Scanner(System.in);
        Map<Character, Integer> map = new HashMap<>();
        map.put('1', 1);map.put('4', 4);map.put('7', 7);map.put('a', 10);map.put('d', 13);map.put('A', 10);map.put('D', 13);
        map.put('2', 2);map.put('5', 5);map.put('8', 8);map.put('b', 11);map.put('e', 14);map.put('B', 11);map.put('E', 14);
        map.put('3', 3);map.put('6', 6);map.put('9', 9);map.put('c', 12);map.put('f', 15);map.put('C', 12);map.put('F', 15);
        while (input.hasNext()) {
            String str = input.nextLine();
            long res = 0;
            for (int i = str.length() - 1; i >= 2 ; i--) {
                res += map.get(str.charAt(i)) * Math.pow(16, str.length() - 1 - i);
            }
            System.out.println(res);
        }
    }

    void func4() {
        Scanner input = new Scanner(System.in);
        Map<Character, Integer> map = new HashMap<>();
        map.put('0', 0);
        map.put('1', 1);map.put('4', 4);map.put('7', 7);map.put('a', 10);map.put('d', 13);map.put('A', 10);map.put('D', 13);
        map.put('2', 2);map.put('5', 5);map.put('8', 8);map.put('b', 11);map.put('e', 14);map.put('B', 11);map.put('E', 14);
        map.put('3', 3);map.put('6', 6);map.put('9', 9);map.put('c', 12);map.put('f', 15);map.put('C', 12);map.put('F', 15);
        while (input.hasNext()) {
            int a = input.nextInt();
            String n = input.next();
            int b = input.nextInt();
            long res = 0;
            for (int i = n.length() - 1; i >= 0; i--) {
                // https://www.cnblogs.com/someblue/p/3397715.html
                res += map.get(n.charAt(i)) * Math.pow(a, n.length() - 1 - i);
            }
            List<Character> list = new ArrayList<>();
            while (res != 0) {
                int mod = (int) (res % b);
                if (mod > 9) {
                    list.add((char) (mod - 10 + 'A'));
                } else {
                    list.add((char) (mod + '0'));
                }
                res /= b;
            }
            for (int i = list.size() - 1; i >= 0; i--) {
                System.out.print(list.get(i));
            }
            System.out.println();
        }
    }

    // a > b
    int GCD(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return GCD(b, a % b);
        }
    }

    void func5() {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            int n = input.nextInt();
            if (n == 0) {
                break;
            }
            int num = 0;
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                list.add(input.nextInt());
            }
            list.sort(new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    return o1 - o2;
                }
            });
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (GCD(list.get(j), list.get(i)) == 1) {
                        num++;
                    }
                }
            }
            System.out.println(num);
        }
    }

    void func6() {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            int k = input.nextInt();
            if (k == 0) {
                continue;
            }
            List<Integer> list = new ArrayList<>();
            List<Boolean> mark = new ArrayList<>(Collections.nCopies(150000, true));
            mark.set(0, false);
            mark.set(1, false);
            for (int i = 2; i < 150000; i++) {
                if (mark.get(i)) {
                    list.add(i);
                    k--;
                    // int j = i * i 爆int 有些编译器过不了
                    for (int j = i * i; j < 150000; j += i) {
                        mark.set(j, false);
                    }
                }
                if (k == 0) {
                    System.out.println(list.get(list.size() - 1));
                    break;
                }
            }
        }
    }

    void func7() {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            int n = input.nextInt();
            if (n == 0) {
                break;
            }
            for (int i = 0; i < n; i++) {
                long m = input.nextLong();
                int res = 0;
                int j;
                for (j = 1; j * j < m ; j++) {
                    if (m % j == 0) {
                        res +=2;
                    }
                }
                if (j * j == m) {
                    res++;
                }
                System.out.println(res);
            }
        }
    }

    void func8() {
        // TODO
    }

    int fastExp(long x, long y, long k) {
        long res = 1;
        for (; y > 0; y >>= 1, x = x * x % k) {
            if (y % 2 == 1) {
                res = res * x % k;
            }
        }
        return (int) res;
    }

    void func9() {
        Scanner input = new Scanner(System.in);
        int x, y, k;
        while (input.hasNext()) {
            x = input.nextInt();
            y = input.nextInt();
            k = input.nextInt();
            int ans = fastExp(x, y, k - 1);
            if (ans == 0) {
                ans = k - 1;
            }
            System.out.println(ans);;
        }

    }

    void func10() {
        Scanner input = new Scanner(System.in);
        int n, m;
        while (input.hasNext()) {
            n = input.nextInt();
            if (n == 0) {
                break;
            }
            m = input.nextInt();
            int[][] A= new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    A[i][j] = input.nextInt();
                }
            }
            int tmp;
            int res = 0;
            boolean flag = false;
            for (int i = 0; i < n; i++) {
                flag = true;
                for (int j = 0; j < m; j++) {
                    tmp = input.nextInt();
                    A[i][j] += tmp;
                    if (A[i][j] != 0) {
                        flag = false;
                    }
                }
                if (flag) {
                    res++;
                }
            }

            for (int j = 0; j < m; ++j) {
                flag = true;
                for (int i = 0; i < n; i++) {
                    if (A[i][j] != 0) {
                        flag = false;
                    }
                }
                if (flag) {
                    res++;
                }
            }
            System.out.println(res);;
        }
    }

    void func11() {
        Scanner input = new Scanner(System.in);
        int a0, a1, p, q, k, i, a;
        while (input.hasNext()) {
            a0 = input.nextInt();
            a1 = input.nextInt();
            p = input.nextInt();
            q = input.nextInt();
            k = input.nextInt();
            i = input.nextInt();
            for (i = 2; i <= k; i++) {
                a = (p * a1 + q * a0);
                a0 = a1 % 10000;
                a1 = a % 10000;
            }
            System.out.println(a1);;
        }
    }

    void func12() {
        Scanner input = new Scanner(System.in);
        int a = input.nextInt();
        String str = String.valueOf(a);
        int n = input.nextInt();
        BigInteger bi = new BigInteger("0");
        for (int i = 0; i < n; i++) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j <= i; j++) {
                sb.append(str);
            }
            bi = bi.add(new BigInteger(sb.toString()));
        }
        System.out.println(bi);

        /*
        *

        Scanner in = new Scanner(System.in);
        while(in.hasNext()){
            int a = in.nextInt();
            int n = in.nextInt();
            BigInteger sum = BigInteger.valueOf(0);
            BigInteger aa = BigInteger.valueOf(a);
            BigInteger aaa = aa;
            BigInteger radix = BigInteger.valueOf(10);
            BigInteger tmp;
            for(int i=1;i<=n;i++){
                sum = sum.add(aaa);
                aaa = aaa.add(aa.multiply(radix.pow(i)));
            }
            System.out.println(sum);
        }
        *
        */
    }


    void func13() {
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            String c = input.nextLine();
            boolean flag = true;
            if ("-1".equals(c)) {
                break;
            } else {
                BigInteger big = new BigInteger(c);
                for (int i = 2; i <= 9; i++) {
                    if (big.mod(BigInteger.valueOf(i)).intValue() == 0) {
                        if (!flag) {
                            System.out.print(" ");
                        }
                        System.out.printf("%d", i);
                        flag = false;
                    }
                }
            }
            if (flag) {
                System.out.println("none");
            } else {
                System.out.println();
            }
        }
    }
}

