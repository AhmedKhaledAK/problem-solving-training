
/**

k=2, l=[1,2,3,4,5,6]
output: l=[5,6,1,2,3,4]
In place O(1) space complexity

*/


public static int [] rotateArray(int [] arr, int k){
        for(int i = 0; i < k; i++){
            int j = arr.length-1, last = arr[j];
            while (j>0)
                arr[j]=arr[--j];
            arr[0] = last;
        }
        return arr;
}
