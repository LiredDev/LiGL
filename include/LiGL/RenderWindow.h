#include <cstdlib>
#include <Windows.h>
#include <gl/GL.h>
#include <iostream>
#include <LiGL/Shape.h>
#include <LiGL/Event.h>

class Window {
    public:
        Window(int width, int height, std::string title, bool enableConsole = true, bool borderless = false) {
            if (enableConsole == false) {
                HWND console = GetConsoleWindow();
                ShowWindow(console, SW_HIDE);
                
            };
            isActive = true;
            m_width = width;
            m_height = height;
            m_title = title;
            // Register the window class
            WNDCLASS wc = {};
            wc.lpfnWndProc = Window::WndProc;
            wc.hInstance = GetModuleHandle(nullptr);
            wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
            wc.lpszClassName = "MyWindowClass";
            RegisterClass(&wc);
            // Create the window
            m_hWnd = CreateWindow(wc.lpszClassName, m_title.c_str(), WS_OVERLAPPEDWINDOW,
                CW_USEDEFAULT, CW_USEDEFAULT, m_width, m_height, nullptr, nullptr,
                GetModuleHandle(nullptr), nullptr);
            // Create an OpenGL context and link it to the window
            HDC hDC = GetDC(m_hWnd);
            PIXELFORMATDESCRIPTOR pfd = {0};
            pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
            pfd.nVersion = 1;
            pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
            pfd.iPixelType = PFD_TYPE_RGBA;
            pfd.cColorBits = 32;
            pfd.cDepthBits = 24;
            pfd.cStencilBits = 8;
            int iPixelFormat = ChoosePixelFormat(hDC, &pfd);
            SetPixelFormat(hDC, iPixelFormat, &pfd);
            HGLRC hRC = wglCreateContext(hDC);
            wglMakeCurrent(hDC, hRC);
            ReleaseDC(m_hWnd, hDC);
            // Show the window
            ShowWindow(m_hWnd, SW_SHOW);
            if (borderless == true) {
                LONG_PTR dwStyle = GetWindowLongPtr(m_hWnd, GWL_STYLE);
                dwStyle &= ~(WS_CAPTION | WS_THICKFRAME | WS_MINIMIZE | WS_MAXIMIZE | WS_SYSMENU);
                SetWindowLongPtr(m_hWnd, GWL_STYLE, dwStyle);
            }
        };

