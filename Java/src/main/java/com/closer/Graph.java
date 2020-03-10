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

    Map<String, GNode> graph = new HashMap<>();

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

    public static void main(String[] args) {
        Graph graph = new Graph();

        int n;
        Scanner input = new Scanner(System.in);
        while (input.hasNext()) {
            n = input.nextInt();
            graph.graph.clear();
            String str1;
            String str2;
            int weight;
            for (int i = 0; i < n; ++i) {
                // 一个边的头节点和尾节点，还有边的权值
                str1 = input.next();
                str2 = input.next();
                weight = input.nextInt();
                // 构造图
                graph.insertEdge(str1, str2, weight);
            }
            // 展示图
            graph.showGraph();
        }
    }
}

