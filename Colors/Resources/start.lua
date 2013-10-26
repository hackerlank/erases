require("base64")
require("sync")
require("game")
require("box2d")
require("json")
function __G__TRACKBACK__(msg)
    print("----------------------------------------")
    print("LUA ERROR: " .. tostring(msg) .. "\n")
    print(debug.traceback())
    print("----------------------------------------")
end
function doLuaTimerCallback(timer,timerid)
    timer.timeout(timeid)
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
local function main()
game.start()
window = Window:create()
function testClose()
    local button = Button:create();
    button.drawSelf = function()
        --glLineWidth(16)
    
        if (button.up == true) then
            ccDrawColor4B(0, 255, 0, 255)
            ccDrawCircle(ccp(0,0), 100, 0, 10, false)
        else
            ccDrawColor4B(0, 0, 255, 255)
            ccDrawCircle(ccp(0,0), 100, 0, 10, false)
        end
    end
    local count = 0
    button:setsize(CCSizeMake(200,200));
    button.click = function()
       -- window:removeUI(button)
        count = count+1
        print("click " .. count)
        return 0
    end
    window:addUI(button)
end
testClose()
drawrect = Image:create()
drawrect:addTimer(1,1000)
drawrect.timeout = function(timerid)
    --print(".")
end
--drawrect:setPosition(ccp(300,300))
drawrect.touchdown = function(x,y)
    --print("touch begin")
    drawrect.drawit = true
    drawrect.startpoint = ccp(x,y)
     drawrect.endpoint = ccp(x,y)
end
drawrect.touchmove = function(x,y)
    drawrect.endpoint = ccp(x,y)
end

drawrect.touchend = function(x,y)
    --print("touch end")
    drawrect.drawit = false
    -- 创建一个rect 放入世界
    local image = Image:create()
    window:addUI(image)
    local x,y = drawrect:getPosition()
    image.startPoint = ccpSub(drawrect.startpoint,ccp(x,y))
    image.endPoint = ccpSub(drawrect.endpoint,ccp(x,y))
    image.drawSelf=function()
        point = ccpSub(image.endPoint,image.startPoint)
        ccDrawRect(ccp(0,0),ccp(1,1))
       -- print(",")
    end
    image:setPosition(ccp(image.startPoint.x,image.startPoint.y))
    -- 创建
    local width = math.abs(image.endPoint.x - image.startPoint.x)/2
    local height = math.abs(image.endPoint.y - image.startPoint.y)/2
    if (width > 10 and height > 10) then
    local shape = b2PolygonShape:new_local()
    shape:SetAsBox(width/32,height/32)
    local body = box2d.addbody(image,shape)
    end
end

drawrect.drawSelf = function()
ccDrawColor4B(0, 0, 255, 255)
--ccDrawCircle(ccp(0,0), 100, 0, 10, false)

if (drawrect.drawit) then
    local x,y = drawrect:getPosition()
    ccDrawRect(ccpSub(drawrect.startpoint,ccp(x,y)),ccpSub(drawrect.endpoint,ccp(x,y)))
end
if (box2d.world) then
    box2d.world:DrawDebugData()
end
end
window:addUI(drawrect)
drawrect.checkin = function()
    return 1
end

panel = Panel:create()
if (panel ~= nil) then
    panel:setsize(CCSizeMake(300,300))
    --panel:replacePng("panel_back.png");
    --panel:addUI(button)
    panel:setLocation(ALIGN_CENTER,CCSizeMake(3,3),CCPoint(1,1))
    panel:setMoveable(true)
end
game.addChild(window)
box2d.start()

local s = CCDirector:sharedDirector():getWinSize()
box2d.groudbox(s.width,s.height)

sprite = CCSprite:create("Icon.png")
print("get sprite".."")
game.addChild(sprite)
local s = CCDirector:sharedDirector():getWinSize()
sprite:setPosition(ccp(10, 10)) -- 随机一点
local body = box2d.addbody(sprite)
vel = body:GetLinearVelocity();
m = body:GetMass();-- the mass of the body
local velChange = b2Vec2(0,0)
local impluse = b2Vec2(0,0)
local desiredVel = b2Vec2(50,0);-- the vector speed you set
velChange.x = desiredVel.x - vel.x
velChange.y = desiredVel.y - vel.y
impluse.x = m * velChange.x --impluse = mv
impluse.y = m * velChange.y
body:ApplyLinearImpulse( impluse, body:GetWorldCenter() );

game.ontouch(doTouchFunction)
end
xpcall(main, __G__TRACKBACK__)
