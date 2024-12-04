#include "tweet.h"

std::vector<Tweet> readTweetsFromFile(const std::string& filename) 
{
	std::ifstream file(filename);
	std::string line;
	std::vector<Tweet> db;
	getline(file,line);
	while(std::getline(file,line)){
		std::stringstream ss(line);
		std::string value;
		std::vector<int> n;
		while(getline(ss,value,',')){
			n.push_back(stoi(value));
		}
		Tweet temp;
		temp.tweetID = n[0];
		temp.retweetCount = n[1];
		temp.favoriteCount = n[2];
		db.push_back(temp);
	}
	return db;
}

void writeTweetsToFile(const std::string& filename, const std::vector<Tweet>& tweets) 
{
	std::ofstream output_file(filename);
	output_file<<"tweetID"<<","<<"retweetCount"<<","<<"favoriteCount"<<"\n";
	for(int i = 0; i < tweets.size(); i++){
		output_file<<std::to_string(tweets[i].tweetID)<<","<<std::to_string(tweets[i].retweetCount)<<","<<std::to_string(tweets[i].favoriteCount)<<"\n";
	}
	output_file.close();
}