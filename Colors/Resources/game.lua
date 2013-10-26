WINDOW={
	UP = 0,
	DOWN = 1,
	CENTER = 2
}
game={
	addChild = function(sprite)
		game.scene:addChild(sprite)
	end,
    removeChild = function(sprite)
        game.scene:removeChild(sprite,true)
    end,
	start = function()
        game.scene = CCScene:create()
        local runningScene = CCDirector:sharedDirector():getRunningScene()
		if (runningScene == game.scene) then return end
		if runningScene == nil then   
			CCDirector:sharedDirector():runWithScene(game.scene)   
		else   
			CCDirector:sharedDirector():replaceScene(game.scene)   
		end  
		game.label = CCLabelTTF:create("","Aril",32)
		game.layer = CCLayer:create()
		game.scene:addChild(game.label)
		game.scene:addChild(game.layer)
		print("start game")
		return game.scene
	end,
    exit=function()
        CCDirector:sharedDirector():endToLua()
    end,
	info = function(content,loc)
		if (game.label:isVisible()) then
		--	game.label:setVisible(false)
		end
		game.label:setString(content)
		--game.label:setVisible(true)
		local s = CCDirector:sharedDirector():getWinSize()
		if (loc == WINDOW.UP) then
			game.label:setPosition(ccp(s.width/2,s.height-32))
		elseif (loc == WINDOW.CENTER) then
			game.label:setPosition(ccp(s.width/2,s.height/2))
		end
		local fadeIn = CCFadeIn:create(1.5)
		local action = CCSequence:createWithTwoActions(fadeIn,fadeIn:reverse())
		game.label:runAction(action)

	end,
	replaceScene=function(scene)
		CCDirector:sharedDirector():replaceScene(scene)
	end,
	ontouch=function(callback)
		game.layer:setTouchEnabled(true)
    		game.layer:registerScriptTouchHandler(callback)
		print("on touch ")
	end	
}
