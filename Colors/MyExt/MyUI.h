#pragma once
#include "cocos2d.h"
#include "tolua++.h"
#include "BaseLuaExt.h"
USING_NS_CC;
/**
 ***/
enum SHAPE{
    CIRCLE = 0,
    LINE = 1,
    SHAPE_RECT = 2,
    POLY = 3,
};

class DrawShapeExt{
public:
    DrawShapeExt(){}
    DrawShapeExt* push(const CCPoint &point);
    void drawPloy(bool tag,const ccColor4F &color);
    static void drawSolidCircle(const CCPoint& center, float radius, float angle, unsigned int segments, bool drawLineToCenter, float scaleX, float scaleY);
    DrawShapeExt* setColor(float r,float g,float b,float alpha);
    ccColor4F color;
    DrawShapeExt* setLineWidth(float width);
    DrawShapeExt * setShapeType(int shapeType);
    std::vector<CCPoint> points;
    int shapeType;
    void show();
    void clear();
    bool checkIn(const CCPoint &point);
};
namespace myui{
	enum TouchEvent{
		TOUCH_DOWN = 1,
		TOUCH_MOVE = 2,
		TOUCH_END = 3,
	}; // 
	enum AlignType{
		ALIGN_LEFT = 1 << 0,
		ALIGN_RIGHT = 1 << 1,
		ALIGN_UP = 1 << 2,
		ALIGN_BOTTOM = 1 << 3,
		ALIGN_CENTER = 1 << 4,
	}; // 
	enum FitType{
		FIT_SELF = 0, // 
		FIT_GRID = 1, // 
	};
    enum LuaExtEvent{
        HANDLE_DOWN = 0,
        HANDLE_MOVE = 1,
        HANDLE_END = 2,
        HANDLE_DRAW = 3, //
        HANDLE_CLICK = 4,
        HANDLE_TOUCHIN = 5,
    };
	class Panel;
    class Base;
    /**

     */
    class TouchHandle:public CCObject{
    public:
        virtual void handleDown(Base *base){};
        virtual void handleMove(Base *base){};
        virtual void handleEnd(Base *base){};
        virtual void handleClick(Base *base){};
    };
    class Timer{
    public:
        int timeid;
        int timeout;
        cc_timeval nowTime;
        Timer()
        {
            timeid = 0;
            timeout = 0;
            CCTime::gettimeofdayCocos2d(&nowTime, NULL);
        }
    };

	class Base:public CCNode{
	public:
		Base()
		{
			touch = NULL;
			isActive = false;
            moveAble = false;
			panel = NULL;
            parent=NULL;
            touchHandle = NULL;
		}
		virtual bool checkIn(CCTouch *touch)
		{
			return false;
		}
        TouchHandle *touchHandle;
        void bindTouchHandle(TouchHandle *touchHandle);
        void setMoveable(bool moveableTag){moveAble = moveableTag;}
		/**
         */
		virtual bool attachTouch(TouchEvent event,CCTouch *touch);
		virtual bool doTouch(TouchEvent event,CCTouch *touch)
		{
			return false;
		}
        void hide();
        void show();
		CCTouch *touch; // 
		CCPoint nowTouchPoint; // 
		bool isActive; // 
        bool moveAble; // 
		Panel *panel;
        CCNode *parent;
        std::map<int,Timer> timers;
        typedef std::map<int,Timer>::iterator TIMERS_ITER;
        void addTimer(int timeid,int timeout);
        /**
		 * ????�?
		 */
		void setLocation(AlignType alignType,const CCSize &splitSize,const CCPoint &gridLocation);
        
