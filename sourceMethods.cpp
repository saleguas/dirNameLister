// dirNameLister.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include "sourceMethods.h"
#include <filesystem>
#include <vector>
#include <fstream>

using namespace std;

namespace fs = std::filesystem;

void printDir(string path)
{
	for (const auto & entry : fs::directory_iterator(path))
		cout << entry.path() << endl;
}

vector<string> generateSource(string path, bool onlyName)
{
	vector<string> retn;
	retn.push_back("");
	for (const auto entry : fs::directory_iterator(path))
		if(!onlyName)
			retn.push_back(entry.path().filename().string());
		else {
			retn.push_back(absolute(entry.path()).string());
		}
	return retn;
}
void createTXT(vector<string> source, string name)
{
	ofstream outfile(name + ".txt");
	for (auto it : source)
	{
		outfile << it << endl;
	}
	outfile.close();
}