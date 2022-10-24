
#include<iostream>
#include<fcntl.h>
#include<unistd.h>
#include <iostream>
#include <fstream>
#include <cstdlib>

 void	exit_error(char const *error_message)
{
	std::cerr << "Error: " << error_message << std::endl;
	exit (EXIT_FAILURE);
}

void	is_empty(std::ifstream &infile)
{
	std::string		line;

	std::getline(infile, line);
	if (infile.eof())
	{
		infile.close();
		exit_error("file empty");
	}
	infile.close();
}

void	check_errors(int ac, char **av)
{
	std::ifstream	infile;
	std::string		file;

	if (ac != 4)
		exit_error("bad arguments");
	infile.open(av[1]);
	if (infile.fail())
		exit_error("failed to open file");
	is_empty(infile);
	file = av[1];
	if (file.empty())
	{
		infile.close();
		exit_error("s1 is empty");
	}
	infile.close();
}

static void	search_file(std::ifstream &infile, std::string replace, std::string s1, std::string s2)
{
	std::string		line;
	std::ofstream	outfile;
	std::size_t		pos;
	std::size_t		i;

	outfile.open(replace.c_str());
	if (outfile.fail())
		exit_error("failed to open file");
	while (!infile.eof())
	{
		std::getline(infile, line);
		if (line.find(s1) != std::string::npos)
			{
				i = 0;
				while((pos = line.find(s1, i)) != std::string::npos)
				{
					line.erase(pos, s1.length());
					line.insert(pos, s2);
					i = pos + s2.length();
				}
			}
		if (!infile.eof())
			outfile << line << std::endl;
	}
	outfile.close();
}
int	main(int ac, char **av)
{
	std::ifstream	infile;
	std::string		replace;

	check_errors(ac, av);
	infile.open(av[1]);
	if (infile.fail())
		exit_error("failed to open file");
	replace = (std::string)av[1] + ".replace";
	search_file(infile, replace, av[2], av[3]);
	infile.close();
	return (0);
}