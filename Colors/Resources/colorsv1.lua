require("game")
require("base64")
require("VisibleRect")
require("sync")
rect = VisibleRect:new()
local kinds={
    RECT=1,
    UP=2,
    DOWN=3,
    CIRCLE = 4,
    MAX_NUM = 1,
}
local colors={
    WHITE = 0,
    GREEN = 1,
    RED = 2,
    YELLOW = 3,
    GREY = 4,
    BLACK = 5,
    STATIC = 6,
    MAX_COLOR_NUM = 6,
}
local parseInt = function(x)
        if x <= 0 then
            return math.ceil(x);
        end

        if math.ceil(x) == x then
            x = math.ceil(x);
        else
            x = math.ceil(x) - 1;
        end
        return x;
end
math.randomseed(tostring(os.time()):reverse():sub(1, 6))
function drawShapeByColor(object,kind,color,width)
    if (width == nil) then width = 64 end
    object:clear()
    local shape = object:pushShape(DrawShapeExt:new())

    if (color == colors.WHITE) then
        shape:setColor(255,255,255,255)
    elseif (color == colors.RED) then
        shape:setColor(255,0,212,255)
    elseif (color == colors.YELLOW) then
        shape:setColor(0,255,0,255)
    elseif (color == colors.GREY) then
        shape:setColor(23,233,233,255)
    elseif (color == colors.GREEN) then
        shape:setColor(0,0,255,255)
    elseif (color == colors.BLACK) then
        shape:setColor(24,25,23,255)
    elseif (color == colors.STATIC) then
        shape:setColor(132,234,212,255)
    else
    
    end
    shape.shapeType = POLY
    if (kind == kinds.RECT) then
       shape:push(ccp(-width/2,-width/2)):push(ccp(width/2,-width/2)):push(ccp(width/2,width/2)):push(ccp(-width/2,width/2))
    elseif (kind == kinds.UP) then
        shape:push(ccp(-width/2,-width/2)):push(ccp(width/2,-width/2)):push(ccp(width/2,width/2))
    elseif (kind == kinds.DOWN) then
        shape:push(ccp(-width/2,width/2)):push(ccp(-width/2,-width/2)):push(ccp(width/2,-width/2))
    elseif (kind == kinds.CIRCLE) then
        shape:push(ccp(0,0)):push(ccp(width/2,0)):push(ccp(10,0)):push(ccp(1,1))
        shape.shapeType = CIRCLE
    end
end
-----Number 数字----
function Number(name,value)
    local number = Label:create("T("..name.." & Arial &20 & 123 & 233 & 233)N(0&fps_images.png& 12& 32& . & 255 & 0 & 0)",CCSizeMake(64,64))
    number:addTimer(1,100/value) -- 需要计数
    local nowValue = value;
    local numberTbl={
        setValue = function(value)
            nowValue = value
            local lv = number:getNumber(0)
            if (lv == nowValue) then lv = nowValue - 1 end
            number:addTimer(1,200/math.abs(nowValue - lv))
        end,
        setPosition = function(x,y)
            number:setPosition(ccp(x,y))
        end,
        getValue = function()
            return nowValue
        end
    }
    window:addUI(number)
    number.timeout = function()
        local nn = number:getNumber(0)
        if (nn - nowValue < 3) then
            number:addTimer(1,200)
        end
        if (nn < nowValue) then
            number:setNumber(0,nn + 1)
        end
        if (nn > nowValue) then
            number:setNumber(0,nn-1)
        end
    end
    return numberTbl;
end

