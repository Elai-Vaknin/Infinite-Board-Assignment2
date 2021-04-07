#include <iostream>
#include <stdexcept>
#include <sstream>

#include "Board.hpp"

using namespace std;

namespace ariel{
	void Board::post(unsigned int row, unsigned int col, Direction d, string s)
	{
		/* Extending Array if needed */
		unsigned int r = row + ((d == Direction::Vertical) ? s.length() : 0) + 1;
		unsigned int c = col + ((d == Direction::Horizontal) ? s.length() : 0) + 1;

		if (r > this->rows) {
			char** arr;
			arr = new char*[r];

			for (unsigned int i = 0; i < this->rows; i++)
				arr[i] = this->arr[i];

			for (unsigned int i = this->rows; i < r; i++) {
				arr[i] = new char[this->cols];

				/* Reset new added rows */
				for (int j = 0; j < this->cols; j++)
					arr[i][j] = '_';
			}
			
			delete[] this->arr;
			
			this->rows = r;
			this->arr = arr;
		}

		if (c > this->cols) {
			for (unsigned int i = 0; i < this->rows; i++) {
				char* arr = new char[c];

				for (unsigned int j = 0; j < this->cols; j++)
					arr[j] = this->arr[i][j];
				/* Reset new added columns */
				for (unsigned int j = this->cols; j < c; j++)
					arr[j] = '_';

				/* Delete previous array and replace with new */
				delete[] this->arr[i];

				this->arr[i] = arr;
			}
			this->cols = c;
		}

		/* Adding the string to the board */
		for (unsigned int i = 0; i < s.length(); i++) {
			unsigned int tempr = row + (d == Direction::Vertical ? i : 0);
			unsigned int tempc = col + (d == Direction::Horizontal ? i : 0);

			this->arr[tempr][tempc] = s[i];
		}
	}

	string Board::read(unsigned int row, unsigned int col, Direction d, unsigned int len)
	{
		string s = "";

		for (unsigned int i = 0; i < len; i++) {
			unsigned int r = row + ((d == Direction::Vertical) ? i : 0);
			unsigned int c = col + ((d == Direction::Horizontal) ? i : 0);

			if (r >= this->rows || c >= this->cols) s += "_";
			else					s += this->arr[r][c];
		}
	
		return s;
	}

	void Board::show()
	{
		for (unsigned int i = 0; i < this->rows; i++) {
			for (unsigned int j = 0; j < this->cols; j++) {
				cout << this->arr[i][j] << " ";
			}

			cout << endl;
		}
	}
};
    		
	





