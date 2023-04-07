-- Create a new window
local window = RenderWindow(800, 600, "Window")

local event = Event()

local width = 10
local height = 69

-- Start the game loop
while window:isOpen() do
    -- Handle events
    while window:pollEvent() do
        if event:compareState("Closed") then
            window:close()
        end
    end
    
    -- Draw the rectangle
    window:clear()

    for y = 0,height,1 do
        for x = 0,width,1 do
            window:drawPoint(10 + x, 10 + y, 255, 0, 0)
        end
    end
    
    window:display()
end
