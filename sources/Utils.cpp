#include "Utils.h"
#include "Vector2.h"
#include "Camera.h"


// 使用图片的透明通道进行绘制
void putimage_alpha(int x, int y, IMAGE* img)
{
    const int w = img->getwidth();
    const int h = img->getheight();
    AlphaBlend(GetImageHDC(nullptr), x, y, w, h,
        GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}

void putimage_alpha(int dst_x, int dst_y, int width, int height, IMAGE* img, int src_x, int src_y)
{
    const int w = width > 0  ? width  : img->getwidth();
    const int h = height > 0 ? height : img->getheight();
    AlphaBlend(GetImageHDC(GetWorkingImage()), dst_x, dst_y, w, h,
        GetImageHDC(img), src_x, src_y, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}

void putimage_alpha(const POINT& pos, IMAGE* img)
{
    putimage_alpha(pos.x, pos.y, img);
}

void putimage_alpha(const Camera& camera, const POINT& pos, IMAGE* img)
{
    putimage_alpha(camera.get_window_pos(pos), img);
}

// 翻转图片
void flip_image(IMAGE* src, IMAGE* dst)
{
    const int w = src->getwidth();
    const int h = src->getheight();
    Resize(dst, w, h);
    DWORD* src_buffer = GetImageBuffer(src);
    DWORD* dst_buffer = GetImageBuffer(dst);
    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            int idx_src = y * w + x;
            int idx_dst = y * w + (w - x - 1);
            dst_buffer[idx_dst] = src_buffer[idx_src];
        }
    }
}

void outtextxy_shaded(int x, int y, LPCTSTR str, COLORREF color, COLORREF shadow_color)
{
    settextcolor(color);
    outtextxy(x + 3, y + 3, str);
    settextcolor(shadow_color);
    outtextxy(x, y, str);
}

void line(const Camera& camera, int x1, int y1, int x2, int y2)
{
    const auto [x1_, y1_] = camera.get_window_pos({ (double)x1, (double)y1 });
    const auto [x2_, y2_] = camera.get_window_pos({ (double)x2, (double)y2 });
    line((int)x1_, (int)y1_, (int)x2_, (int)y2_);
}

void sketch_image(IMAGE* src, IMAGE* dst)
{
    const int w = src->getwidth();
    const int h = src->getheight();
    Resize(dst, w, h);
    DWORD* src_buffer = GetImageBuffer(src);
    DWORD* dst_buffer = GetImageBuffer(dst);
    for (int y = 0; y < h; ++y)
    {
        for (int x = 0; x < w; ++x)
        {
            int idx = y * w + x;
            dst_buffer[idx] = BGR(RGB(255, 255, 255)) | (src_buffer[idx] & 0xFF000000);
        }
    }

}


