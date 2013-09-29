/* Linked structure for a bst tree node. The whole tree is represented
   by a pointer to its root 
*/

typedef struct  {
 int data;
 bst_node* left;
 bst_node*  right;
}bst_node;

int s1;
int s2;
int s3;
int s4;

/*
 The following tree is represented by  the structure shown after it. 
 This is not a valid C code. It is just to show the structure of 
 the bst tree we'll use to test the code.  We need to create this 
 structure in the data part of our program.


          412
        /     \
      106     900
      / \     / \
     7  215 450  1024
    / \       \
   1   9      512

*/ 

bst_node* mytree =
{412,	
	{106, 
		{ 7,
		  { 1,
			0, 
			0
		  }, 
		  { 9,
			0,
			0
		   }
		}, 
		{ 215,
			0,
			0
		}
	}, 
	{ 900,
		{ 450,
			0,
			{ 512,
				0,
				0
			}
		},
		{ 1024, 
			0,
			0
		}
	}
}
				  	

/* stub code makes this call */
dosearch();

/* Returns the address of the node in the tree that has the item,
   or NULL if the item is not in the tree.
   Note: NULL is really 0.
*/

bst_node*  search(bst_node* tree, int item) {
 if(tree == NULL)
  return NULL;
 if(tree->data == item)
  return tree;
 if (tree->data > item)
	return search(tree->left, item);
 return search(tree->right, item);
}

void dosearch() {
 s1 = search(tree, 215);
 s2 = search(tree, 450);
 s3 = search(tree, 9);
 s4 = search(tree, 115);
}




/* The following is the start of the data part you have to add to your
  sm 213 assembly program to run it with the simulator.
  COmplete the tree structure and add some space for the stack.


.pos 0x400
# Data area
s1: .long 0             # s1
s2: .long 0             # s2
s3: .long 0             # s3
s4: .long 0             # s4

.pos 0x1000
tree:
    .long 412           # bst_node->data
    .long 0x1100	    # bst_node->left
    .long 0x1200	    # bst_node->right

.pos 0x1100
    .long 106          # data
    .long 0x1300	   # left
    .long 0x1400	   # right

.pos 0x1200
    .long 900	       # data
    .long 0x1500	   # left
    .long 0x1600	   # right


. . .

*/ 