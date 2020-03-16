package com.closer;

import java.math.BigInteger;
import java.util.*;

/**
 * <p>Graph01</p>
 * <p>
 *    -  new ArrayList<>(Collections.nCopies(105, new ArrayList<>()));
 *     所有105个元素的arraylist都是一个内存地址，造成灾难性后果，即使赋值给形参也不行， List tmp = new ArrayList<>();
 *     要lle = new ArrayList<>(Collections.nCopies(105, null));
 *     然后判断为null，则新建。这样内存地址就不是同一个
 *    - compare 函数
 *    - BigInteger 的用法
 * </p>
 *
 * @author closer
 * @version 1.0.0
 * @date 2020-03-11 19:42
 */
public class Graph01 {
    class Edge {
        int to;
        BigInteger length;

        public Edge() {
        }

        public Edge(int to, BigInteger length) {
            this.to = to;
            this.length = length;
        }
    };

    class Point {
        int number;
        BigInteger distance;

        public Point(int number, BigInteger distance) {
            this.number = number;
            this.distance = distance;
        }
    };


    public Graph01() {
        for (int i = 0; i < 105; i++) {
            List<Edge> list = new ArrayList<>();
            list.add(new Edge());
            lle.add(list);
        }
    }

    // 顶点集，每个顶点有他的边集，顶点的下标记为顶点名
    List<List<Edge>> lle = new ArrayList<>(Collections.nCopies(105, new ArrayList<>()));
    // 某点到其他点的距离
    BigInteger[] dis = new BigInteger[105];


    void dijkstra(int s) {
        Queue<Point> queue = new PriorityQueue<>(new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                // 距离小的优先级高，也就意味者是 按由小到大的方式排序 ，即如下
                // compare(x, y)  若 x > y -> 1; x < y -> -1; x = y -> 0
                // 返回1表示 x 要排在 y 前面
                return o1.distance.compareTo(o2.distance);
            }
        });
        dis[s] = BigInteger.valueOf(0);
        queue.add(new Point(s, dis[s]));
        while (!queue.isEmpty()) {
            int u = queue.poll().number;
            List<Edge> list = lle.get(u);
            for (Edge aList : list) {
                int v = aList.to;
                BigInteger d = aList.length;
                if (dis[v] == null || dis[v].compareTo(dis[u].add(d)) > 0) {
                    dis[v] = dis[u].add(d);
                    queue.add(new Point(v, dis[v]));
                }
            }
        }
    }

    int test() {
        int n, m;
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            n = input.nextInt();
            m = input.nextInt();
            lle = new ArrayList<>(Collections.nCopies(105, null));
            dis = new BigInteger[105];
            // 插入边，双向插入
            for (int i = 0; i < m; i++) {
                int from, to;
                from = input.nextInt();
                to = input.nextInt();
                if (from == to) {
                    continue;
                }
                List<Edge> list = lle.get(from);
                if (list == null) {
                    list = new ArrayList<>();
                }
                list.add(new Edge(to, new BigInteger("2").pow(i)));
                lle.set(from, list);
                list = lle.get(to);
                if (list == null) {
                    list = new ArrayList<>();
                }
                list.add(new Edge(from, new BigInteger("2").pow(i)));
                lle.set(to, list);
            }
            dijkstra(0);
            for (int i = 1; i < n; i++) {
                if (dis[i] == null) {
                    System.out.println(-1);
                } else {
                    System.out.println(dis[i].mod(BigInteger.valueOf(100000)).intValue());
                }
            }
        }
        return 0;
    }

    public static void main(String[] args) {
        Graph01 obj = new Graph01();
        obj.test();

        /*Queue<String> queue = new PriorityQueue<>(new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return -o1.compareTo(o2);
            }
        });
        queue.add("2");
        queue.add("1");
        queue.add("3");

        while (!queue.isEmpty()) {
            System.out.println(queue.poll());
        }*/
    }
}

