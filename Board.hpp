#pragma once

#include <string>
#include "Direction.hpp"

namespace ariel {
	class Board {
	public:
		char** arr;
		unsigned int rows;
		unsigned int cols;

		Board() {
			rows = 0;
			cols = 0;

			arr = NULL;
		}

		void post(unsigned int row, unsigned int col, Direction d, std::string s);
		void show();
		std::string read(unsigned int row, unsigned int col, Direction d, unsigned int len);
	};
};
