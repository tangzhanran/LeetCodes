//	166. Fraction to Recurring Decimal
//
//	Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
//
//	If the fractional part is repeating, enclose the repeating part in parentheses.
//
//	For example,
//
//	Given numerator = 1, denominator = 2, return "0.5".
//	Given numerator = 2, denominator = 1, return "2".
//	Given numerator = 2, denominator = 3, return "0.(6)".
//
//	Written by Zhanran Tang @ 5/2/2017
//
//	Idea:	Straight forward remainder operation.
//	Complexity:	O(n) n - decimal number(loop) length

#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

string fractionToDecimal(int numerator, int denominator)
{
	bool sign = false;
	if ((numerator>0 && denominator<0) || (numerator<0 && denominator>0))
		sign = true;
	long long num = labs(numerator);
	long long den = labs(denominator);
	vector<pair<long long, long long>> reminder_result;
	long long reminder = num%den;
	long long result = num / den;
	pair<long long, long long> p(reminder, result);
	reminder_result.push_back(p);
	int loop_start = -1;
	while (reminder != 0)
	{
		num = 10 * reminder;
		reminder = num%den;
		result = num / den;
		for (int i = 0; i<reminder_result.size(); i++)
		{
			if (reminder == reminder_result[i].first)
			{
				loop_start = i;
				break;
			}
		}
		reminder_result.push_back(pair<int, int>(reminder, result));
		if (loop_start != -1)
			break;
	}
	stringstream ss;
	string tmp = "";
	string output = "";
	if (sign)
		output += '-';
	ss << reminder_result[0].second;
	ss >> tmp;
	ss.str("");
	output += tmp;
	tmp = "";
	if (reminder_result.size() == 1)
		return output;
	output += '.';
	for (int i = 1; i <= loop_start; i++)
	{
		ss.clear();
		ss << reminder_result[i].second;
		ss >> tmp;
		ss.str("");
		output += tmp;
		tmp = "";
	}
	int k = 0;
	if (loop_start > -1)
	{
		output += '(';
		k = loop_start;
	}
	for (int i = k + 1; i<reminder_result.size(); i++)
	{
		ss.clear();
		ss << reminder_result[i].second;
		ss >> tmp;
		ss.str("");
		output += tmp;
		tmp = "";
	}
	if (loop_start > -1)
		output += ')';
	return output;
}

int main()
{
	cout << fractionToDecimal(-1, -2147483648) << endl;
	system("pause");
	return 0;
}