		/**
		 * ?????????????
		 */
		void setInView(const CCSize &size){}
        template<typename UICLASS>
        int doLuaEvent(LuaExtEvent event, UICLASS* ui,const char *type)
        {
            lua_getglobal(CCLuaEngine::defaultEngine()->getLuaState(), "doLuaUICallback");
            if (!lua_isfunction(CCLuaEngine::defaultEngine()->getLuaState(), -1))
            {
                CCLOG("[LUA ERROR] name '%s' does not represent a Lua function", "doLuaUICallback");
                lua_pop(CCLuaEngine::defaultEngine()->getLuaState(), 1);
                return 0;
            }
            CCLuaEngine::defaultEngine()->pushInt(event);
            tolua_pushusertype(CCLuaEngine::defaultEngine()->getLuaState(), ui, type);
            //int ret = CCLuaEngine::defaultEngine()->getLuaStack()->executeFunction(2);
			lua_pcall(CCLuaEngine::defaultEngine()->getLuaState(),2,0,0);
         //   CCLuaEngine::defaultEngine()->getLuaStack()->clean();
            return 0;
        }
        template<typename UICLASS>
        int doLuaEventTouchIn(LuaExtEvent event, UICLASS* ui,const char *type,const CCPoint &point)
        {
            lua_getglobal(CCLuaEngine::defaultEngine()->getLuaState(), "doLuaUICallback");
            if (!lua_isfunction(CCLuaEngine::defaultEngine()->getLuaState(), -1))
            {
                CCLOG("[LUA ERROR] name '%s' does not represent a Lua function", "doLuaUICallback");
                lua_pop(CCLuaEngine::defaultEngine()->getLuaState(), 1);
                return 0;
            }
            CCLuaEngine::defaultEngine()->pushInt(event);
            tolua_pushusertype(CCLuaEngine::defaultEngine()->getLuaState(), ui, type);
            CCLuaEngine::defaultEngine()->pushInt(point.x);
            CCLuaEngine::defaultEngine()->pushInt(point.y);
           // int ret = CCLuaEngine::defaultEngine()->getLuaStack()->executeFunction(4);
            lua_pcall(CCLuaEngine::defaultEngine()->getLuaState(),4,0,0);
			//CCLuaEngine::defaultEngine()->getLuaStack()->clean();
            return 0;
        }
        template < typename UICLASS>
        void doLuaTimerCallback(UICLASS *ui,const char* type,int timeid)
        {
            lua_getglobal(CCLuaEngine::defaultEngine()->getLuaState(), "doLuaTimerCallback");
            if (!lua_isfunction(CCLuaEngine::defaultEngine()->getLuaState(), -1))
            {
                CCLOG("[LUA ERROR] name '%s' does not represent a Lua function", "doLuaUICallback");
                lua_pop(CCLuaEngine::defaultEngine()->getLuaState(), 1);
                return;
            }
            tolua_pushusertype(CCLuaEngine::defaultEngine()->getLuaState(), ui, type);
            CCLuaEngine::defaultEngine()->pushInt(timeid);
           // CCLuaEngine::defaultEngine()->getLuaStack()->executeFunction(2);
			lua_pcall(CCLuaEngine::defaultEngine()->getLuaState(),2,0,0);
            //CCLuaEngine::defaultEngine()->getLuaStack()->clean();
        }
    };
	/**
	 */
	class Image:public Base{
	public:
		static Image *create(const char *pngName = NULL);
		/**
		 */
		bool checkIn(CCTouch *touch);
		/**

         */
		virtual bool checkIn(const CCPoint &point);
		std::string pngName; // png
		std::string outlinePngName; // png
		/**
         */
		void setOutLine(const char *pngName);
		/**
         */
		bool doTouch(TouchEvent event,CCTouch *touch);
       
        /**
         */
		CCSprite *sprite;
        
		void show(CCNode *node)
		{
			if (sprite)
				node->addChild(sprite);
		}
        void draw();
		/**
         */
		void replacePng(const char *name);
		bool checkIn(const CCPoint point,CCSprite *sprite,const char *fileName);
		bool checkInRect(const CCPoint point,CCSprite *sprite);
		bool createImage(const char *fileName,CCImage* &image);
        ~Image()
        {
            if (image) delete image;
            image = NULL;
        }
		Image()
		{
			sprite = NULL;
			image = NULL;
            resizeable = false;
		}
        CCImage* image;
        
