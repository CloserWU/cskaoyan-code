package com.closer;

import java.util.*;


/**
 * <p>machine</p>
 * <p>description</p>
 *
 * @author closer
 * @version 1.0.0
 * @date 2020-03-21 11:08
 */
public class machine {
    void func1() {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for (int i = 0; i < n; i++) {
            System.out.println(Long.toBinaryString(input.nextLong()));
        }
    }

    void func2() {
        //
    }

    void func3() {
        //
    }

    void func4() {
        //
    }

    public static void main(String[] args) {
        machine obj = new machine();
        obj.func1();
    }
}

