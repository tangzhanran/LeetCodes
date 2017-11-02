//	6. ZigZag Conversion
//
//	The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
//	(you may want to display this pattern in a fixed font for better legibility)
//
//	P   A   H   N
//	A P L S I I G
//	Y   I   R
//	And then read line by line : "PAHNAPLSIIGYIR"
//	Write the code that will take a string and make this conversion given a number of rows :
//
//	string convert(string text, int nRows);
//	convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
//
//	Written by Zhanran Tang @ 9/22/2017
//
//	Ideas: 
//		For each char in the first row: numRows-1 char are under it and numRows-2 char are in next column going back.
//		For each char in the last row: numRows-2 char are in next column and numRows-1 down to next last.
//		For each char in the ith row(not 1st and last): 
//			Going down and up: numRows-i char are under it and numRows-i-1 while going up.
//			Going up and down: doble i-2 and one in 1st row.
//		So:
//			1st rows char are in 0+2*(numRows-1) index
//			last rows char are in numRows-1+2*(numRows-1)
//			ith rows char are in i-1+ 2*(numRows-i)or2*(i-2) back and forth.
//	Complexity:	O(n) in time, O(1) in space.

#include "Header.h"

using namespace std;

string convert(string s, int numRows)
{
	string res = "";
	for (int i = 0; i<s.length(); i = i + 2 * numRows - 2)
		res += s[i];
	for (int i = 2; i<numRows; i++)
	{
		bool reverseflag = false;
		int k = i - 1;
		while (k < s.length())
		{
			res += s[k];
			if (!reverseflag)
				k += 2 * (numRows - i);
			else
				k += 2 * (i - 1);
			reverseflag = !reverseflag;
		}
	}
	for (int i = numRows - 1; i<s.length(); i = i + 2 * numRows - 2)
		res += s[i];
	return res;
}