#include <memory>
#include <string>
#include <fstream>
#include <iostream>

#include "gtest/gtest.h"
#include "filescomparator.h"

namespace fs = std::filesystem;


class FilesComparatorTests : public ::testing::Test
{
public:
    FilesComparatorTests()
    {
    }

protected:
    // Test interface
    void SetUp() override
    {
		fs::create_directory(dirPath1);
		fs::create_directory(dirPath2);

		filePath11 = createFile(dirPath1, "file11", "1");
		filePath12 = createFile(dirPath1, "file12", "2");
		filePath13 = createFile(dirPath1, "file13", "11");
		createFile(dirPath1, "file14", "1111");
		createFile(dirPath1, "file15", "1111");
		createFile(dirPath1, "file16", "2222");

		filePath21 = createFile(dirPath2, "file21", "1");
		createFile(dirPath2, "file22", "1");
		createFile(dirPath2, "file23", "111");
		createFile(dirPath2, "file24", "1111");
		createFile(dirPath2, "file25", "2222");
		createFile(dirPath2, "file26", "2222");
    }
    
	void TearDown() override
    {
		fs::remove_all(dirPath1);
		fs::remove_all(dirPath2);
    }

private:
    void TestBody() override
    {
    }

	fs::path createFile(fs::path directoryPath, const std::string &name, const std::string &content)
	{
		const auto filePath = directoryPath / name;

		std::ofstream out(filePath, std::ios::out);
		out << content;
		out.close();

		return filePath;
	}

protected:
	const fs::path dirPath1 = "dir1";
	const fs::path dirPath2 = "dir2";

	fs::path filePath11;
	fs::path filePath12;
	fs::path filePath13;
	fs::path filePath21;
};

TEST_F( FilesComparatorTests, filesComparisonBySizeTest )
{
	const auto isSizeEqual1 = FilesComparator::isFilesSizeEqual(filePath11, filePath21);
	ASSERT_TRUE(isSizeEqual1);

	const auto isSizeEqual2 = FilesComparator::isFilesSizeEqual(filePath13, filePath21);
	ASSERT_FALSE(isSizeEqual2);
}

TEST_F(FilesComparatorTests, filesComparisonByDataTest)
{
	const auto isDataEqual1 = FilesComparator::isFilesDataEqual(filePath11, filePath21);
	ASSERT_TRUE(isDataEqual1);

	const auto isDataEqual2 = FilesComparator::isFilesDataEqual(filePath12, filePath21);
	ASSERT_FALSE(isDataEqual2);
}

TEST_F(FilesComparatorTests, directorySimpleComparisonTest)
{
	const auto files = FilesComparator::getEqualFilesListSimple(dirPath1, dirPath2);
	ASSERT_EQ(files.size(), 6);
}

TEST_F(FilesComparatorTests, directoryComparisonTest)
{
	const auto files = FilesComparator::getEqualFilesList(dirPath1, dirPath2);
	ASSERT_EQ(files.size(), 6);
}
