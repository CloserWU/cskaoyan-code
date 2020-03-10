package com.closer;

import java.text.DecimalFormat;
import java.util.*;

/**
 * <p>DataStructure</p>
 * <p>description</p>
 *
 * @author closer
 * @version 1.0.0
 * @date 2020-02-24 20:03
 */
public class DataStructure {
    void func1() {
        Stack<Integer> stack = new Stack<>();
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            int n = input.nextInt();
            if (n == 0) {
                break;
            }
            for (int i = 0; i < n; i++) {
                String next = input.next();
                if ("P".equals(next)) {
                    stack.push(input.nextInt());
                } else if ("O".equals(next)) {
                    if (!stack.isEmpty()) {
                        stack.pop();
                    }
                } else if ("A".equals(next)) {
                    if (stack.isEmpty()) {
                        System.out.println("E");
                    } else {
                        System.out.println(stack.peek());
                    }
                }
            }
            System.out.println();
        }
    }
    private static int index = 0;

    private double getNumber(String str) {
        double number = 0;
        while (Character.isDigit(str.charAt(index))) {
            number = number * 10 + str.charAt(index++) - '0';
        }
        return number;
    }

    private double calculate(double y, double x, char op) {
        double res = 0;
        if (op == '+') {
            res = x + y;
        } else if (op == '-') {
            res = x - y;
        } else if (op == '*') {
            res = x * y;
        } else if (op == '/') {
            res = x / y;
        }
        return res;
    }

    void func2() {
        index = 0;
        Map<Character, Integer> priority = new HashMap<>();
        priority.put('+', 2);
        priority.put('-', 2);
        priority.put('*', 3);
        priority.put('/', 3);
        priority.put('#', 0);
        priority.put('$', 1);
        Stack<Character> oper = new Stack<>();
        Stack<Double> data = new Stack<>();
        Scanner input = new Scanner(System.in);
        String str = input.nextLine();
        str += "$";
        oper.push('#');
        while (index < str.length()) {
            if (Character.isDigit(str.charAt(index))) {
                data.push(getNumber(str));
            } else {
                if (priority.get(oper.peek()) < priority.get(str.charAt(index))) {
                    oper.push(str.charAt(index++));
                } else {
                    data.push(calculate(data.pop()/*先执行*/, data.pop()/*后执行*/, oper.pop()));
                }
            }
        }
        System.out.println(data.peek().intValue());
    }
}

