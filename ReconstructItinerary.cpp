//	332. Reconstruct Itinerary
//
//	Given a list of airline tickets represented by pairs of departure and arrival airports[from, to], reconstruct the itinerary in order.All of the tickets belong to a man who departs from JFK.Thus, the itinerary must begin with JFK.
//
//	Note:
//		1. If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.For example, the itinerary["JFK", "LGA"] has a smaller lexical order than["JFK", "LGB"].
//		2. All airports are represented by three capital letters(IATA code).
//		3. You may assume all tickets form at least one valid itinerary.
//
//	Example 1 :
//		tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
//		Return["JFK", "MUC", "LHR", "SFO", "SJC"].
//
//	Example 2 :
//		tickets = [["JFK", "SFO"], ["JFK", "ATL"], ["SFO", "ATL"], ["ATL", "JFK"], ["ATL", "SFO"]]
//		Return["JFK", "ATL", "JFK", "SFO", "ATL", "SFO"].
//		Another possible reconstruction is["JFK", "SFO", "ATL", "JFK", "ATL", "SFO"].But it is larger in lexical order.
//
//	Written by Zhanran Tang @ 5/27/2017
//
//	Ideas: Keep going from the start by choosing the minimum next. When stuck, add stuck pos into route then goes back.
//	Complexity: O(m) in time and space. m-input tickets size.


#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;

unordered_map<string, multiset<string>> flights;
vector<string> route;

void findRoute(string curAirport)
{
	while (!flights[curAirport].empty())
	{
		auto dest = flights[curAirport].begin();
		string destAirport = *dest;
		flights[curAirport].erase(dest);
		findRoute(destAirport);
	}
	route.push_back(curAirport);
}
vector<string> findItinerary(vector<pair<string, string>> tickets)
{
	for (int i = 0; i<tickets.size(); i++)
	{
		string from = tickets[i].first;
		string to = tickets[i].second;
		if (flights.find(from) == flights.end())
			flights.insert(pair<string, multiset<string>>(from, multiset<string>()));
		if (flights.find(to) == flights.end())
			flights.insert(pair<string, multiset<string>>(to, multiset<string>()));
		flights[from].insert(to);
	}
	findRoute("JFK");
	reverse(route.begin(), route.end());
	return route;
}

int main()
{
	/*vector<pair<string, string>> tickets ={
		pair<string, string>("EZE", "TIA"),pair<string, string>("EZE", "HBA"),pair<string, string>("AXA", "TIA"),
		pair<string, string>("JFK", "AXA"),pair<string, string>("ANU", "JFK"),pair<string, string>("ADL", "ANU"),
		pair<string, string>("TIA", "AUA"),pair<string, string>("ANU", "AUA"),pair<string, string>("ADL", "EZE"),
		pair<string, string>("ADL", "EZE"),pair<string, string>("EZE", "ADL"),pair<string, string>("AXA", "EZE"),
		pair<string, string>("AUA", "AXA"),pair<string, string>("JFK", "AXA"),pair<string, string>("AXA", "AUA"),
		pair<string, string>("AUA", "ADL"),pair<string, string>("ANU", "EZE"),pair<string, string>("TIA", "ADL"),
		pair<string, string>("EZE", "ANU"),pair<string, string>("AUA", "ANU") 
	};*/
	vector<pair<string, string>> tickets = { 
		pair<string, string>("JFK", "SFO"),pair<string, string>("JFK", "ATL"),pair<string, string>("SFO", "ATL"),
		pair<string, string>("ATL", "JFK"),pair<string, string>("ATL", "SFO")
	};
	vector<string> res = findItinerary(tickets);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}