
struct linked_node {
	int data;
	struct linked_node *next;
};

struct linked_node *creati_list();
int addnode(int data, struct linked_node **head);
void show_list(struct linked_node *head);
