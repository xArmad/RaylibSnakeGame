#include <iostream>
#include <raylib.h>

using namespace std;

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

const int cellSize = 30;
const int cellCount = 25;

const int dimensions = cellSize * cellCount;

class Food {
public:
    Vector2 pos;
    Texture2D texture;

    Food()
    {
        Image image = LoadImage("Graphics/food.png");
        texture = LoadTextureFromImage(image);
        UnloadImage(image);
        pos = GenerateRandomPos();
    }

    ~Food()
    {
        UnloadTexture(texture);
    }

    Vector2 GenerateRandomPos()
    {
        int x = GetRandomValue(0, cellCount - 1);
        int y = GetRandomValue(0, cellCount - 1);

        return { static_cast<float>(x), static_cast<float>(y) };
    }

    void Draw()
    {
        DrawTexture(texture, static_cast<int>(pos.x * cellSize), static_cast<int>(pos.y * cellSize), WHITE);
    }
};

void UpdateGame(Food&);

int main()
{
    InitWindow(dimensions, dimensions, "Snake Game");
    SetTargetFPS(60);

    Food food;

    while (!WindowShouldClose())
    {
        UpdateGame(food);
    }

    CloseWindow();

    return 0;
}

void UpdateGame(Food& food)
{
    BeginDrawing();

    ClearBackground(green);

    food.Draw();
    DrawText("This is TEXT", 50, 50, 20, RED);

    EndDrawing();
}