---- Shape 定义------
function Shape(kind,color,downcount)
    local image = Image:create()
    image:retain()
    drawShapeByColor(image,kind,color)
    image:addTimer(1,100)
    image:addTimer(2,1500)
    image:addTimer(3,1000) -- 需要下降计数
    if (downcount == nil) then
        downcount =  parseInt(math.random() * 10 + 1)
    end
    local number = Label:create("N(0&fps_images.png& 12& 32& . & 255 & 0 & 0)",CCSizeMake(64,64))
    image:addChild(number)
    if (color == colors.BLACK) then
        number:setVisible(false)
    end
    local shape = {
        width = 1,
        height = 1,
        kind = kind,
        color = color,
        image = image,
        down = downcount,
        x = function()
            return image:getPositionX()
        end,
        y =function()
            return image:getPositionY()
        end,
        setPosition = function(x,y)
            image:setPosition(ccp(x,y))
        end,
        setColor = function(r)
            drawShapeByColor(image,kind,r)
        end
    }
    number:setNumber(0,shape.down)
    
    image.timeout = function(timeid)
       if (timeid == 1 and shape and shape.down <= 0) then
            local x = image:getPositionX()
            local y = image:getPositionY() - 64
            if (shape.map == nil or shape.color == colors.BLACK) then return end
       
            if (shape.map.checkblockbyxy(x,y) == false and y >= 0 and y <= 64 * shape.map.cellheightsize) then
                shape.map.clearblock(shape)
                image:setPosition(ccp(x,y))
                shape.map.setblock(shape)
            end
       elseif (timeid == 2 and shape ~= nil) then
           -- shape.map.clearblock(shape)
           -- shape.map.removeShape(shape)
           -- table.insert(shape.map.dirtyShapes,shape.image)
           -- shape = nil
            image:addTimer(2,-1) --  删除定时器
       elseif (timeid == 3 and shape ~= nil) then
            shape.down = shape.down - 1
            if (shape.down <= 0) then
                image:addTimer(3,-1)
                number:setVisible(false)
            end
            if (shape.color == colors.BLACK) then
                number:setVisible(false)
            end
            number:setNumber(0,shape.down)
       end
    end
    return shape
end

function showGameOver()
    local show = Label:create("T(GameOver & 黑体 &24 & 0 & 0 & 0)",CCSizeMake(184,64))
    show:setPosition(ccp(160,240))

    local array = CCArray:create()
    array:addObject(CCScaleTo:create(1.5,2))
    array:addObject(CCFadeOut:create(1.5))
    array:addObject(CCRotateBy:create(1.5, 360))
    local action2 = CCSpawn:create(array)
    array:addObject(action2)
    --array:addObject(CCCallFuncN:create(CallFucnCallback3))
    local action3 = CCSequence:create(array)
    game.addChild(show)
    show:runAction(action3)
end
----end-----------

local function CallFucnCallback3(sender)
    if ( sender == nil) then return end
	game.removeChild(sender,true)
end

function showScore(score,x,y)
    local showLbl =  Label:create("N("..score.."&fps_images.png& 12& 32& . & 255 & 0 & 0)",CCSizeMake(64,64))
    local array2 = CCArray:create()
    array2:addObject(CCScaleTo:create(0.5,8))
    array2:addObject(CCMoveTo:create(0.5, ccp(140,240)))
    local action1 = CCSpawn:create(array2) -- move to center
    array2 = CCArray:create()
    array2:addObject(CCMoveTo:create(0.5, ccp(140,400)))
    array2:addObject(CCFadeOut:create(0.5))
    array2:addObject(CCScaleTo:create(0.5,0.5))
    local action2 = CCSpawn:create(array2)
    array2 = CCArray:create()
    array2:addObject(action1)
    array2:addObject(action2)
    array2:addObject(CCCallFuncN:create(CallFucnCallback3))
    local action3 = CCSequence:create(array2)
    showLbl:runAction(action3)
    game.addChild(showLbl)
    showLbl:setPosition(ccp(x,y))
end

function addScore(score)
    local value = nowScoreLbl.getValue()
    --print("add score" .. score .. "value" .. value)
    nowScoreLbl.setValue( score  + value);
    value = nowScoreLbl.getValue()
    local level = nowLevelLbl.getValue()
    local nowExp = needScoreLbl.getValue() 
    if (nowExp ==0 ) then  nowExp = 25 end
    if (value >= nowExp) then
        nowLevelLbl.setValue(level + 1)
        needScoreLbl.setValue(nowExp + level * level)
    else
        needScoreLbl.setValue(nowExp)
    end
end


