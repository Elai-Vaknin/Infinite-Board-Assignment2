#include "doctest.h"
#include "Board.hpp"
#include "Direction.hpp"

using namespace ariel;

Board myb;
	
TEST_CASE("Board posts") {
	myb.post(0,0,Direction::Horizontal, "Hello");
	myb.post(0,0,Direction::Vertical, "to you");
	myb.post(0,3,Direction::Horizontal, "Some dog related post");
	myb.post(1,1,Direction::Vertical, "Awesome");
	myb.post(2,3,Direction::Horizontal, "Word");
	myb.post(3,0,Direction::Horizontal, "A very long sentence");
	myb.post(0,7,Direction::Vertical, "Sunshine");
	myb.show();
}

TEST_CASE("Board read horizontal") {
	CHECK(myb.read(0,0,Direction::Horizontal, 11) == "telSomeSdog");
    	CHECK(myb.read(1,0,Direction::Horizontal, 8) == "oA_____u");
    	CHECK(myb.read(2,0,Direction::Horizontal, 10) == " w_Wordn__");
    	CHECK(myb.read(3,0,Direction::Horizontal, 22) == "A very song sentence__");
    	CHECK(myb.read(4,0,Direction::Horizontal, 8) == "os_____h");
    	CHECK(myb.read(5,0,Direction::Horizontal, 9) == "uo_____i_");
    	CHECK(myb.read(6,0,Direction::Horizontal, 8) == "_m_____n");
    	CHECK(myb.read(7,0,Direction::Horizontal, 8) == "_e_____e");
	CHECK(myb.read(8,0,Direction::Horizontal, 10) == "__________");
}

TEST_CASE("Board read vertical") {
	CHECK(myb.read(0,0,Direction::Vertical, 6) == "to Aou");
    	CHECK(myb.read(0,1,Direction::Vertical, 8) == "eAw some");
    	CHECK(myb.read(0,2,Direction::Vertical, 4) == "l__v");
    	CHECK(myb.read(0,3,Direction::Vertical, 4) == "S_We");
    	CHECK(myb.read(0,4,Direction::Vertical, 4) == "o_or");
    	CHECK(myb.read(0,5,Direction::Vertical, 4) == "m_ry");
    	CHECK(myb.read(0,6,Direction::Vertical, 4) == "e_d ");
    	CHECK(myb.read(0,7,Direction::Vertical, 8) == "Sunshine");
    	CHECK(myb.read(0,8,Direction::Vertical, 5) == "d__o_");
    	CHECK(myb.read(0,9,Direction::Vertical, 6) == "o__n__");
    	CHECK(myb.read(0,10,Direction::Vertical, 4) == "g__g");
}

TEST_CASE("Board infinity check") {
	myb.post(10002,19998,Direction::Horizontal, "Simple");
	myb.post(10001,20000,Direction::Vertical, "Test");
	
	CHECK(myb.read(100,200,Direction::Vertical, 5) == "_____");
	CHECK(myb.read(1000,2000,Direction::Vertical, 5) == "_____");
	CHECK(myb.read(10002,19998, Direction::Horizontal, 6) == "Sieple");
	CHECK(myb.read(10000,20000, Direction::Vertical, 6) == "_Test_");
}
