class Node{
    int data;
    Node right;
    Node left;

    public Node(){
        this.data=0;
        this.right=null;
        this.left=null;
    }
    public Node(int data){
        this.data=data;
        this.right=null;
        this.left=null;
    }
}

public class arbitrarySumTree{
    Node root;
    public void convertTree(Node node){


    }


    public static void main(String[] args) {
        arbitrarySumTree tree= new arbitrarySumTree();
        tree.root = new Node(50);
        tree.root.left = new Node(7);
        tree.root.right = new Node(2);
        tree.root.left.left = new Node(3);
        tree.root.left.right = new Node(5);
        tree.root.right.left = new Node(1);
        tree.root.right.right = new Node(30);

        System.out.println("Inorder traversal before conversion is :");
        tree.printInorder(tree.root);

        tree.convertTree(tree.root);
        System.out.println("");

        System.out.println("Inorder traversal after conversion is :");
        tree.printInorder(tree.root);
    }
}