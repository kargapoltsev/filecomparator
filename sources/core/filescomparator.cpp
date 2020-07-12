#include "filescomparator.h"
#include <fstream>
#include <map>
#include <list>

namespace fs = std::filesystem;
using namespace std;

std::vector<std::pair<std::string, std::string>> FilesComparator::getEqualFilesListSimple(const std::filesystem::path & directoryPath1, const std::filesystem::path & directoryPath2)
{
	std::vector<std::pair<std::string, std::string>> result;

	for (auto& file1 : fs::directory_iterator(directoryPath1))
	{
		const auto filePath1 = file1.path();

		for (auto& file2 : fs::directory_iterator(directoryPath2))
		{
			const auto filePath2 = file2.path();

			if (isFilesSizeEqual(filePath1, filePath2) && isFileDataEqual(filePath1, filePath2))
				result.emplace_back(filePath1.filename().u8string(), filePath2.filename().u8string());
		}
	}
	
	return result;
}

std::vector<std::pair<std::string, std::string>> FilesComparator::getEqualFilesList(const std::filesystem::path & directoryPath1, const std::filesystem::path & directoryPath2)
{
	// 1. Sorting files in directory by size
	std::map<std::size_t, std::vector<fs::path>> directoryGroups1;
	
	for (auto& file : fs::directory_iterator(directoryPath1))
		directoryGroups1[file.file_size()].push_back(file.path());

	std::map<std::size_t, std::vector<fs::path>> directoryGroups2;
	for (auto& file : fs::directory_iterator(directoryPath2))
		directoryGroups2[file.file_size()].push_back(file.path());

	// 2. Splitting files by groups with equal contents

	//auto it1 = directoryGroups1.begin();
	//auto end1 = directoryGroups1.end();
	//auto it2 = directoryGroups2.begin();
	//auto end2 = directoryGroups2.end();

	//for (; it1 != end1 && it2 != end2; )
	//{
	//	const auto&[size1, path1] = *it1;
	//	const auto&[size2, path2] = *it2;
	//}

	//for (const auto&[size1, files1] : directoryGroups1)
	//{
	//	const auto it2 = directoryGroups2.find(size1);
	//	if (it2 != directoryGroups2.end())
	//	{
	//		const auto&[size2, files2] = *it2;

	//		if (isFileDataEqual(path1, path2))
	//			result.emplace_back(filePath1.filename().u8string(), filePath2.filename().u8string());
	//	}
	//}

	return std::vector<std::pair<std::string, std::string>>();
}


bool FilesComparator::isFilesSizeEqual(const filesystem::path &filePath1, const filesystem::path &filePath2)
{
    return fs::file_size(filePath1) == fs::file_size(filePath2);
}

bool FilesComparator::isFileDataEqual(const filesystem::path &filePath1, const filesystem::path &filePath2)
{
    std::ifstream file1(filePath1);
    std::ifstream file2(filePath2);

    if (file1.fail() || file2.fail()) return false;

    std::istreambuf_iterator<char> begin1(file1);
    std::istreambuf_iterator<char> begin2(file2);

    std::istreambuf_iterator<char> end;

    while(begin1 != end && begin2 != end)
    {
        if(*begin1 != *begin2) return false;
        ++begin1;
        ++begin2;
    }

    return (begin1 == end) && (begin2 == end);
}
