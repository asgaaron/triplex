#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ArtLibrary.h"
using namespace std;

void Pause()
{
    cout << "Press any key to continue...";
    std::cin.get();
}

int RandomCode(int Difficulty)
{
    if (Difficulty >= 8)
    {
        return rand() % Difficulty + 1;
    }
    else
    {
        return rand() % Difficulty;
    }
}

bool PlayGame(int Difficulty)
{
    int GuessA, GuessB, GuessC, GuessSum, GuessProduct;

    const int FirstCode = RandomCode(Difficulty), SecondCode = RandomCode(Difficulty), ThirdCode = RandomCode(Difficulty);
    const int CodeSum = FirstCode + SecondCode + ThirdCode;
    const int CodeProduct = FirstCode * SecondCode * ThirdCode;

    cout << "codes: " << FirstCode << " " << SecondCode << " " << ThirdCode;
    cout << "sum: " << CodeSum << " product: " << CodeProduct;

    cout << ArtLibrary::Cutscenes::LevelBegin(Difficulty, CodeSum, CodeProduct);

    cin >> GuessA;
    cin >> GuessB;
    cin >> GuessC;

    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        return true;
    }
    else
    {
        cout << ArtLibrary::Cutscenes::TryAgain();
        Pause();
        return false;
    }
}

int main()
{
    srand(time(NULL));
    cout << ArtLibrary::Cutscenes::Introduction();
    Pause();

    int Difficulty = 5, MaxDifficulty = 10, Lives = 3;
    while (Difficulty <= MaxDifficulty)
    {
        if (PlayGame(Difficulty))
        {
            // Win level
            Difficulty++;

            if (Difficulty > MaxDifficulty)
            {
                // Win game
                cout << ArtLibrary::Cutscenes::Victory();
                Pause();
                return 0;
            }
        }
        else
        {
            // Lose
            --Lives;
            if (Lives == 0)
            {
                cout << ArtLibrary::Cutscenes::GameOver();
                Pause();
                return 0;
            }
        }
        std::cin.clear();
        std::cin.ignore();
    }
}