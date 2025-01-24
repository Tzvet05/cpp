#ifndef __FILE_H__
#define __FILE_H__

#include <string>
#include <fstream>

class	File
{
	public:
		File(std::string filename);
		~File(void);

		void	setInFilename(std::string inFilename);
		void	setOutFilename(std::string outFilename);
		void	setContent(std::string content);

		std::string	getInFilename(void);
		std::string	getOutFilename(void);
		std::string	getContent(void);
	private:
		std::string	_inFilename;
		std::string	_outFilename;
		std::string	_content;
};

#endif
