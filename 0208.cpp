
#include <iostream>

using namespace std;




template<class T>
class DoubleLinkedList
{
public:
	struct Node
	{
		T Element;
		Node* Prev;
		Node* next;
	};

	DoubleLinkedList()
	{
		head = NULL;
		tail = NULL;
		
	}

	~DoubleLinkedList()
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

		if (Loc==head&&head!=NULL)
		{
			TmpNode->next = head;
			head->Prev = TmpNode;
			head = TmpNode;
			TmpNode->Prev = NULL;
		}
		else if (Loc==NULL)
		{
		   if (head==NULL)
		   {
			   head = TmpNode;
			   head->Prev = NULL;
			   head->next = tail;
		   }
		   else 
		   {
			   Node* TmpCurNode = head;
			   while (TmpCurNode->next!=tail)
			   {
				   TmpCurNode = TmpCurNode->next;
			   }
			   TmpCurNode->next = TmpNode;
			   TmpNode->Prev = TmpCurNode;
			   TmpNode->next = tail;
		   }

		}
		else
		{
			Node* ListNode = head;
			while(ListNode!=tail)
			{

				ListNode = ListNode->next;
				
				if (ListNode == Loc)
				{
					Node* TmpPrev = ListNode->Prev;
					TmpPrev->next = TmpNode;
					TmpNode->next = ListNode;
					ListNode->Prev = TmpNode;
					TmpNode->Prev = TmpPrev;
					break;
				}
				
			}
			if (ListNode==tail)
			{
				if (tail != NULL)
				{
					Node* TmpPrev = tail->Prev;
					TmpPrev->next = TmpNode;
					TmpNode->next = tail;
					tail->Prev = TmpNode;
					TmpNode->Prev = TmpPrev;
				}
				else
				{
					tail = TmpNode;
					TmpNode->Prev = head;
					TmpNode->next = NULL;
				}

			}

		}
	}

	void Remove(Node* RemoveNode)
	{
		Node* TmpNode = head;
		while (TmpNode!=tail)
		{
			if (RemoveNode==TmpNode)
			{
				Node* Prev = TmpNode->Prev;
				Node* Next = TmpNode->next;
				delete RemoveNode;
				if(Prev!=NULL)
				Prev->next = Next;

				if (Next!=NULL)
				{
					Next->Prev = Prev;
				}
				
				break;
			}
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
	Node* tail;
};


int main()   //2,3,4,5,1
{
	DoubleLinkedList<int> dl;
	dl.Add(NULL, 1);
	DoubleLinkedList<int>::Node* n = dl.GetNode(0);
	dl.Add(n, 2);
	n = dl.GetNode(1);
	dl.Add(n, 3);
	n = dl.GetNode(2);
	dl.Add(n, 4);
	n = dl.GetNode(3);
	dl.Add(n, 5);

	dl.Remove(dl.GetNode(2));
	dl.Add(dl.GetNode(5), 6);
	dl.Remove(dl.GetNode(2));
	dl.Print();
	system("pause");
	return 0;
}
