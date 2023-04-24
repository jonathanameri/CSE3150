#include <vector>
#include <map>
#include <set>

class LargeImageDoc {
public:
    LargeImageDoc(const std::map<int, std::string>& listImageInfo)
        : numTicks(0), listImageInfo(listImageInfo)
    {
        for (auto it = listImageInfo.begin(); it != listImageInfo.end(); ++it) {
            LoadImage(it->first, it->second);
        }
    }

    void Show(int page)
    {
        if (listImageInfo.find(page) != listImageInfo.end() && listPagesShown.find(page) == listPagesShown.end()) {
            LoadImage(page, listImageInfo[page]);
            listPagesShown.insert(page);
        }
    }

private:
    void LoadImage(int page, const std::string& fileNameImage)
    {
        // do some work to load image data...
        // for example:
        std::vector<uint8_t> imageData = LoadImageData(fileNameImage);

        // update the number of ticks
        numTicks += imageData.size();
    }

    int numTicks;
    const std::map<int, std::string>& listImageInfo;
    std::set<int> listPagesShown;
};