        void runAction(CCAction *action);
        
        CCSize getViewSize();
        CCSize imageSize;
        bool resizeable;
        void setsize(const CCSize &size);
		void setInView(const CCSize &size);
        void setResizeable(bool tag);
        //ccColor4F color;
        std::list<DrawShapeExt*> shapes;
        typedef std::list<DrawShapeExt*>::iterator SHAPES_ITER;
        void clear();
        void showShapes();
        DrawShapeExt * pushShape(DrawShapeExt *shape);
        DrawShapeExt * getShape(int index);
    };
	/**
	 * ???
	 **/
	class Button:public Image{
	public:
		/**
		 * ???????
		 */
		static Button * create(const char *upName = NULL,const char *downName= NULL);
		/**
         * ???touch??
         * ???????????????
         */
		bool doTouch(TouchEvent event,CCTouch *touch);
        
		std::string upName;
		std::string downName;
        
        bool up;
        Button()
        {
            up = true;
        }
        void draw();
        
        /**
         * ?????????????
         */
		virtual bool checkIn(const CCPoint &point);
	};
    /**
     * ?????
     */
    class Choice:public Image{
    public:
        /**
		 * ?????
		 */
		static Choice * create(const char *upName = NULL,const char *downName = NULL);
		/**
         * ???touch??
         * ???????????????
         */
		bool doTouch(TouchEvent event,CCTouch *touch);
        
		std::string upName;
		std::string downName;
        
        bool choiceAble;
        /**
         * ?????????????
         */
		virtual bool checkIn(const CCPoint &point);

        virtual void draw();
        
    };
    /**
     * ????
     */
    class Bubble:public Choice{
    public:
        /**
		 * ???????
		 */
		static Bubble * create(const char *upName,const char *downName);
		/**
         * ???touch??
         * ???????????????
         */
		bool doTouch(TouchEvent event,CCTouch *touch);
        
		std::string upName;
		std::string downName;
        
        Bubble()
        {
            
        }
        /**
         * ?????????????
         */
		virtual bool checkIn(const CCPoint &point);

        void draw();
        void popUp();
    };
	/**
	 * ???
	 */
	class Slider:public Image{
	public:
		/**
		 * ?????
		 */
		static Slider * create(const char *upName,const char *downName);
        
		/**
		 * ????????
		 */
		bool init(const char *upName,const char *downName);
        
		/**
         * ?????????Touch
         */
        bool checkIn(CCTouch *touch);
        /**
         * ????touch??
         * ???????????????
         */
        bool doTouch(TouchEvent event,CCTouch *touch);
		/**
		 * ?????
		 */
		CCSprite *backSprite;
        /**
		 *  ???
		 */
		CCSprite *sliderSprite;
		/**
		 * ????
		 */
		float getValue();
		/**
		 * ??????????
		 */
		void setValue(float value);
        
		/**
		 * ???
		 */
		float value;
        
		Slider()
		{
			value = 0;
			backSprite = sliderSprite = NULL;
		}
        
		float getMaxValue();
	};
	/**
	 * ?????????????
	 * ????????????????????
	 **/
	class Label:public Base{
	public:
		static Label * create(const char *content,const CCSize& size);
		/**
		 * ????????????????????
		 */
		bool init(const char* content,const CCSize &size);
        /**
         * ???????????
         */
        static const char* getArgs(const char * content,int argc,std::vector<std::string> &args);
        
        /**
         * ?????????Touch
         */
        bool checkIn(CCTouch *touch);
        /**
         * ????touch??
         * ???????????????
         */
        bool doTouch(TouchEvent event,CCTouch *touch);
        
        CCRect rect;
        
