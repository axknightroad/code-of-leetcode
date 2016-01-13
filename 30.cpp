#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
  vector<int> ans;
  vector<vector<string> > sWords;
  map<string, int> wordsMap;
  map<string, int> tempMap;
  int wordLength, wordsSize, sLength, sumWordLength;
  
  wordsSize = words.size();
  sLength = s.size();
  
  if(!wordsSize || !sLength) return ans;
  wordLength = words[0].size();
  sumWordLength = wordLength * wordsSize;
  
  if(sLength < sumWordLength) return ans;
  
  for(int i = 0; i < wordsSize; i++) {
    wordsMap[words[i]] += 1;
  }
  
  for(int i = 0; i < wordLength; i++) {
    vector<string> temp;
    for(int j = 0; j < (sLength - i) / wordLength; j++ ) {
      if(i+j*wordLength + wordLength <= s.size()) {
	temp.push_back(s.substr(i+j*wordLength, wordLength));
      }
    }
    sWords.push_back(temp);
  }
  
  for(int index = 0; index < sLength - sumWordLength + 1; index++) {
    tempMap.clear();
    bool isMatch = true;
    int turn = index / wordLength;
    int offset = index % wordLength;
    
    for(int i = 0; i < wordsSize; i++) {
      string temp = sWords[offset][turn + i];
      if(!wordsMap.count(temp)||tempMap[temp] >= wordsMap[temp]) {
	isMatch = false;
	break;
      } else {
	tempMap[temp] += 1;
      }
    }
    
    if (isMatch) {
      for(int i = 0; i < wordsSize; i++) {
	string tempWord = words[i];
	if(tempMap[tempWord] != wordsMap[tempWord]) {
	  isMatch = false;
	  break;
	}
      }
    }
    
    if (isMatch) ans.push_back(index);
  }
  
  return ans;
}


int main() {
  string s = "barfoothefoobarman";
  vector<string> words;
  words.push_back("foo");
  words.push_back("bar");

  vector<int> ans = findSubstring(s, words);

  for(int i = 0; i < ans.size(); i++)
    std::cout << ans[i] << std::endl;

  return 0;
}
