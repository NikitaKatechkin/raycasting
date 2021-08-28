#ifndef WINDOW_H_INCLUDED
#define WINDOW_H_INCLUDED

#include <cstddef>
#include <vector>
#include <cstdint>

class Window
{
private:
    size_t m_width;
    size_t m_height;

    std::vector<uint32_t>* m_frameBuffer;
public:
    size_t getWidth();
    void setWidth(size_t l_width);

    size_t getHeight();
    void setHeight(size_t l_height);

    std::vector<uint32_t>* getFrameBuffer();
    void changeFrameBuffer(std::vector<uint32_t>* l_frameBuffer);

    Window(size_t l_width, size_t l_height, uint32_t color);
    ~Window();
};

#endif // WINDOW_H_INCLUDED
