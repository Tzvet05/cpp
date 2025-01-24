#include "File.hpp"

File::File(std::string filename)
{
	_inFilename = filename;
	_outFilename = filename + ".replace";
}

File::~File(void)
{
}

std::string	File::getInFilename(void)
{
	return (_inFilename);
}

std::string	File::getOutFilename(void)
{
	return (_outFilename);
}

std::string	File::getContent(void)
{
	return (_content);
}

void	File::setInFilename(std::string inFilename)
{
	_inFilename = inFilename;
}

void	File::setOutFilename(std::string outFilename)
{
	_outFilename = outFilename;
}

void	File::setContent(std::string content)
{
	_content = content;
}