--Map的定义
function Map()
    local cellwidth = 64
    local cellheight = 64
    local cellheightsize = 10 --parseInt((rect:getVisibleRect().size.height - 86)/64)
    local cellwidthsize = 10 --parseInt(rect:getVisibleRect().size.width/64)
    local height = cellheight * cellheightsize
    local width = cellwidth * cellwidthsize
    local bits = {
            tag=BitMap:new_local(),
            red=BitMap:new_local(),
            green=BitMap:new_local(),
        }
    local image = Image:create()
    --image:retain()
    local startPoint = ccp(0,0)
    local endPoint = ccp(1,1)
    local xImage = Image:create()
    local yImage = Image:create()
    image:addChild(xImage,10)
    image:addChild(yImage,10)
    image.drawSelf = function()
        -- 绘制bitset
        -- 绘制当前的touch
        return 1
    end
    local shape = image:pushShape(DrawShapeExt:new())
         shape.shapeType = POLY
         shape:push(ccp(0,0)):push(ccp(width,0)):push(ccp(width,height)):push(ccp(0,height))
         :setColor(25,100,25,35)
    local shape = image:pushShape(DrawShapeExt:new())
         shape.shapeType = POLY
         shape:push(ccp(0,height)):push(ccp(width,height)):push(ccp(width,height+184)):push(ccp(0,height+184))
         :setColor(125,235,125,255)
        
    local nowShape = nil
    local parseLocation = function(x,y)
        return parseInt(x / cellwidth) * cellwidth, parseInt(y/cellheight) * cellheight
    end

    image.touchdown = function(x,y)
        -- 点击开始
        startPoint = ccp(x,y)
        startPoint = image:convertToNodeSpace(startPoint)
        if (startPoint.y >= 0 and startPoint.y <= 64 * cellheightsize) then
            xImage:setVisible(true)
            yImage:setVisible(true)
            nowShape = Shape(button.kind,button.color) --Shape(kinds.RECT,colors.GREY)
            nowShape.image:retain()
            local x,y = parseLocation(0,startPoint.y)
            xImage:setPosition(ccp(x,y))
            local x,y = parseLocation(startPoint.x,0)
            yImage:setPosition(ccp(x,y))
        end
    end
    local calcId2 = function(x,y)
        return parseInt(x / cellwidth),parseInt(y / cellheight)
    end
    local calcIdby2 = function(x,y)
        if ( x >= cellwidthsize or x < 0 or y >= cellheightsize or y < 0) then return -1 end
        return x * cellheightsize +y
    end
    local calcId = function (x,y,log)
        if (log == 1) then
        --print("calc x:"..parseInt(x / cellwidth) .. "y:" .. parseInt(y / cellheight))
        end
        return parseInt(x / cellwidth) * cellheightsize + parseInt(y / cellheight)
    end
    image.checkin = function(x,y)
        return true
    end
    image.touchmove = function(x,y)
         -- 判断是否移动 或者绘制 
         image.drawrect = true
         endPoint = ccp(x,y)
         endPoint = image:convertToNodeSpace(endPoint)
         if (endPoint.y >= 0 and endPoint.y <= 64 * cellheightsize) then
            xImage:clear();
            local shape = xImage:pushShape(DrawShapeExt:new())
            shape.shapeType = POLY
            shape:push(ccp(0,0)):push(ccp(width,0)):push(ccp(width,64)):push(ccp(0,64))
            :setColor(25,0,25,125)
            local x,y = parseLocation(0,endPoint.y)
            xImage:setPosition(ccp(x,y))
         
            yImage:clear();
            local shape = yImage:pushShape(DrawShapeExt:new())
            shape.shapeType = POLY
            shape:push(ccp(0,0)):push(ccp(64,0)):push(ccp(64,height)):push(ccp(0,height))
            :setColor(25,0,25,125)
            local x,y = parseLocation(endPoint.x,0)
            yImage:setPosition(ccp(x,y))
         end
    end
    local allshapes = {}
    local map = {
        setblock = function(shape)
            local index = calcId(shape.x(),shape.y(),1)
            bits.tag:set(index)
            allshapes[index] = shape
        end,
        clearblock = function(shape)
            if (shape ~= nil) then
                local index = calcId(shape.x(),shape.y())
                bits.tag:reset(index)
                --table.remove(allshapes,index)
                allshapes[index] = nil
            end
        end,
        checkblock = function(shape)
            local index = calcId(shape.x(),shape.y())
            return bits.tag:test(index)
        end,
        checkblockbyxy = function(x,y)
            local index = calcId(x,y)
            return bits.tag:test(index)
        end,
        cellheightsize = cellheightsize,
        removeShape = function(shape)
            if(shape.image == nil) then return end
            image:removeChild(shape.image,true)
            local x = CCSprite:create("Icon.png")
            game.addChild(x)
            local p1,p2 = shape.image:getPosition()
            x:setPosition(ccp(p1,p2))
            local array2 = CCArray:create()
            array2:addObject(CCRotateBy:create(0.2, 360))
            array2:addObject(CCFadeOut:create(0.8))
            array2:addObject(CCCallFuncN:create(CallFucnCallback3))
            local action3 = CCSequence:create(array2)
            x:runAction(action3)
            shape.image = nil

            end,
        dirtyShapes={}
    }
    local function eraseAllShapes1()
        local alleraseshapes={}
        local index = 0
        local allshapecount = 0
        local sx = 0
        local sy = 0
        table.foreach(allshapes,function(i,shape)
            if ( shape ~= nil) then
            allshapecount = allshapecount + 1
            local x = shape.x()
            local y = shape.y()
            local t = {
                {1,0},
                {0,1},
                {-1,0},
                {0,-1}
            }
            local tag = false
            local x,y = calcId2(shape.x(),shape.y())
            local circle_count = 0
            local circles = {}
            table.foreach(t,function(i,v)
                local pos = {}
                local id = calcIdby2(x+v[1],y+v[2])
                if (id ~= -1 ) then
                local dshape = allshapes[id]
                if (dshape ~= nil and dshape.color == shape.color and shape.color ~= colors.BLACK) then
                    tag = true
                elseif (dshape ~= nil and dshape.color == colors.BLACK and shape.color ~= colors.WHITE and shape.hadcircle ~= true and dshape.hadcircle ~= true) then
                    tag = false
                    shape.setColor(colors.BLACK)
                    shape.color = colors.BLACK
                    circle_count = circle_count + 1
                    table.insert(circles,dshape)
                    sx,sy = shape.image:getPosition()
                end
                end
            end)
            if(circle_count >= 2) then
                -- 将该色块变圆 表示不再扩展
				table.insert(circles,shape)
                table.foreach(circles,function(i,v)
                    v.hadcircle = true
                    drawShapeByColor(v.image,kinds.CIRCLE,colors.WHITE)
                end)
                addScore(4 * circle_count)
                showScore(4 * circle_count,sx,sy)
            end
            if (tag == true) then
                index = index + 1
                table.insert(alleraseshapes,shape)
            end
            else
            end
        end)
        if (table.getn(alleraseshapes) > 1) then
            --print("need erase count" .. table.getn(alleraseshapes))
        end
        local count = 0
        table.foreach(alleraseshapes,function(i,shape)
                --print(shape.image)
                map.clearblock(shape)
                sx,sy = shape.image:getPosition()
                map.removeShape(shape)
                count = count + 1
        end)
        if (count >= 2) then
            addScore(count *count)
            showScore(count * count,sx,sy)
        end
        if (allshapecount == (cellheightsize * cellwidthsize)) then
            if (image.over == nil) then
                image:addTimer(5,3000)
                image.over = true
                print("game over")
                showGameOver()
            end
        end
        --print(table.getn(allshapes))
    end
    image:addTimer(1,300)
    image.timeout = function(timerid)
       if (timerid == 1) then
            -- 检查image上是否是相同的相邻 若相邻 则 小时格子
            table.foreach(map.dirtyShapes, function(i, v)
                v:release()
            end)
            map.dirtyShapes = {}
            eraseAllShapes1()
       else
            image:addTimer(5,0)
            main()
       end
    end

    image.touchend = function(x,y)
        endPoint = ccp(x,y)
        endPoint = image:convertToNodeSpace(endPoint)
        if (endPoint.y >= 0 and endPoint.y <= 64 * cellheightsize) then
        if (nowShape and map.checkblockbyxy(endPoint.x,endPoint.y) == false) then
            image:addChild(nowShape.image)
            nowShape.image:release()
            local x,y = parseLocation(endPoint.x,endPoint.y)
            nowShape.setPosition(x+32,y+32)
            map.setblock(nowShape)
            nowShape.map = map
            nowShape = nil
            button.color = parseInt(math.random() * colors.MAX_COLOR_NUM)
            button.kind = parseInt(math.random() * kinds.MAX_NUM + 1)
            drawShapeByColor(button,button.kind,button.color,62)
        end
       end
       xImage:setVisible(false)
       yImage:setVisible(false)

    end
    return image
