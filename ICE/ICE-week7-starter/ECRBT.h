#ifndef EC_BINARY_ROOTED_TREE
#define EC_BINARY_ROOTED_TREE

// define node class
class ECTreeNode
{
public:
	ECTreeNode(int id);
	~ECTreeNode();
	
	void SetLeftChild(ECTreeNode *pChild);
	void SetRightChild(ECTreeNode *pChild);
	ECTreeNode *GetLeftChild() const;
	ECTreeNode *GetRightChild() const;
	int GetNumLeavesUnder() const;		// get the total number of leaves below this node (including the current node if it is a leaf)
	int GetID() const { return idNode; }
	
private:
	bool IsLeaf() const;

	int idNode;
	ECTreeNode *pChildLeft;
	ECTreeNode *pChildRight;
};

// define a rooted binary tree
class ECRootedBinaryTree
{
public:
	ECRootedBinaryTree();
	~ECRootedBinaryTree();
	
	void SetRoot( ECTreeNode *pRootNew );
	ECTreeNode *GetRoot() const;
	
private:
	ECTreeNode *pRoot;
};

#endif
