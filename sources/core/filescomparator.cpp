#include "filescomparator.h"
#include <fstream>
#include <map>
#include <list>
#include "directoryhandler.h"

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

			if (isFilesSizeEqual(filePath1, filePath2) && isFilesDataEqual(filePath1, filePath2))
				result.emplace_back(filePath1.filename().u8string(), filePath2.filename().u8string());
		}
	}
	
	return result;
}

std::vector<std::pair<std::string, std::string>> FilesComparator::getEqualFilesList(
	const fs::path & directoryPath1, const fs::path & directoryPath2)
{
	std::vector<std::pair<std::string, std::string>> result;

	DirectoryHandler dh1;
	dh1.handleDirectory(directoryPath1);

	DirectoryHandler dh2;
	dh2.handleDirectory(directoryPath2);

	for (const auto&[size1, groups1] : dh1)
	{
		const auto it2 = dh2.find(size1);

		if (it2 != dh2.end())
		{
			const auto&[size2, groups2] = *it2;

			for (auto &group1 : groups1)
			{
				if (group1.empty())
					continue;

				for (auto &group2 : groups2)
				{
					if (group2.empty())
						continue;

					if (isFilesDataEqual(group1.front(), group2.front()))
					{
						for (const auto &path1 : group1)
						{
							for (const auto &path2 : group2)
							{
								result.emplace_back(path1.filename().u8string(), path2.filename().u8string());
							}
						}
					}
				}
			}
		}
	}

	return result;
}


bool FilesComparator::isFilesSizeEqual(const filesystem::path &filePath1, const filesystem::path &filePath2)
{
    return fs::file_size(filePath1) == fs::file_size(filePath2);
}

bool FilesComparator::isFilesDataEqual(const filesystem::path &filePath1, const filesystem::path &filePath2)
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


