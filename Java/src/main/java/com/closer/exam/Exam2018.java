package com.closer.exam;

import java.util.*;


/**
 * <p>machine</p>
 * <p>description</p>
 *
 * @author closer
 * @version 1.0.0
 * @date 2020-03-21 11:08
 */
public class Exam2018 {
    void func1() {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; i++) {
            String string = Long.toBinaryString(input.nextLong());
            StringBuilder sb = new StringBuilder(string);
            sb.reverse();
            Long along = 0L;
            int power = 0;
            for (int j = 0; j < sb.length(); j++) {
                along += (long) Math.pow(2, power++) * sb.charAt(j);
            }
            System.out.println(along);
        }
    }

    void func2() {
        String[] zero = new String[5];
        zero[0] = "111";
        zero[1] = "101";
        zero[2] = "101";
        zero[3] = "101";
        zero[4] = "111";
        String[] one = new String[5];
        one[0] = "001";
        one[1] = "001";
        one[2] = "001";
        one[3] = "001";
        one[4] = "001";
        String[] two = new String[5];
        two[0] = "111";
        two[1] = "001";
        two[2] = "111";
        two[3] = "100";
        two[4] = "111";
        String[][] sss = new String[][]{zero, one, two};

        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            String s = input.nextLine();
            for (int j = 0; j < 5; j++) {
                for (int i = 0; i < s.length(); i++) {
                    System.out.print(sss[s.charAt(i) - '0'][j]);
                }
                System.out.println();
            }
        }
    }

    void func3() {
        
    }

    void func4() {
        //
    }

    void func5() {
        //
    }

    void func6() {
        //
    }

    void func7() {
        //
    }

    void func8() {
        //
    }

    void func9() {
        //
    }

    public static void main(String[] args) {
        Exam2018 obj = new Exam2018();
//        obj.func1();
        obj.func2();
    }
}

