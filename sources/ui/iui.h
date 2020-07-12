#pragma once

#include <filesystem>
#include <utility>

class IUI
{
public:
	virtual ~IUI() {}

	// Получение путей рабочих директорий для сравнения файлов
	virtual std::pair<std::filesystem::path, std::filesystem::path> getPaths() = 0;

	// Отображение эквивалентных файлов
	virtual void displayFiles(const std::vector<std::pair<std::string, std::string>> &files) = 0;
};
