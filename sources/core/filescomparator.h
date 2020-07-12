#pragma once

#include <filesystem>

using namespace std;

class FilesComparatorTests;

class FilesComparator
{
	friend FilesComparatorTests;

public:
	static std::vector<std::pair<std::string, std::string>> getEqualFilesListSimple(const std::filesystem::path &directoryPath1, const std::filesystem::path &directoryPath2);
	static std::vector<std::pair<std::string, std::string>> getEqualFilesList(const std::filesystem::path &directoryPath1, const std::filesystem::path &directoryPath2);

	static bool isFilesSizeEqual(const std::filesystem::path &filePath1, const std::filesystem::path &filePath2);
	static bool isFileDataEqual(const std::filesystem::path &filePath1, const std::filesystem::path &filePath2);
};
