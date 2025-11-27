#include <iostream>
#include <fstream>
#include <string>

bool 		read_content(const std::string &filename, std::string &content);
std::string	replace_str(std::string content, const std::string s1, const std::string s2);
bool 		write_content(const std::string &filename, const std::string &content);

int	main(int argc, char **argv)
{
	if (argc != 4 || !argv[1] || !argv[2] || !argv[3])
	{
		std::cerr << "Invalid argument(s): Execute as `./ex04 <filename> <str_to_find> <str_to_replace>`" << std::endl;
		return (1);
	}
	std::string	content;
	std::string	filename = argv[1];
	if (!read_content(filename, content))
		return (1);
	std::string	replaced = replace_str(content, replace_str(argv[2], "\\n", "\n"), replace_str(argv[3], "\\n", "\n"));
	std::string	newfile = filename + ".replace";
	if (!write_content(newfile, replaced))
		return (1);
	return (0);
}

bool read_content(const std::string &filename, std::string &content)
{
    std::ifstream ifs(filename.c_str());
    if (!ifs.is_open())
    {
        std::cerr << "Error: Cannot open file: " << filename << std::endl;
        return (false);
    }
    std::string tmp;
    std::string line;
    while (std::getline(ifs, line))
        tmp += line + '\n';
    if (!ifs.eof())
    {
        std::cerr << "Error: Cannot read content: " << filename << std::endl;
        return (false);
    }
    content = tmp;
    return (true);
}

std::string	replace_str(std::string content, const std::string s1, const std::string s2)
{
	std::string	tmp;
	size_t		pos;

	while (!content.empty() && (pos = content.find(s1, 0)) != std::string::npos)
	{
		tmp += content.substr(0, pos);
		tmp += s2;
		content = content.substr(pos + s1.length(), std::string::npos);
	}
	if (content != "\0")
		tmp += content;
	return (tmp);
}

bool write_content(const std::string &filename, const std::string &content)
{
    std::ofstream ofs(filename.c_str(), std::ios::out | std::ios::trunc);
    if (!ofs.is_open())
    {
        std::cerr << "Error: Cannot open writing file: " << filename << std::endl;
        return (false);
    }
    ofs << content;
    if (!ofs)
    {
        std::cerr << "Error: Cannot write: " << filename << std::endl;
        return (false);
    }
    return (true);
}
