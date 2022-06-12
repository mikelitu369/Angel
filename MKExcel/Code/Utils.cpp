

#include <Utils.hpp>


namespace MKExcel
{
    std::vector<std::string> Utils::Split(std::string string, const char* splitter)
    {
        std::vector<std::string> first;

        char* aa = NULL;
        char* point = strtok_s(&string[0], splitter, &aa);

        while (point != nullptr)
        {
            first.push_back(point);
            point = strtok_s(nullptr, splitter, &aa);
        }

        return first;
    }
}

