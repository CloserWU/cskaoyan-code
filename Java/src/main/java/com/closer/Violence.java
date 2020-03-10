package com.closer;


import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.*;


/**
 * <p>Violence</p>
 * <p>description</p>
 *
 * @author closer
 * @version 1.0.0
 * @date 2020-02-17 14:16
 */
public class Violence {
    boolean func1_no7(int n) {
        while (n != 0) {
            if (n % 10 == 7) {
                return false;
            }
            n /= 10;
        }
        return true;
    }

    public void func1() {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        long res = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 7 != 0 && func1_no7(i)) {
                res += Math.pow(i, 2);
            }
        }
        System.out.println(res);
    }

    public void func2() {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < (100 - 5 * x) / 3; y++) {
                for (int z = 0; z < (100 - 5 * x - 3 * y) * 3; z++) {
                    if (15 * x + 9 * y + z <= 3 * n && x + y + z == 100) {
                        System.out.printf("x=%d,y=%d,z=%d\n", x, y, z);
                        ;
                    }
                }
            }
        }
    }


    public void func3() {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int x, y, z, price = 99999;
        x = input.nextInt();
        y = input.nextInt();
        z = input.nextInt();
        for (; price > 0; price--) {
            for (int i = 1; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (i * 10000 + x * 1000 + y * 100 + z * 10 + j == price * n) {
                        System.out.printf("%d %d %d", i, j, price);
                        return;
                    }
                }
            }
        }
        System.out.println(0);
    }


    char[][] mmap = new char[3003][3003];
    String[] str = new String[6];
    Integer n;

    void dfs(int m, int x, int y) {
        if (m == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mmap[x + i][y + j] = (str[i]).charAt(j);
                }
            }
            return;
        }
        int size = (int) Math.pow(n * 1.0, m - 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((str[i]).charAt(j) != ' ') {
                    dfs(m - 1, x + i * size, y + j * size);
                }
            }
        }
    }


    public void func4() {
        n = 1;
        Scanner input = new Scanner(System.in);
        while (n != null) {
            n = Integer.parseInt(input.nextLine());
            for (int i = 0; i < n; i++) {
                str[i] = input.nextLine();
            }
            int m = Integer.parseInt(input.nextLine());
            int size = (int) Math.pow(n * 1.0, m);
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    mmap[i][j] = ' ';
                }
                mmap[i][size] = '\0';
            }
            dfs(m, 0, 0);
            for (int i = 0; i < size; i++) {
                System.out.println(mmap[i]);
            }
        }
    }

    public void func5() {
        char[] str = new char[80];
        Scanner input = new Scanner(System.in);
        str = input.nextLine().toCharArray();
        int len = str.length;
        int n1 = 0, n2 = 0;
        for (int i = 1; i <= len; i++) {
            if (len + 2 - 2 * i >= i && i > n1) {
                n1 = i;
            }
        }
        n2 = len + 2 - 2 * n1;
        // cout<< n1 << " " << n2 << endl;
        char[][] matrix = new char[n1][n2 + 1];

        for (int i = 0; i < n1; i++) {
            matrix[i][n2] = '\0';
            matrix[i][0] = str[i];
            matrix[i][n2 - 1] = str[len - i - 1];
        }
        for (int i = 0; i < n2; i++) {
            matrix[n1 - 1][i] = str[n1 + i - 1];
        }
        for (int i = 0; i < n1; i++) {
            System.out.println(matrix[i]);
        }
    }

    /**
     * 牛客网测试用例中
     * 10000101
     * 10010201
     * 给出的结果是397，错误
     * 以下代码正确
     *
     * @throws ParseException
     */
    public void func6() throws ParseException {
        Scanner input = new Scanner(System.in);
        String day1 = input.nextLine();
        String day2 = input.nextLine();
        SimpleDateFormat format = new SimpleDateFormat("yyyyMMdd");
        Date date1 = format.parse(day1);
        System.out.println(date1.getTime());
        Date date2 = format.parse(day2);
        System.out.println(date2.getTime());
//        Calendar calendar = Calendar.getInstance();
//        calendar.setTime(date1);
//        LocalDate localDate1 = LocalDate.of(calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH), calendar.get(Calendar.DAY_OF_MONTH));
//        calendar.setTime(date2);
//        LocalDate localDate2 = LocalDate.of(calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH), calendar.get(Calendar.DAY_OF_MONTH));
//        System.out.println(localDate1.until(localDate2, ChronoUnit.DAYS) + 1);
        Long a = Math.abs(((date1.getTime() - date2.getTime()) / (1000 * 3600 * 24)));
        System.out.println(a + 1);
    }


    public void func7() {
        Map<Object, Object> map = new HashMap<>();
        map.put("January", 1);
        map.put("February", 2);
        map.put("March", 3);
        map.put("April", 4);
        map.put("May", 5);
        map.put("June", 6);
        map.put("July", 7);
        map.put("August", 8);
        map.put("September", 9);
        map.put("October", 10);
        map.put("November", 11);
        map.put("December", 12);

        map.put(7, "Sunday");
        map.put(1, "Monday");
        map.put(2, "Tuesday");
        map.put(3, "Wednesday");
        map.put(4, "Thursday");
        map.put(5, "Friday");
        map.put(6, "Saturday");


        Scanner input = new Scanner(System.in);
        String[] split = input.nextLine().split(" ");
        int day = Integer.parseInt(split[0]);
        int month = (int) map.get(split[1]);
        int year = Integer.parseInt(split[2]);

//        Calendar calendar = Calendar.getInstance();
//        calendar.set(year, month - 1,  day);
        LocalDate date = LocalDate.of(year, month, day);
        DayOfWeek ofWeek = date.getDayOfWeek();

        System.out.println(map.get(ofWeek.getValue()));

    }

    void func8() throws ParseException {
        SimpleDateFormat format = new SimpleDateFormat("yyyy MM dd");
        SimpleDateFormat format1 = new SimpleDateFormat("yyyy-MM-dd");
        Scanner input = new Scanner(System.in);
        int line = Integer.parseInt(input.nextLine());
        for (int i = 0; i < line; i++) {
            Date d = format.parse(input.nextLine());
            Calendar calendar = Calendar.getInstance();
            calendar.setTime(d);
            // Calender的月份从0开始 LocalDate的月份从1开始
            LocalDate localDate = LocalDate.of(calendar.get(Calendar.YEAR), calendar.get(Calendar.MONTH) + 1, calendar.get(Calendar.DAY_OF_MONTH));
            LocalDate plusDays = localDate.plusDays(1);
            System.out.println(plusDays);
        }
    }

    void func9() {
        Scanner input = new Scanner(System.in);
        int p, t, g1, g2, g3, gj;
        double res;
        while (input.hasNextLine()) {
            p = input.nextInt();
            t = input.nextInt();
            g1 = input.nextInt();
            g2 = input.nextInt();
            g3 = input.nextInt();
            gj = input.nextInt();
            if (Math.abs(g1 - g2) <= t) {
                res = (double) (g1 + g2) / 2.0;
                System.out.printf("%.1f\n", res);
                continue;
            }
            if (Math.abs(g3 - g1) <= t && Math.abs(g3 - g2) <= t) {
                res = (double) Math.max(g3, Math.max(g2, g1));
                System.out.printf("%.1f\n", res);
                continue;
            }
            if (Math.abs(g3 - g1) <= t || Math.abs(g3 - g2) <= t) {
                res = (double) (Math.min(Math.abs(g3 - g1), Math.abs(g3 - g2)) + 2 * g3) / 2.0;
                System.out.printf("%.1f\n", res);
                continue;
            }
            if (Math.abs(g3 - g1) > t && Math.abs(g3 - g2) > t) {
                res = (double) gj;
                System.out.printf("%.1f\n", res);
                continue;
            }
        }
    }


    void func10() {

    }

    void func11() {

        class Ant {
            int direct;
            int position;

            public Ant(int position, int direct) {
                this.direct = direct;
                this.position = position;
            }
        }

        Scanner input = new Scanner(System.in);
        int n;
        while (input.hasNext()) {
            n = Integer.parseInt(input.nextLine());
            List<Ant> list = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                list.add(new Ant(input.nextInt(), input.nextInt()));
            }
            list.sort(new Comparator<Ant>() {
                @Override
                public int compare(Ant o1, Ant o2) {
                    return o1.position - o2.position;
                }
            });
            int target = 0, toLeft = 0;
            for (int i = 0; i < n; i++) {
                if (list.get(i).direct == 0) {
                    target = i;
                }
                if (list.get(i).direct == -1) {
                    toLeft++;
                }
            }

            if (toLeft == target) {
                System.out.println("Cannot fall!");
            } else if (toLeft > target) {
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    if (list.get(i).direct == -1 && cnt == target) {
                        System.out.println(list.get(i).position);
                        return;
                    }
                    if (list.get(i).direct == -1) {
                        cnt++;
                    }
                }
            } else {
                int cnt = 0;
                for (int i = n - 1; i >= 0; i--) {
                    if (list.get(i).direct == 1 && cnt == n - target - 1) {
                        System.out.println(100 - list.get(i).position);
                        return;
                    }
                    if (list.get(i).direct == 1) {
                        cnt++;
                    }
                }
            }
        }

    }

}

