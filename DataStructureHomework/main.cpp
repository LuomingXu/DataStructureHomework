#include<iostream>
#include"list.h"
using namespace std;

#ifdef SequenceList


#pragma region List_Sequence

template<typename type> class List
{
public:
	List(int size);
	~List();
	void Insert(int i, type t);
	void Insert(type t);//向表中插入一个数据, 任然保持有序性
	int GetTypeByIndex(int i);
	void Display();
	bool DisplayByElement(type t);
	int GetLength();
private:
	type* table;
	int tableSize;//链表的总长度, 在初始时就已经确定了
	int length = 0;
};

template<typename type>
inline List<type>::List(int size)
{
	tableSize = size;

	table = new type[size];

	if (table == NULL)
	{
		cout << "\"table\" is NULL !" << endl;
		return;
	}

	length = 0;
}

template<typename type>
inline List<type>::~List()
{
	/*cout << endl << "call destructer function..." << endl;
	delete[] List<type>::table;
	cout << "fun end..." << endl;

	system("pause");*/
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
		for (int j = length; j >= i; j--)
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

	if (t > table[length])
	{
		Insert(length, t);
		std::cout << "Insert is succeed" << endl;
		return;
	}

	for (int i = 0; i < length; i++)
	{
		if ((t - table[i]) < 0)
		{
			Insert(i, t);
			std::cout << "Insert is succeed" << endl;
			break;
		}
	}
}

template<typename type>
int List<type>::GetTypeByIndex(int i)
{
	return table[i];
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

template<typename type>
int List<type>::GetLength()
{
	return List<type>::length;
}

#pragma endregion

void printMeau()
{
	cout << "WELCOME USERS !";
}

void Meau()
{
	std::cout << endl;
	std::cout << "The Meau..." << endl;
	std::cout << "1 Display" << endl;
	std::cout << "2 Insert" << endl;
	std::cout << "3 Search" << endl;
	std::cout << "4 Copy" << endl;
	std::cout << "-1 exit" << endl;
}

int main()
{
	int choice = 0;
	int tableSize = 0;
	std::cout << "Please input the table size !" << endl;
	std::cin >> tableSize;
	List<int> table(tableSize);

	int cinTemp = 0;
	int lastNumer = 0;

	while (choice != -1)
	{
		if (choice == 0)
		{
			std::cout << "Please input the first number !" << endl;
			std::cin >> cinTemp;
			lastNumer = cinTemp;
			table.Insert(0, cinTemp);
			for (int i = 1; i < tableSize; i++)
			{
				cout << "Please input the " << i + 1 << " number !" << endl;
				cin >> cinTemp;
				while (cinTemp <= lastNumer)
				{
					std::cout << "Please input a larger number !" << endl;
					std::cin >> cinTemp;
				}
				table.Insert(i, cinTemp);
				lastNumer = cinTemp;
			}
		}
		else if (choice == 1)
		{
			table.Display();
		}
		else if (choice == 2)
		{
			std::cout << "Please input the number which you want insert " << endl;
			int temp = 0;
			std::cin >> temp;
			table.Insert(temp);
		}
		else if (choice == 3)
		{
			std::cout << "Please input the number which you want search " << endl;
			int temp = 0;
			std::cin >> temp;
			table.DisplayByElement(temp);
		}
		else if (choice == 4)
		{
			int length = table.GetLength();
			int doubleLength = length * 2;
			//本来想用switch的, 但是在用switch的时候, 在这边重新定义一个List<>的时候回出现一个
			//不知道什么鬼错误, 为了方便起见就用了if_else语句来实现
			List<int> table2(doubleLength);

			for (int i = 0; i < length; i++)
			{
				table2.Insert(i, table.GetTypeByIndex(i));
			}

			for (int i = length; i < doubleLength; i++)
			{
				table2.Insert(i, table.GetTypeByIndex(--length));
			}
			cout << table2.GetLength() << endl;
			table2.Display();
		}
		else
		{
			std::cout << "the choice is not exist !" << endl;
		}

		Meau();
		std::cin >> choice;
	}

#pragma region rubbish
	//table.Display();
	//table.DisplayByElement(5);

	//table.Insert(4);
	//table.Display();

	//int length = table.GetLength();
	//int doubleLength = length * 2;
	//List<int> table2(doubleLength);

	//for (int i = 0; i < length; i++)
	//{
	//	table2.Insert(i, table.GetTypeByIndex(i));
	//}

	//for (int i = length; i < doubleLength; i++)
	//{
	//	table2.Insert(i, table.GetTypeByIndex(--length));
	//}
	//cout << table2.GetLength() << endl;
	//table2.Display();
#pragma endregion

	if (choice == -1)
	{
		system("exit");
	}
	/*int temp;
	std::cin >> temp;*/
	return 0;
}

#endif // SequenceList

#ifdef LinkedList

void Meau()
{
	std::cout << endl;
	std::cout << "The Meau..." << endl;
	std::cout << "1 Display" << endl;
	std::cout << "2 Insert" << endl;
	std::cout << "3 Search" << endl;
	std::cout << "4 Copy" << endl;
	std::cout << "-1 exit" << endl;
	std::cout << "Please input your choice..." << endl;
}

int main()
{
	int choice = 0;
	int size = 0;
	int temp = 0;
	int i = 1;
	int flag = 0;//judge whether insertion is successful
	SingleList<int> list;

	while (choice != -1)
	{
		switch (choice)
		{
		case 0:
			std::cout << "Please input the size of the LinkedList..." << endl;
			std::cin >> size;
			list.CreatList(size);
			break;
		case 1:
			list.Display();
			break;
		case 2:
			flag = 0;//initialize flag
			std::cout << "Please input the number which you want to \"INSERT\" into the LinkesList :";
			std::cin >> temp;
			for (int i = 1; i < list.GetListLength(); i++)
			{
				if (temp > list.DisplayByPosition(i)  && temp < list.DisplayByPosition(i + 1))
				{
					list.InsertNode(i + 1,temp);
					flag++;
					break;
				}
			}
			if (temp  > list.DisplayByPosition(list.GetListLength()))//larger than the last number
			{
				list.Add(temp);
				flag++;
			}
			if (flag == 0)
			{
				std::cout << "This number is smaller than any number in the LinkedList !" << endl;
				std::cout << "This time the insertion is unsuccessful !" << endl;
			}
			else if(flag == 1)
			{
				std::cout << "INSERTION is successful..." << endl;
			}
			break;
		case 3:
			flag = 0;
			std::cout << "Please input the number which you want to \"SERACH\" into the LinkesList :";
			std::cin >> temp;
			for (int i = 1; i < list.GetListLength(); i++)
			{
				if (temp == list.DisplayByPosition(i))
				{
					std::cout << "The number which you want to search is EXIT ! &it is@" << i << endl;
					flag++;
					break;
				}
			}
			if (flag == 0)
			{
				std::cout << "The number which you want to search is NOT EXIT !" << endl;
			}
			break;
		case 4:	
			for (i = 1; i < size +1; i++)
			{
				std::cout<< list.DisplayByPosition(i) << "  ";
			}
			for ( i-- ; i > 0; i--)
			{
				std::cout << list.DisplayByPosition(i) << "  ";
			}
			std::cout << endl;
			break;
		case -1:
			break;
		default:
			std::cout << "There is no such CHOICE !" << endl;
			break;
		}

		Meau();
		std::cin >> choice;
	}
	
	std::cout << "Please input any key to exit..." << endl;
	getchar();
	return 0;
}

#endif // LinkedList
