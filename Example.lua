-- Create a window with a width of 800 pixels and a height of 600 pixels
local window = Window(800, 600, "Window Title", false, false)

-- Main loop
local event = Event()
local keyboard = Keyboard()

local width = 5
local height = 5
local i = 0
local j = 0

window:setTransparency(0.5)

while window:Active() do
    event.Name = window:pollEvent()
    if event.Name == "Closed" then
        window:Close()
        break
    end
    if event.Name == "Resized" then
        window:updateView(window:GetEventWidth(), window:GetEventHeight())
    end
    if event.Name == "KeyPressed" then
        local key = window:GetPressedKey()
        print(key, keyboard.KEY_A)
        if key == keyboard.KEY_A then
            i = i - 1
        end
        if key == keyboard.KEY_D then
            i = i + 1
        end
        if key == keyboard.KEY_W then
            j = j - 1
        end
        if key == keyboard.KEY_S then
            j = j + 1
        end
    end

    window:Clear(0, 0, 0, 0)
    for y = 0, height, 1 do
        for x = 0, width, 1 do
            window:drawPoint(i + x, j + y, 255, 0, 0)
        end
    end
    for y = 0, 10, 1 do
        for x = 0, 10, 1 do
            window:drawPoint(window:GetMouseX() + x, window:GetMouseY() + y, 30, 128, 50)
        end
    end
    window:Display()
end
