#ifndef ARTLIBRARY_H
#define ARTLIBRARY_H
#include <string>

namespace ArtLibrary
{
    class Cutscenes
    {
    public:
        static std::string Introduction();
        static std::string Victory();
        static std::string GameOver();
        static std::string NextLevel();
        static std::string TryAgain();
        static std::string LevelBegin(int Difficult, int CodeSum, int Product);
    };

    class Numbers
    {
    public:
        static std::string NumberGenerator(int Number);
    private:
        static std::string Zero();
        static std::string One();
        static std::string Two();
        static std::string Three();
        static std::string Four();
        static std::string Five();
        static std::string Six();
        static std::string Seven();
        static std::string Eight();
        static std::string Nine();
    };
} // namespace ArtLibrary
#endif