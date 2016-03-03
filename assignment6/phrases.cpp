#include <sstream>     	// std::istringstream
#include <fstream>
#include <map>		// std::multimap
#include <algorithm>   	// std::copy, std::for_each

#include "mr.hpp"
#include "ioutils.hpp"
#include "phrases.hpp"


namespace mr {
// Map and reduce methods to count occurrences of a word in a given text.

// A specialized map function with string keys and int values
void
Phrases::MRmap(const std::map<std::string,std::string> &input,
				std::multimap<std::string,int> &out_values) {
	IOUtils io;
	// input: in a real Map Reduce application the input will also be a map
	// where the key is a file name or URL, and the value is the document's contents.
	// Here we just take the string input and process it.
	for (auto it = input.begin(); it != input.end(); it++ ) {
		std::string inputString = io.readFromFile(it->first);
        
        std::stringstream ss(inputString);
        std::string sentence;
        //split line
        while(std::getline(ss, sentence, '\n')){
            // Split line up the input into words
            std::istringstream iss(sentence);
            //make array for every line
            std::vector<std::string> words;
            do {
                std::string word;
                iss >> word;
                for(int i = 0; i < word.length(); i++){
                    if(ispunct(word[i]) && word[i] != '\''){
                        word.erase(i, i);
                    }
                }
                words.push_back(word);
                } while (iss);
                // Each word-group gets assigned a count of 1
            for(int i = 0; i < (words.size() - 1); i++){
                out_values.insert(std::pair<std::string,int>(words[i] + ' ' + words[i+1],1));
            }
        }
	}
}

// A specialized reduce function with string keys and int values
void
Phrases::MRreduce(const std::multimap<std::string,int> &intermediate_values,
					std::map<std::string,int> &out_values) {

	// Sum up the counts for all intermediate_values with the same key
	// The result is the out_values map with each unique word as
	// the key and a total count of occurrences of that word as the value.
	std::for_each(intermediate_values.begin(), intermediate_values.end(),
			// Anonymous function that increments the sum for each unique key (word)
			[&](std::pair<std::string,int> mapElement)->void
			{
				out_values[mapElement.first] += 1;
			});  // end of for_each
}

}; // namespace mr
