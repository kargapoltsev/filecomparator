#include "cui.h"

#include <iostream>

using namespace std;
namespace fs = filesystem;


std::pair<std::filesystem::path, std::filesystem::path> CUI::getPaths()
{
	const auto directoryPath1 = getDirectoryPath("Enter first directory path");
	const auto directoryPath2 = getDirectoryPath("Enter second directory path");

	return { directoryPath1, directoryPath2 };
}

void CUI::displayFiles(const std::vector<std::pair<std::string, std::string>>& files)
{
	if (files.empty())
	{
		cout << "Directories haven't equals files" << endl;
		return;
	}

	cout << "Equals files in directories are:\n";

	for (const auto &[filename1, filename2] : files)
		std::cout << filename1 << " and " << filename2 << "\n";
}

std::filesystem::path CUI::getDirectoryPath(const std::string &message)
{
	cout << message << ": ";
	string strDirectoryPath;
	cin >> strDirectoryPath;

	fs::path directoryPath(strDirectoryPath);
	if (!fs::exists(directoryPath))
		throw runtime_error("Incorrect directry path");

	return directoryPath;
}
