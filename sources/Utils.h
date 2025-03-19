#pragma once

#include <iostream>
#include <easyx.h>
#include <Windows.h>
#include <mmsystem.h>
#include <Digitalv.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "MSIMG32.LIB")


///////////////////////////////////////////
// 常量定义

// 窗口信息
constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;


// 游戏信息
constexpr int GAME_FPS = 90;



///////////////////////////////////////////
// 工具宏

// 发送 MCI 字符串命令
#define MCI_SEND_STRING(str)                mciSendString(TEXT(str), nullptr, 0, nullptr)

// 打开音乐
#define MCI_MUSIC_OPEN(music)               MCI_SEND_STRING("open " #music)
// 打开音乐，并设置别名
#define MCI_MUSIC_OPEN_ALIAS(music, alias)  MCI_SEND_STRING("open " #music " alias " #alias)
// 从头开始播放音乐
#define MCI_MUSIC_PLAY(music)               MCI_SEND_STRING("play " #music " from 0")
// 从头开始播放音乐，循环播放
#define MCI_MUSIC_PLAY_LOOP(music)          MCI_SEND_STRING("play " #music " repeat from 0")
// 停止音乐播放
#define MCI_MUSIC_STOP(music)               MCI_SEND_STRING("stop " #music)
// 暂停音乐播放
#define MCI_MUSIC_PAUSE(music)              MCI_SEND_STRING("pause " #music)
// 继续音乐播放
#define MCI_MUSIC_RESUME(music)             MCI_SEND_STRING("resume " #music)
// 关闭音乐
#define MCI_MUSIC_CLOSE(music)              MCI_SEND_STRING("close " #music)



///////////////////////////////////////////
// 工具函数模板，类模板

template<typename... Args>
void print(Args&&... args) 
{
    (std::cout << ... << args);
}

template<typename... Args>
void println(Args&&... args) 
{
    print(std::forward<Args>(args)..., '\n');
}


// 单例类模板
template<typename T>
class Singleton
{
public:
    static T& get_instance()
    {
        static T instance;
        return instance;
    }

protected:
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    ~Singleton() = default;
};



///////////////////////////////////////////
// 工具函数

class Camera;

// 使用图片的透明通道进行绘制
void putimage_alpha(int x, int y, IMAGE* img);
// 使用图片的透明通道进行绘制，指定区域裁剪显示
void putimage_alpha(int dst_x, int dst_y, int width, int height, IMAGE* img, int src_x, int src_y);
void putimage_alpha(const POINT& pos, IMAGE* img);
void putimage_alpha(const Camera& camera, const POINT& pos, IMAGE* img);

// 翻转图片
void flip_image(IMAGE* src, IMAGE* dst);

// 绘制文字，带有阴影效果
void outtextxy_shaded(int x, int y, LPCTSTR str, 
    COLORREF color = RGB(45, 45, 45), 
    COLORREF shadow_color = RGB(255, 255, 255));

// 带摄像机参数的绘制直线
void line(const Camera& camera, int x1, int y1, int x2, int y2);
