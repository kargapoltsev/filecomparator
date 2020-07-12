#pragma once

#include <list>
#include <map>
#include <filesystem>

// Класс представляет обработчик путей до файлов в рабочей диреткории. 
// Методы классы позволяют заполнить коллекцию на основе переданного пути
// в порядке возрастания размера файлов, сгруппировать файлы по содержимому.
class DirectoryHandler 
{
public:
	using Group = std::list<std::filesystem::path>;
	using Groups = std::list<Group>;
	using Collection = std::map<std::size_t, Groups>;

	// Обработка указанной директории
	void handleDirectory(const std::filesystem::path &directoryPath);

	auto begin() { return m_collection.begin(); }
	auto end() { return m_collection.end(); }
	
	// Поиск групп файлов по размеру
	auto find(std::size_t size) { return m_collection.find(size); }
	
	// Признак наличия групп файлов заданного размера
	bool has(std::size_t size);

private:
	// Формирование сруктуры коллекции путей файлов рабочей директории
	void fill();
	
	// Группировка путей до файлов по содержимому
	void group();

	// Путь до рабочей директории
	std::filesystem::path m_directoryPath;

	// Коллекция путей
	Collection m_collection;
};
