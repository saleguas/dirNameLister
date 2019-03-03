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
#include <algorithm>

using namespace std;

namespace fs = std::filesystem;

vector<string> extensions;

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
	{
		extensions.push_back(entry.path().extension().string());
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
	}
	return retn;
}

void addExt(vector<string> &source, string path)
{
	cout << extensions.size() << " " << source.size() << endl;
	int counter = 0;
	for (int i = 0; i < source.size(); i++)
	{
		source.at(i) += ("	");
		if (i != 0)
			source.at(i) += extensions.at(i - 1);
	}

}

void replaceAll(string& str, const string& from, const string& to) {
	if (from.empty())
		return;
	size_t start_pos = 0;
	while ((start_pos = str.find(from, start_pos)) != string::npos) {
		str.replace(start_pos, from.length(), to);
		start_pos += to.length(); 
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

void createCSV(vector<string> source, string name)
{
	ofstream outfile(name + ".csv");
	for (auto it : source)
	{
		replaceAll(it , "	", ",");
		outfile << it << endl;

	}
	outfile.close();
}