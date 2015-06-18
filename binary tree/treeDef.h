struct Btree
{
	int tdata;
	struct Btree *left;
	struct Btree *right;
};

typedef struct Btree btree;

struct Node
{
	btree *data;
	struct Node *next;
};

typedef struct Node node;

struct Queue
{
	node *front;
	node *rear;
};

typedef struct Queue queue;
