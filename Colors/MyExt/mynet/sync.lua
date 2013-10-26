require("base64")
require("json")
function doLuaNetCallback(o,content)
    if (o.callback ~= nil) then
        if (o.obj == nil) then
            o.callback(content)
        else
            o.callback(o.obj,content)
        end
    end
end
withtable = {}
function doWithNetCallback(i,content)
    if (withtable[i]~=nil) then
        withtable[i](content)
    end
end

sync={
    init=function()
        CocosNet:getMe():init()
        CocosNet:getMe():newClient(1,"112.124.26.245",5050)
    end,
    req = function(o,callback)
        reqData = LuaReqData:create()
        reqData:setContent(json.encode(o))
        reqData.callback = callback
        CocosNet:getMe():reqToServer(1,reqData)
    end,
    reqwithobject = function(req,obj,callback)
        reqData = LuaReqData:create()
        reqData.obj = obj
        reqData:setContent(json.encode(req))
        reqData.callback = callback
        CocosNet:getMe():reqToServer(1,reqData)
    end,
    send = function(i,content,callback)
        CocosNet:getMe():sendToServer(1,i,content)
        if (callback ~= nil) then
            withtable[i] = callback
        end
    end,
    with = function(i,callback)
        withtable[i] = callback
    end,
}
