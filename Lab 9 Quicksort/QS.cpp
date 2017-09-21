#include "QS.h"
#include <sstream>

QS::QS()
{
	size = 0;
	list = NULL;
	initialSize = 0;
}

void QS::quickSort(int first, int last)
{
	if (last - first > 0)
	{
		int indexOfPivot = medianOfThree(first, last);
		indexOfPivot = partition(first, last, indexOfPivot);

		quickSort(first, indexOfPivot - 1);
		quickSort(indexOfPivot + 1, last);

	}
}

void QS::sortAll()
{
	if (size > 0)
	{
		quickSort(0, size - 1);
	}
}

void QS::swap(int positionOne, int positionTwo)
{
	int temp = 0;
	
	temp = list[positionOne];
	list[positionOne] = list[positionTwo];
	list[positionTwo] = temp;
}


int QS::medianOfThree(int left, int right)
{
	int middle = 0;
	int temp = 0;

	if (size == 0 || left >= right || left < 0 || right >= size || list == NULL)
		return -1;

	else
	{
		middle = (left + right) / 2;

		for (int count = 0; count < 3; count++)
		{
			int l = list[left];
			int m = list[middle];
			int r = list[right];

			if (list[left] > list[middle])
			{
				swap(left, middle);
			}

			if (list[middle] > list[right])
			{
				swap(middle, right);
			}
		}

		return middle;
	}
}

int QS::partition(int first, int last, int indexOfPivot)
{
	if (list == NULL || first < 0 || last >= size || first >= last || indexOfPivot < first || indexOfPivot > last)
		return -1;

	else 
	{
		int temp = 0;
		int up = 0;
		int down = 0;
		int pivot = list[indexOfPivot];

		up = first;
		down = last;

		swap(first, indexOfPivot);

		do
		{
			while (list[up] <= pivot && up < last)
			{
				up++;
			}

			while (list[down] > pivot && down > first)
			{
				down--;
			}

			if (up < down)
			{
				swap(up, down);
				cout << getArray() << endl;

			}
		} while (up < down);

		swap(first, down);

		return down;
	}
	return 0;
}

string QS::getArray() const
{
	stringstream ss;
	if (size == 0 || size == NULL)
	{
		return "";
	}

	else
	{
		for (int count = 0; count < size; count++)
		{
			if (count == (size - 1))
				ss << list[count];

			else
				ss << list[count] << ",";
		}
	}

	return ss.str();
}

int QS::getSize() const
{
	return size;
}

bool QS::addToArray(int toAdd)
{
	if (size != initialSize)
	{
		list[size] = toAdd;
		size++;
		return true;
	}

	else
		return false;
}

bool QS::createArray(int capacity)
{
	if (list != NULL)
		clear();

	if (capacity > 0)
	{
		initialSize = capacity;
		list = new int[capacity];
		return true;
	}

	else
		return false;

}

void QS::clear()
{
	size = 0;
	delete[] list;
	list = NULL;
}