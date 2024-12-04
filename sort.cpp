#include "tweet.h"

void bubbleSort(std::vector<Tweet>& tweets, const std::string& sortBy, bool ascending) 
{
	int size = tweets.size();
	if(ascending) // here we check if the sorting will be in an ascending order or not
	{
		if(sortBy == "tweetID"){ // sorted by tweetID in ascending order
			for(int i = 0; i < size-1; i++){
				for(int j = 0; j < size-i-1; j++){
					if(tweets[j].tweetID > tweets[j+1].tweetID){
						Tweet temp = tweets[j];
						tweets[j]= tweets[j+1];
						tweets[j+1]= temp;
					}
				}
			}
		}else if(sortBy == "retweetCount"){ // sorted by retweetCount in ascending order
			for(int i = 0; i < size-1; i++){
				for(int j = 0; j < size-i-1; j++){
					if(tweets[j].retweetCount > tweets[j+1].retweetCount){
						Tweet temp = tweets[j];
						tweets[j]= tweets[j+1];
						tweets[j+1]= temp;
					}
				}
			}
		}else if(sortBy == "favoriteCount"){ // sorted by favoriteCount in ascending order
			for(int i = 0; i < size-1; i++){
				for(int j = 0; j < size-i-1; j++){
					if(tweets[j].favoriteCount > tweets[j+1].favoriteCount){
						Tweet temp = tweets[j];
						tweets[j]= tweets[j+1];
						tweets[j+1]= temp;
					}
				}
			}
		}
	}else // if not ascending, we branch here to sort the values in a descending order
	{
		if(sortBy == "tweetID"){ // sorted by tweetID in descending order
			for(int i = 0; i < size-1; i++){
				for(int j = 0; j < size-i-1; j++){
					if(tweets[j].tweetID < tweets[j+1].tweetID){
						Tweet temp = tweets[j];
						tweets[j]= tweets[j+1];
						tweets[j+1]= temp;
					}
				}
			}
		}else if(sortBy == "retweetCount"){	// sorted by retweetCount in descending order
			for(int i = 0; i < size-1; i++){
				for(int j = 0; j < size-i-1; j++){
					if(tweets[j].retweetCount < tweets[j+1].retweetCount){
						Tweet temp = tweets[j];
						tweets[j]= tweets[j+1];
						tweets[j+1]= temp;
					}
				}
			}
		}else if(sortBy == "favoriteCount"){ // sorted by favoriteCount in descending order
			for(int i = 0; i < size-1; i++){
				for(int j = 0; j < size-i-1; j++){
					if(tweets[j].favoriteCount < tweets[j+1].favoriteCount){
						Tweet temp = tweets[j];
						tweets[j]= tweets[j+1];
						tweets[j+1]= temp;
					}
				}
			}
		}
	}
}

void insertionSort(std::vector<Tweet>& tweets, const std::string& sortBy, bool ascending) 
{
	int size = tweets.size();
	if(ascending) // here we check if the sorting will be in an ascending order or not
	{
		if(sortBy == "tweetID"){ // sorted by tweetID in ascending order
			for(int i = 1; i < size; i++){
				int j = i-1;
				int key = tweets[i].tweetID;
				Tweet temp = tweets[i];
				while(j >= 0 && key < tweets[j].tweetID){
					tweets[j+1] = tweets[j];
					j--;
				}
				tweets[j+1] = temp;
			}
		}else if(sortBy == "retweetCount"){ // sorted by retweetCount in ascending order
			for(int i = 1; i < size; i++){
				int j = i-1;
				int key = tweets[i].retweetCount;
				Tweet temp = tweets[i];
				while(j >= 0 && key < tweets[j].retweetCount){
					tweets[j+1] = tweets[j];
					j--;
				}
				tweets[j+1] = temp;
			}
		}else if(sortBy == "favoriteCount"){ // sorted by favoriteCount in ascending order
			for(int i = 1; i < size; i++){
				int j = i-1;
				int key = tweets[i].favoriteCount;
				Tweet temp = tweets[i];
				while(j >= 0 && key < tweets[j].favoriteCount){
					tweets[j+1] = tweets[j];
					j--;
				}
				tweets[j+1] = temp;
			}
		}
	}else // if not ascending, we branch here to sort the values in a descending order
	{
		if(sortBy == "tweetID"){ // sorted by tweetID in descending order
			for(int i = 1; i < size; i++){
				int j = i-1;
				int key = tweets[i].tweetID;
				Tweet temp = tweets[i];
				while(j >= 0 && key > tweets[j].tweetID){
					tweets[j+1] = tweets[j];
					j--;
				}
				tweets[j+1] = temp;
			}
		}else if(sortBy == "retweetCount"){ // sorted by retweetCount in descending order
			for(int i = 1; i < size; i++){
				int j = i-1;
				int key = tweets[i].retweetCount;
				Tweet temp = tweets[i];
				while(j >= 0 && key > tweets[j].retweetCount){
					tweets[j+1] = tweets[j];
					j--;
				}
				tweets[j+1] = temp;
			}
		}else if(sortBy == "favoriteCount"){ // sorted by favoriteCount in descending order
			for(int i = 1; i < size; i++){
				int j = i-1;
				int key = tweets[i].retweetCount;
				Tweet temp = tweets[i];
				while(j >= 0 && key > tweets[j].retweetCount){
					tweets[j+1] = tweets[j];
					j--;
				}
				tweets[j+1] = temp;
			}
		}
	}
}

