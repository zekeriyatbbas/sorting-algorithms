#include "tweet.h"

int binarySearch(const std::vector<Tweet>& tweets, long long key, const std::string& sortBy)
{
	int left = 0;
	int right = tweets.size()-1; // we set the boundaries of our search
	if(sortBy == "tweetID"){
		while(left <= right){
			int mid = left + (right-left)/2;
        	if(tweets[mid].tweetID < key){
        	    left = mid+1;
        	}else{
        		right = mid-1;
        	}
		}
		if(tweets[left].tweetID == key)   return left;
	}
	else if(sortBy == "retweetCount"){
		while(left <= right){
			int mid = left + (right-left)/2;
        	if(tweets[mid].retweetCount < key){
        	    left = mid+1;
        	}else{
        		right = mid-1;
        	}
		}
		if(tweets[left].retweetCount == key)   return left;
	}else if(sortBy == "favoriteCount"){
		while(left <= right){
			int mid = left + (right-left)/2;
        	if(tweets[mid].favoriteCount < key){
        	    left = mid+1;
        	}else{
        		right = mid-1;
        	}
		}
		if(tweets[left].favoriteCount == key)   return left;
	}
	return -1; // we return -1 in case of non-existence of the key
}

int countAboveThreshold(const std::vector<Tweet>& tweets, const std::string& metric, int threshold) 
{	
	int return_value = 0;
	int size = tweets.size();
	if(metric == "tweetID"){
		for(int i = 0; i < size; i++){
			if(tweets[i].tweetID > threshold)	return_value++;
		}
	}
	else if(metric == "retweetCount"){
		for(int i = 0; i < size; i++){
			if(tweets[i].retweetCount > threshold)	return_value++;
		}
	}else if(metric == "favoriteCount"){
		for(int i = 0; i < size; i++){
			if(tweets[i].favoriteCount > threshold)	return_value++;
		}
	}
	return return_value;
}