//
//  Drawable2D.h
//  QMediaCore
//
//  Created by spring on 20/05/2019.
//  Copyright © 2017 QMedia. All rights reserved.
//

#ifndef GRAPHICCORE_DRAWABLETEXTURE_H
#define GRAPHICCORE_DRAWABLETEXTURE_H

#include "GLMacros.h"

GRAPHICCORE_BEGIN

class Drawable2D {
public:
    
    enum Mode {
        NONE,
        FlipH,
        FlipV
    };
    
    static float RECTANGLE_COORDS[8];
    static float RECTANGLE_TEX_COORDS[8];
    static float RECTANGLE_TEX_COORDS_FLIPH[8];
    static float RECTANGLE_TEX_COORDS_FLIPV[8];

    static float MtxFlipH[16];
    static float MtxFlipV[16];
//protected:
//    Mode _mode;

};

GRAPHICCORE_END

#endif //GRAPHICCORE_DRAWABLETEXTURE_H
