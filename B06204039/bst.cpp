#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

//Input Constraints
#define MAX_TREE_NUM 10
#define MAX_NODE_NUM 1000
#define MIN_NODE_VALUE -500
#define MAX_NODE_VALUE 1000

int tree_num = 0;
int tree_height = 0;
int node_num = 0;
int node_values[MAX_NODE_NUM];
int max_level_values[MAX_NODE_NUM];

//Reference: https://www.geeksforgeeks.org/construct-a-binary-search-tree-from-given-postorder/
//BST structure
struct tree_node{
    int value;
    int height;
    int level;
    struct tree_node *left_node, *right_node;
};

struct tree_node* new_tree_node (int value){
	struct tree_node* tn = (struct tree_node*) malloc(sizeof(struct tree_node));
    tn->value = value;
    tn->height = 1;
    tn->level = 0;
    tn->left_node = NULL;
    tn->right_node = NULL;
 
    return tn;
}

struct tree_node* build_bst_from_postorder(int* index, int key, int min_value, int max_value, int level){
	struct tree_node* current_node = NULL;
    
	if (key >= min_value && key <= max_value){
		current_node = new_tree_node(key);
		current_node->level = level + 1;
		if(current_node->value > max_level_values[current_node->level]) max_level_values[current_node->level] = current_node->value;

		if (*index >= 1){
	    	*index = *index - 1;
	    	current_node->right_node = build_bst_from_postorder(index, node_values[*index], key, max_value, current_node -> level);
	    	current_node->left_node = build_bst_from_postorder(index, node_values[*index], min_value, key, current_node -> level);

	    	if (current_node->right_node) current_node->height = current_node->right_node->height + 1;
	    	if (current_node->left_node) current_node->height = max(current_node->height, current_node->left_node->height + 1);
	    }
    }

    return current_node;
}

//Reference: http://alrightchiu.github.io/SecondRound/binary-tree-traversalxun-fang.html#pre
void preorder_traversal(tree_node* current_node, ofstream& outfile){
    if (current_node) {
        outfile << current_node->value << " ";

        preorder_traversal(current_node->left_node, outfile);
        preorder_traversal(current_node->right_node, outfile);
    }
}

int main(int argc, char *argv[]){
    ifstream infile; 
    infile.open(argv[1]);
    ofstream outfile;
    outfile.open(argv[2]);

    // TODO: Please code here
    infile >> tree_num;

    for(int i=0; i<tree_num; i++){
    	// Read the tree
    	infile >> node_num;

    	for(int j=0; j<node_num; j++){
    		infile >> node_values[j];
    	}

        // Initialize the variables
    	int index = node_num - 1;
    	fill_n(max_level_values, node_num, MIN_NODE_VALUE - 1);

        // Build the BST from postorder sequence
    	tree_node* bst_root = build_bst_from_postorder(&index, node_values[index], MIN_NODE_VALUE, MAX_NODE_VALUE, -1);
    	tree_height = bst_root->height;

        // Get the preorder_traversal
    	preorder_traversal(bst_root, outfile);
    	outfile << endl;

    	outfile << tree_height << endl;

    	for(int j=0; j<tree_height; j++) outfile << max_level_values[j] << endl;
    	
    }

    infile.close();
    outfile.close();
}