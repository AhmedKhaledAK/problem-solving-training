#### Note: initial one, still looking for a better running time.

``` java
import java.util.*;

public class Main {

    static HashMap<String, Integer> orders = new HashMap<>(200);
    static HashMap<String, Integer> immOrders = new HashMap<>(200);
    static HashMap<String, LinkedList<String>> consMap = new HashMap<>(200);
    static ArrayList<String> strings = new ArrayList<>(300);
    static int depth = 0;

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        String vars = scan.nextLine();
        String constraints = scan.nextLine();

        String[] vArray = vars.split(" ");
        String[] cArray = constraints.split(" ");

        for (String s : vArray) {
            orders.put(s, 0);
            immOrders.put(s,0);
        }

        for (int i = 0; i < cArray.length; i+=2){
            orders.put(cArray[i+1], orders.get(cArray[i+1])+1);
            immOrders.put(cArray[i+1], immOrders.get(cArray[i+1])+1);
            consMap.put(cArray[i], new LinkedList<>());
            consMap.get(cArray[i]).add(cArray[i+1]);
        }

        boolean [] isVisited = new boolean[vArray.length];

        dfs(vArray, isVisited);

        Collections.sort(strings);

        for (String string : strings) 
            System.out.println(string);
    }

    private static void dfs(String[] vArray, boolean[] isVisited) {
        StringBuilder s;
        for (int v = 0; v < vArray.length; v++){
            if (orders.get(vArray[v]) == 0){
                depth = 0;
                s = new StringBuilder();
                s.append(vArray[v]);
                dfsVisit(v, isVisited, vArray, s);
            }
        }
    }

    private static void dfsVisit(int v, boolean[] isVisited, String[] vArray, StringBuilder s) {
        isVisited[v] = true;
        updateConstraint(v,vArray);
        if(s.length() == vArray.length){
            strings.add(s.toString());
        }
        for (int i = 0; i < vArray.length; i++){
            if(i == v) continue;
            if (!isVisited[i] && orders.get(vArray[i]) == 0){
                if (depth == 1)
                    updateConstraint(v,vArray);
                depth = 0;
                dfsVisit(i,isVisited,vArray, s.append(vArray[i]));
                s.deleteCharAt(s.length()-1);
            }
        }
        isVisited[v] = false;
        depth = 1;
        restoreConstraint(v,vArray);
    }

    private static void restoreConstraint(int v, String[] vArray) {
        orders.put(vArray[v], immOrders.get(vArray[v]));
    }

    private static void updateConstraint(int v, String[] vArray){
        if (consMap.get(vArray[v]) == null) return;
        for (int i =0; i < consMap.get(vArray[v]).size(); i++){
            orders.put(consMap.get(vArray[v]).get(i), orders.get(consMap.get(vArray[v]).get(i))-1);
        }
    }
}
```

