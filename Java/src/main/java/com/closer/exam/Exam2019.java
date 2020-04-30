package com.closer.exam;


import java.util.*;

/**
 * <p>Exam2019</p>
 * <p>description</p>
 *
 * @author wushuai
 * @version 1.0.0
 * @date 2020-04-30 9:37
 */
public class Exam2019 {

    void problemA() {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        while (n-- != 0) {
            String str = input.next();
            char[] chars = str.toCharArray();
            int carry = 0;
            chars[chars.length - 1] += 1;
            for (int i = chars.length - 1; i >= 0; i--) {
                chars[i] += carry;
                if (chars[i] >= '2') {
                    chars[i] -= 2;
                    carry = 1;
                } else {
                    carry = 0;
                }
                if (carry == 0) {
                    break;
                }
            }
            System.out.println(new String(chars));
            chars = str.toCharArray();
            carry = 0;
            chars[chars.length - 1] += 1;
            chars[chars.length - 2] += 1;
            for (int i = chars.length - 1; i >= 0; i--) {
                chars[i] += carry;
                if (chars[i] >= '2') {
                    chars[i] -= 2;
                    carry = 1;
                } else {
                    carry = 0;
                }
                if (carry == 0) {
                    break;
                }
            }
            System.out.println(new String(chars));
        }
    }

    void insertEdge(List<List<Integer>> graph, int from, int to) {
        List<Integer> edges;
        if (to != -1 && from != -1) {
            edges = graph.get(from);
            if (edges == null) {
                edges = new ArrayList<>();
            }
            edges.add(to);
            graph.set(from, edges);
        }
    }

    class Node {
        int key;
        int dist;

        public Node(int key, int dist) {
            this.key = key;
            this.dist = dist;
        }
    }

    void dijkstra(List<List<Integer>> graph, int from, int[] dist) {
        dist[from] = 0;
        Queue<Node> queue = new PriorityQueue<>(new Comparator<Node>() {
            @Override
            public int compare(Node o1, Node o2) {
                return Integer.compare(o1.dist, o2.dist);
            }
        });
        queue.add(new Node(from, 0));
        while (!queue.isEmpty()) {
            from = queue.poll().key;
            List<Integer> edges = graph.get(from);
            for (int i = 0; i < edges.size(); i++) {
                Integer to = edges.get(i);
                if (dist[to] > dist[from] + 1) {
                    dist[to] = dist[from] + 1;
                    queue.add(new Node(to, dist[to]));
                }
            }
        }
    }

    void problemB() {
        Scanner input = new Scanner(System.in);
        int _ = input.nextInt();
        while (_-- != 0) {
            int n = input.nextInt();
            List<List<Integer>> graph = new ArrayList<>(Collections.nCopies(n + 1, null));
            int m = input.nextInt();
            for (int i = 1; i <= n; i++) {
                int left = input.nextInt();
                int right = input.nextInt();
                insertEdge(graph, i, left);
                insertEdge(graph, left, i);
                insertEdge(graph, i, right);
                insertEdge(graph, right, i);
            }
            for (int i = 0; i < m; i++) {
                int[] dist = new int[n + 1];
                Arrays.fill(dist, 1000000);
                int from = input.nextInt();
                int to = input.nextInt();
                dijkstra(graph, from, dist);
                System.out.println(dist[to]);
            }
        }
    }

    public static void main(String[] args) {
        Exam2019 o = new Exam2019();
        o.problemB();
/*
1
8 4
2 3
4 5
6 -1
-1 -1
-1 7
-1 -1
8 -1
-1 -1
1 6
4 6
4 5
8 1

 */
    }

}
