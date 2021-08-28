#include "window.h"

size_t Window::getWidth()
{
    return m_width;
}

void Window::setWidth(size_t l_width)
{
    m_width = l_width;
}

size_t Window::getHeight()
{
    return m_height;
}

void Window::setHeight(size_t l_height)
{
    m_height = l_height;
}

std::vector<uint32_t>* Window::getFrameBuffer()
{
    return m_frameBuffer;
}

void Window::changeFrameBuffer(std::vector<uint32_t>* l_frameBuffer)
{
    m_frameBuffer = l_frameBuffer;
}

Window::Window(size_t l_width, size_t l_height, uint32_t color):
    m_width(l_width), m_height(l_height)
{
    m_frameBuffer = new std::vector<uint32_t>(m_width * m_height, color);
}

Window::~Window()
{

}
