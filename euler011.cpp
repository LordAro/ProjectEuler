#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
	std::ifstream grid_file("assets/p011_grid.txt");
	std::vector<std::vector<int>> grid;

	std::string row_str;
	while (std::getline(grid_file, row_str)) {
		std::stringstream tmp(row_str);
		std::vector<int> row;
		int num;
		while (tmp >> num) row.push_back(num);
		grid.push_back(row);
	}

	long largeproduct = 0;

	/* Horizontal */
	for (int i = 0; i < (int)grid.size(); i++) {
		for (int j = 0; j < (int)grid[i].size() - 4; j++) {
			long num = grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];
			largeproduct = std::max(largeproduct, num);
		}
	}

	/* Vertical */
	for (int i = 0; i < (int)grid.size() - 4; i++) {
		for (int j = 0; j < (int)grid[i].size(); j++) {
			long num = grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j];
			largeproduct = std::max(largeproduct, num);
		}
	}

	/* Diagonal "\" */
	for (int i = 0; i < (int)grid.size() - 4; i++) {
		for (int j = 0; j < (int)grid[i].size() - 4; j++) {
			long num = grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];
			largeproduct = std::max(largeproduct, num);
		}
	}

	/* Diagonal "/" */
	for (int i = 0; i < (int)grid.size() - 4; i++) {
		for (int j = 3; j < (int)grid[i].size(); j++) {
			long num = grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 2] * grid[i + 3][j - 3];
			largeproduct = std::max(largeproduct, num);
		}
	}
	std::cout << "Largest product: " << largeproduct << std::endl;
}
