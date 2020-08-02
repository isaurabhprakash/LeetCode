// URL : https://leetcode.com/problems/design-linked-list/

class Node {

public:
	Node(int pVal, Node * pNext) : val(pVal), next(pNext) {}

	int     val;
	Node *  next;
};

class MyLinkedList {

public:

	MyLinkedList();

	int     get(int pIndex);

	void    addAtHead(int pVal);

	void    addAtTail(int pVal);

	void    addAtIndex(int pIndex, int pVal);

	void    deleteAtIndex(int pIndex);

private:

	Node * vHead;
	Node * vTail;
	int     noOfElements;
};

/* Constructor */
MyLinkedList::MyLinkedList()
{
	vHead = nullptr;
	vTail = nullptr;
	noOfElements = 0;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int MyLinkedList::get(int pIndex)
{
	Node * temp = vHead;

	if (vHead == nullptr) {

		return -1;
	}

	if (pIndex == noOfElements - 1) {
		return vTail->val;
	}

	for (int i = 0; i < pIndex; ++i) {

		temp = temp->next;

		if (temp == nullptr) {

			return -1;
		}
	}

	return temp->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void MyLinkedList::addAtHead(int pVal)
{
	if (vHead == nullptr) {

		vHead = new Node(pVal, nullptr);

		// Since this is the only elemen in the list, the head and the tail would be same.
		vTail = vHead;

	} else {

		// Create a new node, point it to the current head and then make it the head.
		vHead = new Node(pVal, vHead);
	}

	noOfElements++;
}

/** Append a node of value val to the last element of the linked list. */
void MyLinkedList::addAtTail(int pVal)
{
	if (vHead == nullptr) {

		vHead = new Node(pVal, nullptr);

		// Since this is the only elemen in the list, the head and the tail would be same.
		vTail = vHead;

	} else {

		// Create a new node, make it the tail.
		vTail->next = new Node(pVal, nullptr);
		vTail = vTail->next;
	}
	noOfElements++;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void MyLinkedList::addAtIndex(int pIndex, int pVal)
{
	Node *  node_just_before_index = vHead;
	Node *  new_node;

	if (pIndex == noOfElements) {

		addAtTail(pVal);
		return;

	}

	if (pIndex > noOfElements) {

		return;

	}

	if (pIndex == 0) {
		addAtHead(pVal);
	}

	// Find the node just before the index where the new node is to be inserted
	for (int i = 0; i < pIndex - 1; ++i) {

		node_just_before_index = node_just_before_index->next;
	}

	new_node = new Node(pVal, node_just_before_index->next);
	node_just_before_index->next = new_node;
	noOfElements++;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void MyLinkedList::deleteAtIndex(int pIndex)
{
	Node *  node_just_before_index = vHead;
	Node *  node_to_be_deleted;

	if (pIndex >= noOfElements) {

		return;

	}

	if (pIndex == 0)
	{
		vHead = vHead->next;
		delete node_just_before_index;
		return;
	}

	if (vHead == vTail) {

		delete vHead;
		vHead = nullptr;
		vTail = nullptr;
		return;
	}

	// Find the node just before the index where the new node is to be inserted
	for (int i = 0; i < pIndex - 1; ++i) {

		node_just_before_index = node_just_before_index->next;
	}

	node_to_be_deleted = node_just_before_index->next;

	// We are deleting the Head
	if (node_to_be_deleted == vHead) {

		vHead = vHead->next;
		noOfElements--;

	} else if (node_to_be_deleted == vTail) {
		// We are deleting the Tail.
		node_just_before_index->next = nullptr;
		vTail = node_just_before_index;
		noOfElements--;

	} else {

		node_just_before_index->next = node_to_be_deleted->next;
		noOfElements--;
	}

	delete node_to_be_deleted;
}