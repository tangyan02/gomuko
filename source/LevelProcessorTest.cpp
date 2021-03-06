#include "GameMap.h"
#include "mapDriver.h"
#include "struct/Color.cpp"
#include "LevelProcessor.h"
#include "logger.h"
#include "Analyzer.h"

using namespace std;

int main()
{
    enum Color **map = readMap();
    GameMap gameMap = GameMap(map);
    printMapToConsole(map);

    LevelProcessor levelProcessor;
    Score score;
    score.initScore(map, WHITE);
    Analyzer data;
    
    data.reset(&gameMap, WHITE, gameMap.getNeighbor(WHITE), &score);
    printAnalyzePoints(data);
    vector<struct Point> points = *levelProcessor.getExpandPoints(&data);
    printf("%ld\n", points.size());
    for (int i = 0; i < points.size(); i++)
    {
        printf("%d %d\n", points[i].x, points[i].y);
    }
    return 0;
}