void merge(std::vector<Tweet>& tweets, int left, int mid, int right, const std::string& sortBy, bool ascending) 
{
	if(ascending) // ascending case
	{
		if(sortBy == "tweetID"){
			std::vector<Tweet> temp(right - left+1);
			int tl = left;
			int tr = mid+1;
			int k = 0;
			while(tl <= mid && tr <= right){
				if(tweets[tl].tweetID < tweets[tr].tweetID){
					temp[k++] = tweets[tl++];
				}else{
					temp[k++] = tweets[tr++];
				}
			}
			while(tl <= mid){
				temp[k++] = tweets[tl++];
			}
			while(tr <= right){
				temp[k++] = tweets[tr++];
			}
			// now we copy the sorted array into original array
			int j = 0;
			for(int i = left; i <= right; i++){
        		tweets[i] = temp[j++];
    		}
		}else if(sortBy == "retweetCount"){
			std::vector<Tweet> temp(right - left + 1);
			int tl = left;
			int tr = mid+1;
			int k = 0;
			while(tl <= mid && tr <= right){
				if(tweets[tl].retweetCount < tweets[tr].retweetCount){
					temp[k++] = tweets[tl++];
				}else{
					temp[k++] = tweets[tr++];
				}
			}
			while(tl <= mid){
				temp[k++] = tweets[tl++];
			}
			while(tr <= right){
				temp[k++] = tweets[tr++];
			}
			// now we copy the sorted array into original array
			int j = 0;
			for(int i = left; i <= right; i++){
        		tweets[i] = temp[j++];
    		}
		}else if(sortBy == "favoriteCount"){
			std::vector<Tweet> temp(right - left + 1);
			int tl = left;
			int tr = mid+1;
			int k = 0;
			while(tl <= mid && tr <= right){
				if(tweets[tl].favoriteCount < tweets[tr].favoriteCount){
					temp[k++] = tweets[tl++];
				}else{
					temp[k++] = tweets[tr++];
				}
			}
			while(tl <= mid){
				temp[k++] = tweets[tl++];
			}
			while(tr <= right){
				temp[k++] = tweets[tr++];
			}
			// now we copy the sorted array into original array
			int j = 0;
			for(int i = left; i <= right; i++){
        		tweets[i] = temp[j++];
    		}
		}
	}else // descending case
	{
		if(sortBy == "tweetID"){
			std::vector<Tweet> temp(right - left+1);
			int tl = left;
			int tr = mid+1;
			int k = 0;
			while(tl <= mid && tr <= right){
				if(tweets[tl].tweetID > tweets[tr].tweetID){
					temp[k++] = tweets[tl++];
				}else{
					temp[k++] = tweets[tr++];
				}
			}
			while(tl <= mid){
				temp[k++] = tweets[tl++];
			}
			while(tr <= right){
				temp[k++] = tweets[tr++];
			}
			// now we copy the sorted array into original array
			int j = 0;
			for(int i = left; i <= right; i++){
        		tweets[i] = temp[j++];
    		}
		}else if(sortBy == "retweetCount"){
			std::vector<Tweet> temp(right - left + 1);
			int tl = left;
			int tr = mid+1;
			int k = 0;
			while(tl <= mid && tr <= right){
				if(tweets[tl].retweetCount > tweets[tr].retweetCount){
					temp[k++] = tweets[tl++];
				}else{
					temp[k++] = tweets[tr++];
				}
			}
			while(tl <= mid){
				temp[k++] = tweets[tl++];
			}
			while(tr <= right){
				temp[k++] = tweets[tr++];
			}
			// now we copy the sorted array into original array
			int j = 0;
			for(int i = left; i <= right; i++){
        		tweets[i] = temp[j++];
    		}
		}else if(sortBy == "favoriteCount"){
			std::vector<Tweet> temp(right - left + 1);
			int tl = left;
			int tr = mid+1;
			int k = 0;
			while(tl <= mid && tr <= right){
				if(tweets[tl].favoriteCount > tweets[tr].favoriteCount){
					temp[k++] = tweets[tl++];
				}else{
					temp[k++] = tweets[tr++];
				}
			}
			while(tl <= mid){
				temp[k++] = tweets[tl++];
			}
			while(tr <= right){
				temp[k++] = tweets[tr++];
			}
			// now we copy the sorted array into original array
			int j = 0;
			for(int i = left; i <= right; i++){
        		tweets[i] = temp[j++];
    		}
		}
	}
}

void mergeSort(std::vector<Tweet>& tweets, int left, int right, const std::string& sortBy, bool ascending) 
{
	if(left >= right)	return;
	int mid = left + (right-left)/2;
	mergeSort(tweets,left,mid,sortBy,ascending);
	mergeSort(tweets,mid+1,right,sortBy,ascending);
	merge(tweets,left,mid,right,sortBy,ascending);
}