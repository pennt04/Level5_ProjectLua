-- game values:

colour = 100
level = 25
lives = 10
playerSprite = "assets/Ufoph.bmp"




motherShip = "assets/Mothership.bmp"
playerLaser = "assets/PlayerLaser.bmp"

ufo1 = "assets/Ufo1.bmp"
ufo2 = "assets/Ufo2.bmp"




-- a simple object, Vector2
startPos = { x = 500, y = 620}






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