-- game values:

colour = 100
level = 25
lives = 10

-- Sprites:
playerSprite = "assets/Ufoph.bmp"
motherShip = "assets/Mothership.bmp"
playerLaser = "assets/PlayerLaser.bmp"
ufo1 = "assets/Ufo1.bmp"
ufo2 = "assets/Ufo2.bmp"




-- Vector2 locations
startPos = { x = 500, y = 620}
mothershipPos = { x=0, y=20}
playerLaserOffset = {x=33, y=0}
ufoLaserOffset = {x=35, y=53}




math.randomseed(os.time())


function randomNumber()
	return math.random(1,10000)
end



function right(x,currentFrame)
	x = x+5 --increase the x coordinate value

	if (x >= 910) --don't let the coordinate exceed the window
	then
		x = 910
	end

	if (currentFrame > 1.9) --reset the frame
	then
		currentFrame = 0
	end
	
	return x, currentFrame
end

function left(x,currentFrame)
	x = x-5 --decreases the x coordinate value

	if (x <= 10) --don't let the coordinate exceed the window
	then
		x = 10
	end

	if (currentFrame > 1.9) --reset the frame
	then
		currentFrame = 0
	end
	
	return x, currentFrame
end








function callMessage()
	display_message("Get a Life", 1)
end












function setPlayerScore()
	CDispatcher("setScore", 5000)
end