        ~Window()
        {
            // Destroy the OpenGL context and the window
            HDC hDC = GetDC(m_hWnd);
            HGLRC hRC = wglGetCurrentContext();
            wglMakeCurrent(nullptr, nullptr);
            wglDeleteContext(hRC);
            ReleaseDC(m_hWnd, hDC);
            DestroyWindow(m_hWnd);
        }
        void Clear(float r, float g, float b, float a) {
            // Clear the screen
            glClearColor(r, g, b, a);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        };
        void Draw(Shape& shape); // not implemented yet
        void Display() {
            // Swap the front and back buffers
            HDC hDC = GetDC(m_hWnd);
            SwapBuffers(hDC);
            ReleaseDC(m_hWnd, hDC);
        };
        void DrawPoint(int x, int y, float r, float g, float b)
        {
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(0, m_width, 0, m_height, -1, 1);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
            glPointSize(1.0);
            glBegin(GL_POINTS);
            glColor3f(r, g, b);
            glVertex2i(x, m_height - y); // OpenGL has its origin in the lower left corner
            glEnd();
        }
        bool Active() {
            return isActive;
        };
        void Close() {
            isActive = false;
        }
        bool pollEvent(Event &event) {
            MSG msg = {};
            // Check if there is a message in the queue
            if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
                // Translate and dispatch the message
                TranslateMessage(&msg);
                DispatchMessage(&msg);
                // Check the message type and return the corresponding event
                event.key = static_cast<int>(msg.wParam);
                switch(msg.message) {
                    case WM_CLOSE:
                        event.type = Event::Closed;
                        return true;
                    case WM_QUIT:
                        event.type = Event::Closed;
                        return true;
                    case WM_KEYDOWN:
                        event.type = Event::KeyPressed;
                        return true;
                    case WM_KEYUP:
                        event.type = Event::KeyReleased;
                        return true;
                    case WM_LBUTTONDOWN:
                        event.type = Event::MouseButtonPressed;
                        return true;
                    case WM_LBUTTONUP:
                        event.type = Event::MouseButtonReleased;
                        return true;
                    case WM_RBUTTONDOWN:
                        event.type = Event::MouseButtonPressed;
                        return true;
                    case WM_RBUTTONUP:
                        event.type = Event::MouseButtonReleased;
                        return true;
                    case WM_SIZE:
                        event.type = Event::Resized;
                        event.width = LOWORD(msg.lParam);
                        event.height = HIWORD(msg.lParam);
                        return true;
                    case WM_MOUSEMOVE:
                        event.type = Event::MouseMoved;
                        POINT mousePos = this->GetMousePosition();
                        event.Mouse_X = mousePos.x;
                        event.Mouse_Y = mousePos.y;
                        return true;
                    // Add cases for other message types you want to handle
                }
            }
            // If there is no message in the queue, return NoEvent
            event.type =  Event::NoEvent;
            return false;
        }

        std::string luaPollEvent() {
            MSG msg = {};
            // Check if there is a message in the queue
            if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
                // Translate and dispatch the message
                TranslateMessage(&msg);
                DispatchMessage(&msg);
                // Check the message type and return the corresponding event
                this->PressedKey = static_cast<int>(msg.wParam);
                switch(msg.message) {
                    case WM_CLOSE:
                        return "Closed";
                    case WM_QUIT:
                        return "Closed";
                    case WM_KEYDOWN:
                        return "KeyPressed";
                    case WM_KEYUP:
                        return "KeyReleased";
                    case WM_LBUTTONDOWN:
                        return "MouseButtonPressed";
                    case WM_LBUTTONUP:
                        return "MouseButtonReleased";
                    case WM_RBUTTONDOWN:
                        return "MouseButtonPressed";
                    case WM_RBUTTONUP:
                        return "MouseButtonReleased";
                    case WM_SIZE:
                        EventWidth = LOWORD(msg.lParam);
                        EventHeight = HIWORD(msg.lParam);
                        return "Resized";
                    case WM_MOUSEMOVE:
                        POINT mousePos = this->GetMousePosition();
                        Mouse_X = mousePos.x;
                        Mouse_Y = mousePos.y;
                        return "MouseMoved";
                    // Add cases for other message types you want to handle
                }
            }
            // If there is no message in the queue, return NoEvent
            return "NoEvent";
        }

        int luaGetPressedKey() {
            return PressedKey;
        }

        int luaGetMouseX() {
            return Mouse_X;
        }

        int luaGetMouseY() {
            return Mouse_Y;
        }

        int luaGetEventWidth() {
            return EventWidth;
        }

        int luaGetEventHeight() {
            return EventHeight;
        }

        POINT GetMousePosition() {
            POINT mousePos;
            GetCursorPos(&mousePos); // Get the mouse position in screen coordinates
            ScreenToClient(m_hWnd, &mousePos); // Convert screen coordinates to client (window) coordinates
            // Adjust the y-coordinate as OpenGL has its origin in the lower left corner
            //mousePos.y = mousePos.y;
            return mousePos;
        }

        void updateView(int width, int height) {
            m_width = width;
            m_height = height;

            // Update the viewport
            glViewport(0, 0, m_width, m_height);

            // Update the projection matrix
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(0, m_width, 0, m_height, -1, 1);
            glMatrixMode(GL_MODELVIEW);
        }
    private:
        int m_width;
        int m_height;
        bool isActive;
        int PressedKey;
        int Mouse_X;
        int Mouse_Y;
        int EventWidth;
        int EventHeight;
        std::string m_title;
        HWND m_hWnd;
        static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
        {
            switch (uMsg)
            {
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
            }
            return DefWindowProc(hWnd, uMsg, wParam, lParam);
        }
};