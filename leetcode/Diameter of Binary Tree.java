public class TreeNode {
    int val, leftPath, rightPath;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; rightPath = leftPath = 0;}
 }

class Diam { // for call by reference
    int d;
    Diam() {d = 0;}
}
 
class Solution {
    int diameterOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        Diam diam = new Diam();
        traverse(root, diam);
        return diam.d;
    }
    
    void traverse (TreeNode node, Diam diam) {
        if (node.left != null) {
            traverse(node.left, diam);
            node.leftPath = 1 + Integer.max(node.left.leftPath, node.left.rightPath);
        } else node.leftPath =  0;
        if (node.right != null) {
            traverse(node.right, diam);
            node.rightPath = 1 + Integer.max(node.right.leftPath, node.right.rightPath);
        } else node.rightPath = 0;
        diam.d = Integer.max(diam.d, node.leftPath + node.rightPath);
    }
}
