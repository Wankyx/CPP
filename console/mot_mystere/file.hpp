#ifndef FILE_HPP 
#define FILE_HPP

 
extern void displayFileContent(std::ifstream& fileStream);
extern std::size_t getFileLineTotal(std::ifstream& fileStream); 
extern std::string getFileLine(std::ifstream& fileStream, const std::size_t line);

extern std::string generateWord(std::string fileName);
extern std::string reverseWord(const std::string& word);

 
 

#endif // FILE_HPP