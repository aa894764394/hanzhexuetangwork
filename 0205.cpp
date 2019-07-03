#include <iostream>
#include <map>
using namespace std;

class IntVector
{
public:
	int size() const
	{
		return num;
	}

	int Capacity() const 
	{
		return CapVal;
	}

	IntVector() :CapVal(1)
	{
		a = new int[CapVal];
	}

	IntVector(int Cap) :CapVal(Cap)
	{
		a = new int[CapVal];
	}

	~IntVector()
	{
		delete[] a;
	}

	void Dilatation(int val)
	{
		int* b = a;
		CapVal = 2 * CapVal;
		a = new int[CapVal];


		for (int i = 0;i < num;i++)
		{
			a[i] = b[i];
		}

		if (m.size() > 0)
		{
			for (int i = num - 1;i >= 0;--i)
			{
				m[i + 1] = m[i];
			}
		}

		a[num] = val;
		m[0] = num;
		++num;
		delete[] b;
	}

	void AddFirst(int val)
	{
		if (num==CapVal)
		{
			Dilatation(val);
		}
		else
		{
			a[num] = val;
			if (m.size()>0)
			{
				for (int i = num-1;i >= 0;--i)
				{
					m[i + 1] = m[i];
				}
			}
			m[0] = num;
			++num;
		}

	}


	void AddLast(int val)
	{
		if (num == CapVal)
		{
			Dilatation(val);
		}
		else
		{
			a[num] = val;
			m[num] = num;
			++num;
		}
	}

	int first() 
	{
		return a[m[0]];
	}

	int last() 
	{
		return a[m[num - 1]];
	}

	int get(int index) 
	{
		if (index > num || index < 0)
		{
			cout << "下标越界" << endl;
			return -1;
		}

		return a[m[index]];
	}

	void set(int index, int value)
	{
		if (index > num || index < 0)
		{
			cout << "下标越界" << endl;
			return;
		}
		int tempIndex = m[index];
		a[tempIndex] = value;
	}

	void add(int Index, int value)
	{
		if (Index>num)
		{
			return;
		}
		if (num == CapVal)
		{
			int* b = a;
			CapVal = 2 * CapVal;
			a = new int[CapVal];


			for (int i = 0;i < num;i++)
			{
				a[i] = b[i];
			}
			a[num] = value;
			//m[num] = num;
			++num;

			for (int i=num-1;i>=Index;--i)
			{
				m[i + 1] = m[i];
			}
			m[Index] = num;
			delete[] b;
		}
		else
		{
			a[num] = value;
			for (int i = num - 1;i >= Index;--i)
			{
				m[i + 1] = m[i];
			}
			m[Index] = num;
			++num;
		}
	}

	int Remove(int Index) 
	{
		if (Index>=num||Index<0)
		{
			cout << "下标越界" << endl;
			return -1;
		}

		int AIndex = m[Index];

		for (int i=m[Index];i<num;++i)
		{
			a[i] = a[i + 1];
		}

		for (int i=Index;i<num-1;++i)
		{
			m[i] = m[i + 1];
		}

		m.erase(num-1);
		--num;

		for (int i=0;i<num;++i)
		{
			if (m[i]>=AIndex)
			{
				--m[i];
			}
		}
		return 0;
	}

	int find(int value)
	{
		for (int i=0;i<num;++i)
		{
			if (a[m[i]]==value)
			{
				return i;
			}
		}
		return -1;
	}

	int findAndRemove(int value)
	{
		for (int i = 0;i < num;++i)
		{
			if (a[m[i]] == value)
			{
				Remove(i);
				return i;
			}
		}
		return -1;
	}

	void Shrink()
	{
		int* b = a;
		CapVal = num+1;
		a = new int[CapVal];


		for (int i = 0;i < num;i++)
		{
			a[i] = b[i];
		}
		delete[] b;
	}

	void Print()
	{
		cout << "理论上的顺序:" << endl;
		for (auto iter = m.begin();iter!=m.end();++iter)
		{
			cout << a[iter->second] << "," ;
		}
		cout << endl;
		cout << "实际的顺序" << endl;
		for (int i=0;i<num;i++)
		{
			cout << a[i] << "," ;
		}
		cout << endl;
		
	}

private:
	//vector元素的大小
	int num = 0;
	//Vector容量
	int CapVal;

	//实际管理元素的数组指针
	int *a;

	//逻辑Index到实际Index的映射
	map<int, int> m;


};

int main()
{
	IntVector a;
	for (int i=1;i<11;++i)
	{
		a.AddFirst(i);
	}
	for (int i = 1;i < 11;++i)
	{
		a.AddLast(i+30);
	}
	a.Print();
	cout << "第一个元素是:" << a.first() << endl;
	cout << "最后一个元素是:" << a.last() << endl;
	cout << "获取第8个值的元素:" << a.get(8) << endl;
	a.set(8, 88);
	cout << "设置完新的值后" << endl;
	a.Print();
	a.add(7, 77);
	a.add(6, 66);
	cout << "设置完新的值后" << endl;
	a.Print();
	a.Remove(6);
	a.Remove(7);
	a.Remove(8);
	cout << "设置完新的值后" << endl;
	a.Print();
	a.set(8, 88);
	cout << "设置完新的值后" << endl;
	a.Print();
	cout << "值为88的位置:" << a.find(88) << endl;
	cout << "删除值为88:" << a.findAndRemove(88) << endl;
	cout << "设置完新的值后" << endl;
	a.Print();
	system("pause");
	return 0;
}