        void setNumber(int tag,double value);
        double getNumber(int tag);
        std::vector<CCLabelAtlas*> numbers;
        
        void draw();
    };
    /**
     * ???
     */
    class HPLabel:public Base{
    public:
        static HPLabel *create(const char *backName = NULL,const char *showName = NULL);
        bool init(const char *backName,const char *showName);
        void setValue(float value);
        CCSize viewSize; // ???????
        int maxValue;
        int value;
        CCSprite *backSprite;
        CCSprite *valueSprite;
        HPLabel()
        {
            backSprite = valueSprite = NULL;
            maxValue = 0;
            value = 0;
        }
        
        void draw();
    };
    /**
     * ????�?
     **/
    class Tree:public Base{
    public:
        Tree()
        {
            parent = next = child = NULL;
            image = NULL;
            isOpen = true;
        }
        /**
         * ???????
         */
        static Tree * create(Image *image);
        /**
         * ????
         */
        void addTree(Tree *tree);
        /**
         * ???????
         */
        void show();
        void visit();
        Tree *parent; // ??
        Tree *next; // ???????
        Tree *child; // ????
        Image *image; // ????
        bool isOpen; // ???????
        CCPoint show(Tree *tree,const CCPoint &point);
        /**
         * ?????????Touch
         */
        bool checkIn(CCTouch *touch);
        /**
         * ????touch??
         * ???????????????
         */
        bool doTouch(TouchEvent event,CCTouch *touch);
        /**
         * ?? ?????????????
         */
        bool checkInTree(CCTouch *touch,Tree *tree);
        /**
         * ??�?????? ??????????
         */
        bool touchInTree(TouchEvent event,CCTouch *touch,Tree *tree);
        /**
         * ?????????????
         */
        void hideCloseNode(Tree *node);
    };
    /**
     * ??�
     */
    class List:public Base{
    public:
        List()
        {
            image = NULL;
            nowTouchImage = NULL;
            exchageAble = true;
        }
        /**
         * ????ҧ
         */
        static List *create(Image *image,const CCSize &cellSize = CCSizeMake(0,0));
        /**
         * ?????ҧ
         */
        void remove(List *list);
        /**
         * ?????ҧ
         */
        void add(Image *list);
        /**
         * ????ҧ
         */
        void show();
        std::list<Image*> content;
        Image *image; // ???
        CCSize cellSize; // ?????ҧ�
        
        /**
         * ?????????Touch
         */
        bool checkIn(CCTouch *touch);
        /**
         * ????touch??
         * ???????????????
         */
        bool doTouch(TouchEvent event,CCTouch *touch);
        /**
         * ?????????Table??�????
         */
        int pickImageIndex(CCTouch *touch);
        
        /**
         * ???????????
         */
        Image *pickImage(const int &index);
        
        Image *nowTouchImage;
        
        bool exchageAble;
        
    };
    /**
     * ??
     */
    class Table:public Base{
    public:
        Table()
        {
            exchageAble = true;
            nowTouchImage = NULL;
        }
        static Table *create(const CCSize & tableSize,const CCSize &cellSize);
        bool exchageAble; //?????????? ?????????????????
        std::vector<Image *> images;
        /**
         * ????????
         */
        void add(const CCPoint &point,Image *image);
        /**
         * ??????????????
         */
        void push(Image *image);
        /**
         * ?????????
         */
        void remove(Image *image);
        /**
         * ?????????Touch
         */
        bool checkIn(CCTouch *touch);
        /**
         * ????touch??
         * ???????????????
         */
        bool doTouch(TouchEvent event,CCTouch *touch);
        /**
         * ?????????Table??֧????
         */
        CCPoint pickImageIndex(CCTouch *touch);
        
        /**
         * ???????????
         */
        Image *pickImage(const CCPoint &point);
        
        /**
         * ?????
         */
        void show();
        
        CCSize tableSize;
        CCSize cellSize;
        