end
--Map结束定义--
function __G__TRACKBACK__(msg)
    print("----------------------------------------")
    print("LUA ERROR: " .. tostring(msg) .. "\n")
    print(debug.traceback())
    print("----------------------------------------")
end

function doLuaUICallback(i,o,x,y)
    if ( i == HANDLE_DRAW and o.drawSelf) then
        o.drawSelf()
        return 1
    end
    if (i == HANDLE_CLICK and o.click) then
        o.click()
        return 1
    end
    if (i == HANDLE_TOUCHIN and o.checkin) then
        return o.checkin(x,y)
    end
    if ( i == HANDLE_DOWN and o.touchdown) then
        o.touchdown(x,y)
        return 1
    end
    if ( i == HANDLE_MOVE and o.touchmove) then
        o.touchmove(x,y)
        return 1
    end
    if ( i == HANDLE_END and o.touchend) then
        o.touchend(x,y)
        return 1
    end
    return 0
end
function doLuaTimerCallback(timer,timerid)
    if (timer.timeout) then
        timer.timeout(timerid)
    end
end
local function doTouchFunction(event,x,y)
    if (event == "began") then
       -- print("began")
    elseif (event == "moved") then
       -- print("moved")
    elseif (event == "ended") then
       -- print("ended")
    end
    return true
