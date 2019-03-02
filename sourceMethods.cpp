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

vector<string> generateSource(string path, bool onlyName, bool keepExt)
{
	vector<string> retn;
	retn.push_back("");
	for (const auto entry : fs::directory_iterator(path))
		if (!onlyName)
		{
			string currentPath = entry.path().filename().string();
			if (!keepExt)
				retn.push_back(currentPath);
			else
			{
				size_t lastindex = currentPath.find_last_of(".");
				retn.push_back(currentPath.substr(0, lastindex));
			}
		}
		else {
			retn.push_back(absolute(entry.path()).string());
		}
	return retn;
}

void addExt(vector<string> &source, string path)
{
	for (const auto entry : fs::directory_iterator(path))
	{

	}
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