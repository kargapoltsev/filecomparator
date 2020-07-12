#include "pathscollection.h"

#include <cassert>
#include "filescomparator.h"

using namespace std;
namespace fs = filesystem;


void PathsHandler::handleDirectory(const std::filesystem::path &directoryPath)
{
	assert(fs::exists(directoryPath));
	m_directoryPath = directoryPath;

	fill();
	group();
}

bool PathsHandler::has(std::size_t size)
{
	return find(size) != end();
}

void PathsHandler::fill()
{
	for (const auto &file : fs::directory_iterator(m_directoryPath))
	{
		auto &groups = m_collection[file.file_size()];

		if (groups.empty())
			groups.push_back(std::list<fs::path>());

		m_collection[file.file_size()].front().push_back(file.path());
	}
}

void PathsHandler::group()
{
	if (m_collection.empty())
		return;

	for (auto &[size, groups] : m_collection)
	{
		auto &commonGroup = groups.front();

		if (commonGroup.size() == 1)
			continue;

		auto it = commonGroup.begin();
		while (it != commonGroup.end())
		{
			std::list<fs::path> newGroup;

			auto it2 = std::next(it, 1);
			while (it2 != commonGroup.end())
			{
				if (FilesComparator::isFilesDataEqual(*it, *it2))
				{
					newGroup.push_back(std::move(*it2));
					commonGroup.erase(it2++);
				}
				else
					++it2;
			}

			newGroup.push_back(std::move(*it));
			commonGroup.erase(it++);

			groups.push_back(newGroup);
		}
	}
}