        Image *nowTouchImage;
        void visit();
        void doExchange(Image *src,Image *dest);
        
        void removeIndex(Image *src);
        
        void draw();

    };
    /**
     * ????֨�???? ??
     **/
    class ScrollView:public Base{
    public:
        static ScrollView * create(float width,float height);
        bool init(float width,float height);
        /**
         * ???????
         */
        void add(Image *base);
        /**
         * ????
         */
        void visit();
        int width; // ????
        int height; // ?????
        ScrollView()
        {
            width = height = 0;
            child = NULL;
            scrollType = ALL;
        }
        CCSize eachTap;
        enum SCROLL_TYPE{
            UP_DOWN = 0,
            LEFT_RIGHT = 1,
            ALL = 2,
        };
        SCROLL_TYPE scrollType;
        void setEachTap(const CCSize eachTap){this->eachTap = eachTap;}
        void setScrollType(SCROLL_TYPE scrollType){this->scrollType = scrollType;}
        Image *child;
        /**
         * ?????????Touch
         */
        bool checkIn(CCTouch *touch);
        /**
         * ????touch??
         * ???????????????
         */
        bool doTouch(TouchEvent event,CCTouch *touch);
        
        void draw();
    };
	/**
	 * ??? ????�?????? ???CCNode ??
	 * 1.?????????????? ?????????????
	 * 2.?????????????
	 * 3.?????
	 *	 1.?¦????? ??????????
	 *		?????: ?????????????????????? ? ????????????̦?
	 * 4.?Panel ????˧? ??????????????
	 **/
	class Panel:public Image{
	public:
        static Panel *create();
		std::list<Base*> uis;  // ????????ߧ ?Base ??????? ??????
		std::list<Base*> actives; // ????ui??ҧ
		std::list<Base*> firsts; // ?????????ҧ ???????
		typedef std::list<Base*>::iterator BASES_ITER;
		/**
         * ????touch??
         * ??Base ???actives
         */
		bool attachTouch(TouchEvent event,CCTouch *touch);
		/**
		 * ?????????
		 */
		void addUI(Base *base);
        
        void removeUI(Base *base);
		/**
		 * ????
		 */
		void visit();
		/**
		 * ?????????Ҧ?
		 */
		void setLocation(AlignType alignType,const CCSize &splitSize,const CCPoint &gridLocation);
		/**
		 * ??????˧�
		 */
		void setSize(const CCSize &size);
		CCRect rect; // ????????????
		CCSize getSize(); // ?????��
		/**
		 * ??????????????�?
		 */
		CCPoint getPoint(AlignType alignType,const CCSize &splitSize,const CCPoint &gridLocation);
        
        /**
         * ˨�????????????
         */
		virtual bool checkIn(const CCPoint &point);
        
        void draw();
	};
	/**
	 * ???
	 */
	class Window:public CCLayer{
	public:
		static Window*create();
		bool init();
		void ccTouchesBegan(cocos2d::CCSet *pTouches, cocos2d::CCEvent *pEvent);
		void ccTouchesMoved(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent);
		void ccTouchesEnded(cocos2d::CCSet *pTouch, cocos2d::CCEvent *pEvent);
		std::list<Base*> uis;
		typedef std::list<Base*>::iterator UIS_ITER;
		std::list<Base*> actives;  
		std::list<Base*> firsts;  
		/**
		 * 增加界面元素
		 */
		void addUI(Base *base);
        
        void removeUI(Base *base);
        /**
         * 渲染
         */
		void visit();
		/**
		 * 获取窗口大小
		 */
		static CCSize getWindowSize();
		/**
		 * 获取点的信息
		 * \param clignType 对齐方式
		 * \spliteSize 划分格局
		 * \location 格子编号
		 */
		static CCPoint getPoint(AlignType alignType,const CCSize &splitSize,const CCPoint &gridLocation);
	};
}