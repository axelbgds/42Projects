/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:19:17 by abeaugra          #+#    #+#             */
/*   Updated: 2023/11/14 12:30:40 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

void newfile(std::ifstream& infile, std::ofstream& outfile, const std::string& s1, const std::string& s2)
{
    std::string line;
    while (std::getline(infile, line)) {
        size_t start_pos = 0, pos;
        while ((pos = line.find(s1, start_pos)) != std::string::npos) {
            outfile << line.substr(start_pos, pos - start_pos) << s2;
            start_pos = pos + s1.length();
        }
        if (start_pos < line.length())
            outfile << line.substr(start_pos, line.length() - start_pos);
        outfile << std::endl;
    }
}

int main(int ac, char **av) {
    if (ac != 4) {
        std::cerr << "Error: usage is " << av[0] << " \"filename\" \"s1\" \"s2\" " << std::endl;
        return 1;
    }

    std::string filename = av[1], s1 = av[2], s2 = av[3], line;
    if (filename.empty() or s1.empty()) {
        std::cerr << "Error: filename and/or s1 should not be empty" << std::endl;
        return 1;
    }

    std::ifstream infile(filename.c_str());
    if (infile.fail()) {
        std::cerr << "Error: input file opening failed" << std::endl;
        return 1;
    }

    std::ofstream outfile((filename + ".replace").c_str());
    if (outfile.fail()) {
        std::cerr << "Error: output file writing failed" << std::endl;
        return 1;
    }

    newfile(infile, outfile, s1, s2);
    std::cout << "Create new file = " << filename + ".replace" << " with replace s1 by s2" << std::endl;
    
    return 0;
}