package com.closer;

import java.util.*;

/**
 * <p>Graph</p>
 * <p>description</p>
 *
 * @author closer
 * @version 1.0.0
 * @date 2020-03-09 20:26
 */
public class Graph {
    class Edge {  // 边
        int weight;   // 边权
        String nodeName;  // 边所连接的顶点名
        Edge next;   // 下一条边

        Edge() {
            weight = 0;
            next = null;
        }

        Edge(int weight, String nodeName, Edge next) {
            this.weight = weight;
            this.nodeName = nodeName;
            this.next = next;
        }
    }


    class GNode {  // 顶点
        String nodeName;  // 顶点名
        Edge head;   // 边指针

        GNode() {
            head = null;
        }

        GNode(String nodeName, Edge head) {
            this.nodeName = nodeName;
            this.head = head;
        }
    }

    private Map<String, GNode> graph = new HashMap<>();
    private Map<String, Boolean> visit = new HashMap<>();
    private Map<String, Integer> dist = new HashMap<>();


    void initialVisit() {
        for (Map.Entry<String, Boolean> entry : visit.entrySet()) {
            entry.setValue(false);
        }
    }

    void initialGraph() {
        visit.clear();;
        dist.clear();
        for (Map.Entry<String, GNode> entry : graph.entrySet()) {
            GNode gNode = entry.getValue();
            Edge edge = gNode.head;
            Edge tmp = null;
            while (edge != null) {
                tmp = edge;
                edge = edge.next;
                tmp = null;
            }
        }
        graph.clear();
    }

    void insertEdge(String key1, String key2, int weight) {
        // 如果这个顶点以及存在，则将边加入这个顶点 （GNode 的 Edge；Edge的链表使用头插法）
        if (graph.containsKey(key1)) {
            GNode gNode = graph.get(key1);
            Edge edge = gNode.head;
            Edge newEdge = new Edge(weight, key2, edge);
            gNode.head = newEdge;
            graph.put(key1, gNode);
        } else {            // 如果这个点不存在，则新建一个顶点， 然后将边加入；
            Edge edge = new Edge(weight, key2, null);
            GNode gNode = new GNode(key1, edge);
            graph.put(key1, gNode);
        }
        visit.put(key1, false);
        dist.put(key1, Integer.MAX_VALUE);
    }

    void showGraph() {
        for (Map.Entry<String, GNode> entry : graph.entrySet()) {
            GNode gNode = entry.getValue();
            Edge edge = gNode.head;
            System.out.print(gNode.nodeName);
            while (edge != null) {
                System.out.print(" --> " + edge.nodeName + " " + edge.weight);
                edge = edge.next;
            }
            System.out.println();
        }
    }


    int BFS() {
        int component = 0;
        for(Map.Entry<String, GNode> entry : graph.entrySet()) {
            component++;
            /*Queue<GNode> queue = new PriorityQueue<>(new Comparator<GNode>() {
                @Override
                public int compare(GNode o1, GNode o2) {
                    return o1.nodeName.compareTo(o2.nodeName);
                }
            });*/
            Queue<GNode> queue = new LinkedList<>();
            if (visit.get(entry.getKey())) {
                continue;
            }
            queue.add(entry.getValue());
            while (!queue.isEmpty()) {
                GNode gNode= queue.poll();
                Edge edge = gNode.head;
                System.out.print(" --- " + gNode.nodeName);
                visit.put(gNode.nodeName, true);
                while (edge != null) {
                    if (!visit.get(edge.nodeName)) {
                        queue.add(graph.get(edge.nodeName));
                        visit.put(edge.nodeName, true);
                    }
                    edge = edge.next;
                }
            }
            System.out.println();
        }
        return component;
    }

    int DFS() {
        int component = 0;
        for(Map.Entry<String, GNode> entry : graph.entrySet()) {
            component++;
            Stack<GNode> stack = new Stack<>();
            if (visit.get(entry.getKey())) {
                continue;
            }
            stack.push(entry.getValue());
            while (!stack.isEmpty()) {
                GNode gNode= stack.peek();
                stack.pop();
                Edge edge = gNode.head;
                System.out.print(" --- " + gNode.nodeName);
                visit.put(gNode.nodeName, true);
                while (edge != null) {
                    if (!visit.get(edge.nodeName)) {
                        stack.add(graph.get(edge.nodeName));
                        visit.put(edge.nodeName, true);
                    }
                    edge = edge.next;
                }
            }
            System.out.println();
        }
        return component;
    }

