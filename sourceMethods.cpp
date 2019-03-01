// dirNameLister.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include "sourceMethods.h"
#include <filesystem>
#include <vector>

using namespace std;

namespace fs = std::filesystem;

void printDir(string path)
{
	for (const auto & entry : fs::directory_iterator(path))
		cout << entry.path() << endl;
}

vector<vector<string>> generateSource(string path, bool onlyName)
{
	vector<string> retn;
	for (const auto entry : fs::directory_iterator(path))
		if(!onlyName)
			retn.push_back(entry.path().filename().string());
		else {
			retn.push_back(absolute(entry.path()).string());
		}
	vector<vector<string>> result;
	result.push_back(retn);
	return result;
}