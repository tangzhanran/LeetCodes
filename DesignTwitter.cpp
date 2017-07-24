#include "Header.h"

using namespace std;

class Twitter {
private:
	unordered_map<int, unordered_set<int>> follows;    //first follows seconds
													   //unordered_map<int, vector<int>> followers;  //first is followed by seconds
	unordered_map<int, vector<int>> tweets; //first's tweets timeid
	unordered_map<int, int> timeline; //<timeid,id>

	int time;
public:
	/** Initialize your data structure here. */
	Twitter()
	{
		time = 0;
	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId)
	{
		if (follows.find(userId) == follows.end())
			follows[userId].insert(userId);
		tweets[userId].push_back(time);
		timeline[time] = tweetId;
		time++;
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId)
	{
		vector<int> userfeeds;
		if (follows.find(userId) != follows.end())
		{
			priority_queue<int, vector<int>, greater<int>> new10feed;
			for (auto i = follows[userId].begin(); i != follows[userId].end(); i++)
			{
				int followeeid = *i;
				if (tweets.find(followeeid) != tweets.end())
				{
					vector<int> followeetweets = tweets[followeeid];
					for (int j = 0; j<followeetweets.size(); j++)
					{
						new10feed.push(followeetweets[j]);
						if (new10feed.size() > 10)
						{
							new10feed.pop();
						}
					}
				}
			}
			while (!new10feed.empty())
			{
				userfeeds.push_back(timeline[new10feed.top()]);
				new10feed.pop();
			}
			reverse(userfeeds.begin(), userfeeds.end());
		}
		return userfeeds;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId)
	{
		if (follows.find(followerId) == follows.end())
			follows[followerId].insert(followerId);
		follows[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId)
	{
		follows[followerId].erase(followeeId);
	}
};

/**
* Your Twitter object will be instantiated and called as such:
* Twitter obj = new Twitter();
* obj.postTweet(userId,tweetId);
* vector<int> param_2 = obj.getNewsFeed(userId);
* obj.follow(followerId,followeeId);
* obj.unfollow(followerId,followeeId);
*/

int main()
{
	Twitter obj;
	vector<int> news;
	obj.postTweet(1, 5);
	obj.follow(1, 2);
	obj.follow(2, 1);
	news = obj.getNewsFeed(2);
	for (int i = 0; i < news.size(); i++)
		cout << news[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}