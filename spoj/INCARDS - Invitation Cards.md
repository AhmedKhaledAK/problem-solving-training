```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;
 
public class Main {
 
    public static void main(String[] args) {
            InputReader reader = new InputReader();
            PrintWriter out = new PrintWriter(System.out);
 
            int t = reader.nextInt();
 
            for (int i = 0; i < t; i++){
                int p = reader.nextInt(), q = reader.nextInt();
                Graph graph = new Graph(p, 1);
                for (int j = 0; j < q; j++){
                    graph.insertInAdjList(reader.nextInt() - 1, reader.nextInt() -1, reader.nextInt());
                }
                solve(graph, out);
            }
 
            out.flush();
    }
 
    private static void solve(Graph graph, PrintWriter out) {
        graph.dijkstra(0);
        int sum = 0;
        for (int i = 0; i < graph.getShortestPathList().size(); i++){
            sum += graph.getShortestPathList().get(i).getWeightKey();
        }
        Graph transposeGraph = graph.getTransposeGraph();
        transposeGraph.dijkstra(0);
        for (int i = 0; i < transposeGraph.getShortestPathList().size(); i++){
            sum += transposeGraph.getShortestPathList().get(i).getWeightKey();
        }
        out.println(sum);
    }
 
 
    static class Graph {
 
        private LinkedList<Vertex>[] adjList;
        private int type; // 0 - undirected, 1 - directed
        private Vertex[] helperArraySP;
        private LinkedList<Vertex> shortestPathList;
        private int size;
 
        Graph(int size, int type) {
            this.size = size;
            this.adjList = new LinkedList[size];
            this.type = type;
            this.helperArraySP = new Vertex[size];
            this.shortestPathList = new LinkedList<>();
        }
 
        void insertInAdjList(int src, int dest, int weight){
            Vertex vertex = new Vertex(dest);
            vertex.setWeight(weight);
            initializeList(src);
            this.adjList[src].add(vertex);
 
            if (this.type == 0){
                if(src == dest) return;
                vertex = new Vertex(src);
                vertex.setWeight(weight);
                initializeList(dest);
                this.adjList[dest].add(vertex);
            }
        }
 
        private void initializeSingleSource(int src){
            for (int i = 0; i < size; i++){
                helperArraySP[i] = new Vertex(i);
                helperArraySP[i].setWeightKey(Integer.MAX_VALUE);
            }
            helperArraySP[src].setWeightKey(0);
        }
 
        private void relaxEdge(Vertex u, Vertex v, int weight, PriorityQueue<Vertex> queue){
            if (v.getWeightKey() > u.getWeightKey() + weight){
                v.setWeightKey(u.getWeightKey() + weight);
                v.setPredecessor(u);
                Vertex minV = queue.poll();
                queue.add(minV);
            }
        }
 
        void dijkstra(int src){
            initializeSingleSource(src);
            PriorityQueue<Vertex> queue = createQueue(helperArraySP);
            while (!queue.isEmpty()){
                Vertex vertex = queue.poll();
                int v = vertex.getV();
                shortestPathList.add(vertex);
                for (int i = 0; i < adjList[v].size(); i++){
                    int vert = adjList[v].get(i).getV();
                    relaxEdge(vertex, helperArraySP[vert], adjList[v].get(i).getWeight(), queue);
                }
            }
        }
 
        Graph getTransposeGraph(){
            Graph graph = new Graph(this.adjList.length, type);
            for (int i = 0; i < adjList.length; i++){
                for (int j = 0; j < adjList[i].size(); j++){
                    graph.insertInAdjList(adjList[i].get(j).getV(), i,adjList[i].get(j).getWeight());
                }
            }
            return graph;
        }
 
        private PriorityQueue<Vertex> createQueue(Vertex[] helperArray) {
            PriorityQueue<Vertex> queue = new PriorityQueue<>();
            Collections.addAll(queue, helperArray);
            return queue;
        }
 
        private void heapifyQueue(PriorityQueue<Vertex> queue, Vertex vertex) {
            queue.remove(vertex);
            queue.add(vertex);
        }
 
        private void initializeList(int i) {
            if (this.adjList[i] == null)
                this.adjList[i] = new LinkedList<>();
        }
 
        public void printGraphAdjList(){
            for(int i = 0; i < adjList.length; i++){
                System.out.print(i + ": ");
                if (adjList[i] == null){
                    System.out.println("/");
                    continue;
                }
                for(int j = 0; j < adjList[i].size(); j++)
                    System.out.print(adjList[i].get(j).getV() + " / ");
                System.out.println();
            }
        }
 
        LinkedList<Vertex> getShortestPathList() {
            return shortestPathList;
        }
    }
 
    static class Vertex implements Comparable<Vertex> {
 
        private int v;
        private int weight;
        private Vertex predecessor;
        private Integer weightKey;
 
        @Override
        public int compareTo(Vertex vertex) {
            return this.getWeightKey().compareTo(vertex.getWeightKey());
        }
 
        Vertex(int v) {
            this.v = v;
        }
 
        int getV() {
            return v;
        }
 
        public void setV(int v) {
            this.v = v;
        }
 
        int getWeight() {
            return weight;
        }
 
        void setWeight(int weight) {
            this.weight = weight;
        }
 
        Vertex getPredecessor() {
            return predecessor;
        }
 
        void setPredecessor(Vertex predecessor) {
            this.predecessor = predecessor;
        }
 
        Integer getWeightKey() {
            return weightKey;
        }
 
        void setWeightKey(Integer weightKey) {
            this.weightKey = weightKey;
        }
    }
 
 
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
 
        InputReader() {
            reader = new BufferedReader(new InputStreamReader(System.in));
            tokenizer = null;
        }
 
        String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return tokenizer.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}
```

