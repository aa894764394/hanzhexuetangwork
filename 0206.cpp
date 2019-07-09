#include <iostream>
#include <map>
using namespace std;

template<class T>
class BiVector
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

	BiVector() :CapVal(1)
	{
		a = new T[CapVal];
	}

	BiVector(int Cap) :CapVal(Cap)
	{
		a = new T[CapVal];
	}

	~BiVector()
	{
		delete[] a;
	}

	void Dilatation(T val,bool IsFirst)
	{
		T* b = a;
		CapVal = 2 * CapVal;
		a = new T[CapVal];


		for (int i = 0;i < num;i++)
		{
			a[i] = b[i];
		}

		if (m.size() > 0&&IsFirst)
		{
			for (int i = num - 1;i >= 0;--i)
			{
				m[i + 1] = m[i];
			}
		}

		a[num] = val;
		delete[] b;
	}



	void AddFirst(T val)
	{
		if (num==CapVal)
		{
			Dilatation(val,true);
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
		}
		m[0] = num;
		++num;

	}


	void AddLast(T val)
	{
		if (num == CapVal)
		{
			Dilatation(val,false);
		}
		else
		{
			a[num] = val;
		}
		m[num] = num;
		++num;
	}

	T first() 
	{
		return a[m[0]];
	}

	T last() 
	{
		return a[m[num - 1]];
	}

	T get(int index) 
	{
		if (index > num || index < 0)
		{
			cout << "�±�Խ��" << endl;
			index = 0;
		}

		return a[m[index]];
	}

	void set(int index, T value)
	{
		if (index > num || index < 0)
		{
			cout << "�±�Խ��" << endl;
			return;
		}
		int tempIndex = m[index];
		a[tempIndex] = value;
	}

	void add(int Index, T value)
	{
		if (Index>num)
		{
			return;
		}
		if (num == CapVal)
		{
			T* b = a;
			CapVal = 2 * CapVal;
			a = new T[CapVal];


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
			cout << "�±�Խ��" << endl;
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

	int find(T value)
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

	int findAndRemove(T value)
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
		T* b = a;
		CapVal = num+1;
		a = new T[CapVal];


		for (int i = 0;i < num;i++)
		{
			a[i] = b[i];
		}
		delete[] b;
	}

	void Print()
	{
		cout << "�����ϵ�˳��:" << endl;
		for (auto iter = m.begin();iter!=m.end();++iter)
		{
			cout << a[iter->second] << "," ;
		}
		cout << endl;
		cout << "ʵ�ʵ�˳��" << endl;
		for (int i=0;i<num;i++)
		{
			cout << a[i] << "," ;
		}
		cout << endl;
		
	}

private:
	//vectorԪ�صĴ�С
	int num = 0;
	//Vector����
	int CapVal;

	//ʵ�ʹ���Ԫ�ص�����ָ��
	T *a;

	//�߼�Index��ʵ��Index��ӳ��
	map<int, int> m;


};

int main()
{
	BiVector<int> a;
	for (int i=1;i<11;++i)
	{
		a.AddFirst(i);
	}
	for (int i = 1;i < 11;++i)
	{
		a.AddLast(i + 30);
	}
	a.Print();
	cout << "��һ��Ԫ����:" << a.first() << endl;
	cout << "���һ��Ԫ����:" << a.last() << endl;
	cout << "��ȡ��8��ֵ��Ԫ��:" << a.get(8) << endl;
	a.set(8, 88);
	cout << "�������µ�ֵ��" << endl;
	a.Print();
	a.add(7, 77);
	a.add(6, 66);
	cout << "�������µ�ֵ��" << endl;
	a.Print();
	a.Remove(6);
	a.Remove(7);
	a.Remove(8);
	cout << "�������µ�ֵ��" << endl;
	a.Print();
	a.set(8, 88);
	cout << "�������µ�ֵ��" << endl;
	a.Print();
	cout << "ֵΪ88��λ��:" << a.find(88) << endl;
	cout << "ɾ��ֵΪ88:" << a.findAndRemove(88) << endl;
	cout << "�������µ�ֵ��" << endl;
	a.Print();
	system("pause");
	return 0;
}