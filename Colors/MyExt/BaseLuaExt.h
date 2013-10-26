//
//  BaseLuaExt.h
//  Dragon
//
//  Created by GameDeveloper on 13-8-13.
//
//

#ifndef Dragon_BaseLuaExt_h
#define Dragon_BaseLuaExt_h
#include "CCLuaEngine.h"
NS_CC_BEGIN
struct PngSqliteData;
class BaseLuaExt{
public:
    static BaseLuaExt * create();
    bool init();
};

NS_CC_END
#endif
