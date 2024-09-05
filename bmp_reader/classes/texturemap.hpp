#pragma once

class texturemap {
    private:
        Bitmap* map_;
        BitmapData mapData;
        BYTE* mapPixels;
        std::string name;
        int mapTexStep;

    public:
        texturemap() {}
        texturemap(Bitmap* map_, BitmapData& mapData, BYTE* mapPixels, int mapTexStep, std::string name) : map_(map_), mapData(mapData), mapPixels(mapPixels), mapTexStep(mapTexStep), name(name) {}

        Bitmap* getMap() { return this->map_; }
        void setMap(Bitmap* map_) { this->map_ = map_; }
        BitmapData& getMapData() { return this->mapData; }
        BYTE* getMapPixels() { return this->mapPixels; }
        void setMapPixels(BYTE* mapPixels) { this->mapPixels = mapPixels; }
        std::string& getName() { return this->name; }
};