    List<Map<String, Integer>> solution() {
        List<Map<String, Integer>> lm = new LinkedList<>();
        lm.clear();
        for (Map.Entry<String, GNode> entry: graph.entrySet()) {
            Stack<GNode> stack = new Stack<>();
            if (visit.get(entry.getKey())) {
                continue;
            }
            stack.push(entry.getValue());
            Map<String, Integer> map = new HashMap<>();
            map.clear();
            while (!stack.isEmpty()) {
                GNode gNode = stack.peek();
                stack.pop();
                Edge edge = gNode.head;
                visit.put(gNode.nodeName, true);
                while (edge != null) {
                    if (!visit.get(edge.nodeName)) {
                        visit.put(edge.nodeName, true);
                        stack.push(graph.get(edge.nodeName));
                    }
                    if (!map.containsKey(gNode.nodeName)) {
                        map.put(gNode.nodeName, 0);
                    }
                    map.put(gNode.nodeName, map.get(gNode.nodeName) + edge.weight);
                    if (!map.containsKey(edge.nodeName)) {
                        map.put(edge.nodeName, 0);
                    }
                    map.put(edge.nodeName, map.get(edge.nodeName) + edge.weight);
                    edge = edge.next;
                }
            }
            if (!map.isEmpty() && map.size() >=3) {
                lm.add(map);
            }
        }
        return lm;
    }

    class Pair {
        String str;
        Integer num;
        Pair(String str, Integer num) {
            this.num = num;
            this.str = str;
        }
    }

    void showResult(List<Map<String, Integer>> lm, int threshold) {
        List<Pair> lp = new LinkedList<>();
        for (Map<String, Integer> map : lm) {
            int total = 0;
            int maxWeight = Integer.MIN_VALUE;
            String maxString = "";
            for(Map.Entry<String, Integer> entry : map.entrySet()) {
                if (entry.getValue() > maxWeight) {
                    maxWeight = entry.getValue();
                    maxString = entry.getKey();
                }
                total += entry.getValue();
            }
            if (total > threshold * 4) {
                lp.add(new Pair(maxString, map.size()));
            }
        }
        if (!lp.isEmpty()) {
            lp.sort(new Comparator<Pair>() {
                @Override
                public int compare(Pair o1, Pair o2) {
                    return o1.str.compareTo(o2.str);
                }
            });
            System.out.println(lp.size());
            for (Pair p: lp) {
                System.out.println(p.str + " " + p.num);
            }
        } else {
            System.out.println(0);
        }
    }

    void test1() {
        int n, k;
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            initialGraph();
            n = input.nextInt();
            k = input.nextInt();
            String str1;
            String str2;
            int weight;
            for (int i = 0; i < n; ++i) {
                // 一个边的头节点和尾节点，还有边的权值
                str1 = input.next();
                str2 = input.next();
                weight = input.nextInt();
                // 构造图
                insertEdge(str1, str2, weight);
                insertEdge(str2, str1, weight);
            }
            // 展示图
            showGraph();
//            graph.DFS();
            initialVisit();
//            graph.BFS();
            List<Map<String, Integer>> list = solution();
            showResult(list, k);
        }
    }

    class Point {
        String nodeName;
        int distance;

        public Point(String nodeName, int distance) {
            this.nodeName = nodeName;
            this.distance = distance;
        }
    }

    void Dijkstra(String source) {
        Queue<Point> queue = new PriorityQueue<>(new Comparator<Point>() {
            @Override
            public int compare(Point o1, Point o2) {
                return Integer.compare(o2.distance, o1.distance);
            }
        });
        dist.put(source, 0);
        queue.add(new Point(source, dist.get(source)));
        while (!queue.isEmpty()) {
            String key = queue.poll().nodeName;
            GNode gNode = graph.get(key);
            Edge edge = gNode.head;
            while (edge != null) {
                String end = edge.nodeName;
                int d = edge.weight;
                if (dist.get(end) > dist.get(key) + d) {
                    dist.put(end, dist.get(key) + d);
                    queue.add(new Point(end, dist.get(end)));
                }
                edge = edge.next;
            }
        }
    }

    void test2() {
        int n, m;
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            initialGraph();
            n = input.nextInt();
            m = input.nextInt();
            String str1;
            String str2;
            String source = null;
            for (int i = 0; i < n; ++i) {
                // 一个边的头节点和尾节点，还有边的权值
                str1 = input.next();
                if (i == 0) {
                    source = str1;
                }
                str2 = input.next();
                // 构造图
                insertEdge(str1, str2, (int) Math.pow(2, i));
                insertEdge(str2, str1, (int) Math.pow(2, i));
            }
            Dijkstra("0");
            for (Map.Entry<String, Integer> e : dist.entrySet()) {
                if (!"0".equals(e.getKey())) {
                    System.out.println(e.getValue() % 10000);
                }
            }
        }
    }


    public static void main(String[] args) {
        Graph graph = new Graph();
        graph.test2();
    }
}

/*
8 59
BBB AAA 20
CCC BBB 10
AAA CCC 40
EEE DDD 70
DDD FFF 5
FFF GGG 30
GGG HHH 20
HHH FFF 10
*/