end
function gamescene()
    game.start()
	rect = VisibleRect:new()
	window = Window:create()
	
	local image = Map()
	image:setPosition(ccp(0,2))
	window:addUI(image)
	game.addChild(window)

	game.ontouch(doTouchFunction)

	button = Button:create()
	window:addUI(button)

	button:setPosition(160,420)
	button.color = 3
	button.kind = parseInt(math.random() * kinds.MAX_NUM) + 1
	drawShapeByColor(button,button.kind,button.color,62)

	button.touchdown=function()
	drawShapeByColor(button,button.kind,1,62)
	end


	button.click = function()
	end
	button.touchend=function()
	drawShapeByColor(button,button.kind,button.color)
	end

	nowScoreLbl = Number("Score",0)
    nowScoreLbl.setPosition(1,430)

	needScoreLbl = Number("HighScore",0)
    needScoreLbl.setPosition(1,400)

    nowLevelLbl = Number("Level",0)
    nowLevelLbl.setPosition(192,385)
    nowLevelLbl.setValue(1)
    addScore(0)
	local endButton = Button:create()
	window:addUI(endButton)
	endButton.touchdown=function()
		
	end
	endButton.click = function()
		main()
	end
	endButton.touchend=function()

	end
    endButton:setPosition(ccp(289,rect:top().y - 45))
    local shape = endButton:pushShape(DrawShapeExt:new()):setColor(255,0,212,255)
    :push(ccp(-24,-24)):push(ccp(24,-24)):push(ccp(24,24)):push(ccp(-24,24))
    shape.shapeType=POLY
    shape = endButton:pushShape(DrawShapeExt:new()):setColor(0,0,212,255)
    shape:push(ccp(-11,-11)):push(ccp(11,-11)):push(ccp(11,11)):push(ccp(-11,11)).shapeType = POLY
end
function main()
    startScene = game.start()
	
	window = Window:create()
    game.addChild(window)
	--创建 2 个按钮 分别表示开始和结束
	local startButton = Button:create()
    startButton:setPosition(160,240)

    startButton:pushShape(DrawShapeExt:new())
:setColor(255,0,212,255):push(ccp(-48,-48)):push(ccp(48,-48)):push(ccp(48,48)):push(ccp(-48,48)).shapeType = POLY
    local shape = startButton:pushShape(DrawShapeExt:new()):setColor(0,0,212,255)
    shape:push(ccp(0,0)):push(ccp(45,0)):push(ccp(10,0)):push(ccp(1,1)).shapeType = CIRCLE

    window:addUI(startButton)
	startButton.touchdown=function()
		
	end
    startButton.click = function()
		-- 返回到开始开始场景
		gamescene()

	end
    --sync.init()
    --sync.send(2,"helo,world")
    print("start")
end
xpcall(main, __G__TRACKBACK__)
