
#include <iostream>

using namespace std;




template<class T>
class SingleLinkedList
{
public:
	struct Node
	{
		T Element;
		Node* next;
	};

	SingleLinkedList()
	{
		head = NULL;
	}

	~SingleLinkedList()
	{
		while (head != NULL)
		{
			Node* Tmp = head;
			head = head->next;
			delete Tmp;
		}
	}

	//添加删除，尾部，头部，中间，空
	void Add(Node* Loc, T value)
	{
		Node* TmpNode = new Node;
		TmpNode->Element = value;

		if (Loc==head)
		{
			TmpNode->next = head;
			head = TmpNode;
		}
		else
		{
			Node* ListNode = head;
			Node* LastNode = head;
			while(ListNode!=NULL)
			{
				Node* TmpListNode = ListNode;
				LastNode = ListNode;
				ListNode = ListNode->next;
				
				if (ListNode == Loc)
				{
					TmpListNode->next = TmpNode;
					TmpNode->next = ListNode;
					break;
				}
				
			}
			if (ListNode==NULL)
			{
				LastNode->next = TmpNode;
				TmpNode->next = NULL;
			}

		}
	}

	void Remove(Node* RemoveNode)
	{
		Node* TmpNode = head;
		Node* PrevNode = NULL;
		while (TmpNode!=NULL)
		{
			if (RemoveNode==TmpNode)
			{
				if (PrevNode)
				{
					PrevNode->next = RemoveNode->next;
					RemoveNode->next = NULL;
					delete RemoveNode;
				}
				else
				{
					RemoveNode->next = NULL;
					delete RemoveNode;
				}
				break;
			}

			PrevNode = TmpNode;
			TmpNode = TmpNode->next;
		}

	}

	void Print()
	{
		Node* TmpNode = head;
		while (TmpNode!=NULL)
		{
			cout << TmpNode->Element << ";";
			TmpNode = TmpNode->next;
		}
		cout << endl;
	}

	Node* GetNode(int Index)
	{
		int Count = 0;
		Node* n = head;
		while (n!=NULL)
		{
			if (Count==Index)
			{
				break;
			}
			n = n->next;
			++Count;
		}
		return n;
	}

private:
	Node* head;
	
};


int main()   //2,3,4,5,1
{
	SingleLinkedList<int> ss;
	ss.Add(NULL, 1);
	SingleLinkedList<int>::Node* n = ss.GetNode(0);
	ss.Add(n, 2);
	n = ss.GetNode(1);
	ss.Add(n, 3);
	n = ss.GetNode(2);
	ss.Add(n, 4);
	n = ss.GetNode(3);
	ss.Add(n, 5);

	ss.Remove(ss.GetNode(2));
	ss.Add(ss.GetNode(5), 6);
	ss.Remove(ss.GetNode(2));
	ss.Print();
	system("pause");
	return 0;
}
