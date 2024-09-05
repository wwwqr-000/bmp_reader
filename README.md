<h1>BMP Image Reader</h1>

```cpp
#include <iostream>
#include <windows.h>
#include <gdiplus.h>
#include <vector>

using namespace Gdiplus;

#include "classes/texturemap.hpp"

//Linkers: -lgdi32 -lgdiplus

ULONG_PTR gdiplusToken;
std::vector<texturemap> textureMaps;

void addTexturemap(const wchar_t* path, std::string name) {
    texturemap tmpMap;
    tmpMap.setMap(new Bitmap(path));
    Rect box(0, 0, tmpMap.getMap()->GetWidth(), tmpMap.getMap()->GetHeight());
    tmpMap.getMap()->LockBits(&box, ImageLockModeRead, PixelFormat24bppRGB, &tmpMap.getMapData());
    tmpMap.setMapPixels(static_cast<BYTE*>(tmpMap.getMapData().Scan0));
    tmpMap.getName() = name;
    textureMaps.emplace_back(tmpMap);
}

void loadTexturemaps() {
    addTexturemap(L"pfp.bmp", "Profile Picture");
}

int main() {
    GdiplusStartupInput gdiplusStartupInput = {0};
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    loadTexturemaps();
    //Get rgb value from pixel on coord 10, 10
    int y = 10;
    int x = 10;
    int index = (y * textureMaps[0].getMapData().Stride + (x * 3));

    int red = static_cast<int>(textureMaps[0].getMapPixels()[index + 2]);
    int green = static_cast<int>(textureMaps[0].getMapPixels()[index + 1]);
    int blue = static_cast<int>(textureMaps[0].getMapPixels()[index]);

    std::cout << "RGB value from '" << textureMaps[0].getName() << "' on x: " << x << ", y: " << y << " is RGB(" << red << ", " << green << ", " << blue << ")\n";
    //

    GdiplusShutdown(gdiplusToken);
    return 0;
}

```

<h4>A simple yet practical bmp reader for c++</h4>

<h5>List of required includes</h5>

```cpp
#include <iostream>
#include <windows.h>
#include <gdiplus.h>
#include <vector>
```
