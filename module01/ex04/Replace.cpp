#include "Replace.hpp"
#include "File.hpp"

int	check_params(int argc, char* argv[])
{
	if (argc < 4)
	{
		std::cerr << "Too few arguments (exactly 3 arguments required)." << std::endl;
		return (1);
	}
	else if (argc > 4)
	{
		std::cerr << "Too many arguments (exactly 3 arguments required)." << std::endl;
		return (1);
	}
	if (std::string(argv[1]).length() == 0)
	{
		std::cerr << "Error: invalid filename: \"\"" << std::endl;
		return (1);
	}
	if (std::string(argv[2]).length() == 0)
	{
		std::cerr << "Error: invalid argument (cannot replace empty string): \"\"" << std::endl;
		return (1);
	}
	return (0);
}

int	read_file(File& file, std::string str1, std::string str2)
{
	std::string	line;
	size_t		new_pos;
	size_t		old_pos;
	size_t		len_str1;

	std::ifstream	infile(file.getInFilename().c_str());

	if (infile.is_open() == 0)
	{
		std::cerr << "Error: ifstream(): failed to open file: " << file.getInFilename() << std::endl;
		return (1);
	}

	std::ofstream	outfile(file.getOutFilename().c_str());

	if (outfile.is_open() == 0)
	{
		infile.close();
		std::cerr << "Error: ifstream(): failed to open file: " << file.getOutFilename() << std::endl;
		return (1);
	}
	while (std::getline(infile, line))
		file.setContent(file.getContent().append(line.append("\n")));
	len_str1 = str1.length();
	old_pos = 0;
	new_pos = file.getContent().find(str1);
	while (new_pos != std::string::npos)
	{
		if (new_pos - old_pos > 0)
			outfile << file.getContent().substr(old_pos, new_pos - old_pos);
		outfile << str2;
		old_pos = new_pos + len_str1;
		new_pos = file.getContent().find(str1, new_pos + len_str1);
	}
	outfile << file.getContent().substr(old_pos, new_pos);
	infile.close();
	outfile.close();
	return (0);
}

int	replace(int argc, char *argv[])
{
	if (check_params(argc, argv) != 0)
		return (1);

	File	file((std::string(argv[1])));

	if (read_file(file, std::string(argv[2]), std::string(argv[3])) == 1)
		return (1);
	return (0);
}
