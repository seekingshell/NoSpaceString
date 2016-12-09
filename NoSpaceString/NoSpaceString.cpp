// NoSpaceString.cpp : Defines the entry point for the console application.
//

#include <map>

std::map<std::string, int> dictionary;

std::string traverseString(std::string::iterator it, std::string &initString)
{
	if (it == initString.end())
		return "";

	std::string temp;
	std::string word;
	std::string sentence;
	std::string::iterator savedIter;

	for (it; it != initString.end(); it++)
	{
		char tempChar = *it;
		temp.append(1, tempChar);
		if (dictionary.find(temp) != dictionary.end())
		{
			// we need to make sure this is the final word!
			word.assign(temp);
			savedIter = it + 1;
		}
	}

	sentence.append(word);
	
	if(savedIter != initString.end())
		sentence.append(" ");

	sentence.append(traverseString(savedIter, initString));

	return sentence;
}

int main()
{
	dictionary["pea"] = 1;
	dictionary["nut"] = 1;
	dictionary["peanut"] = 1;
	dictionary["but"] = 1;
	dictionary["butt"] = 1;
	dictionary["butter"] = 1;

	std::string initString = "peanutbutter";
	std::string sentence = traverseString(initString.begin(), initString);

	return 0;
}



