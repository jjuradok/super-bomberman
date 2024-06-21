#include <vector>

class Level {
  const int rows;
  const int columns;
  std::string fileName;
  std::vector<std::vector<int>> matrix(rows, std::vector<int>(columns));
  public:
  Level(std::string filename);
  int getRows();
  int getColumns();
};