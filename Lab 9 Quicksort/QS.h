#include "QSInterface.h"

class QS
{
	private:
		int* list;
		int size = 0;
		int initialSize;
		void swap(int, int);
		void quickSort(int, int);

	public:
		QS();
		~QS() { clear(); };
		void sortAll();
		int medianOfThree(int, int);
		int partition(int, int, int);
		string getArray() const;
		int getSize() const;
		bool addToArray(int);
		bool createArray(int);
		void clear();

};