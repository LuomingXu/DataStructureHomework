#pragma once
#include<iostream>
using namespace std;

namespace SequenceTable
{
	template<typename type> class List
	{
	public:
		List(int size);
		~List();
		void Insert(int i, type t);
		void Insert(type t);//向表中插入一个数据, 任然保持有序性
		void Display();
		bool DisplayByElement(type t);
		void Delete(int i);
		void Sort(bool isPositiveOrder);
	private:
		type* table;
		int tableSize;//链表的总长度, 在初始时就已经确定了
		int length;
	};

	template<typename type>
	inline List<type>::List(int size)
	{
		tableSize = size;

		table = new type[size];

		if (table==NULL)
		{
			cout << "\"table\" is NULL !" << endl;
			return;
		}

		length = 0;
	}

	template<typename type>
	inline List<type>::~List()
	{
		cout << endl << "call destructer function..." << endl;
		delete[]table;
		cout << "fun end..." << endl;
	}

	//插入数据; 这边的插入只能一次向后插入
	template<typename type>
	inline void List<type>::Insert(int i, type t)
	{
		if (i > length || i < 0)
		{
			cout << "插入的下标不合法";
			return;
		}

		if (i < length)//如果是向数据中间插入数据, 则不需要一次向后退
		{
			for (int j = tableSize - 1; j >= i; j--)
			{
				//cout << j << endl;
				table[j + 1] = table[j];
			}
		}
		
		table[i] = t;

		length++;
	}

	template<typename type>
	inline void List<type>::Insert(type t)
	{
		if (List<type>::DisplayByElement(t))
		{
			cout << "the number is exist !\nPlease input another number !" << endl;
			return;
		}

		for (int i = 0; i < length; i++)
		{
			if ((t - table[i]) < 0)
			{
				List<type>::Insert(i, t);
			}
		}
	}

	//显示所有数据
	template<typename type>
	inline void List<type>::Display()
	{
		for (int i = 0; i < length; i++)
		{
			cout << table[i] << "\t";
		}
		cout << endl << "all data is displayed !" << endl;
	}

	template<typename type>
	inline bool List<type>::DisplayByElement(type t)
	{
		for (int i = 0; i < length; i++)
		{
			if (table[i] == t)
			{
				cout << table[i] << endl;
				cout << "\"" << t << "\"" << " is exist !" << endl;
				return true;
			}
		}
		cout << "Number is not exited !" << endl;
		return false;
	}

	//依据下标来删除数据
	template<typename type>
	inline void List<type>::Delete(int i)
	{
	}
	//参数为-是否正序排列
	template<typename type>
	inline void List<type>::Sort(bool isPositiveOrder)
	{
	}

}