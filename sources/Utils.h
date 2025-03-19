#pragma once

#include <iostream>
#include <easyx.h>
#include <Windows.h>
#include <mmsystem.h>
#include <Digitalv.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "MSIMG32.LIB")


///////////////////////////////////////////
// ��������

// ������Ϣ
constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;


// ��Ϸ��Ϣ
constexpr int GAME_FPS = 90;



///////////////////////////////////////////
// ���ߺ�

// ���� MCI �ַ�������
#define MCI_SEND_STRING(str)                mciSendString(TEXT(str), nullptr, 0, nullptr)

// ������
#define MCI_MUSIC_OPEN(music)               MCI_SEND_STRING("open " #music)
// �����֣������ñ���
#define MCI_MUSIC_OPEN_ALIAS(music, alias)  MCI_SEND_STRING("open " #music " alias " #alias)
// ��ͷ��ʼ��������
#define MCI_MUSIC_PLAY(music)               MCI_SEND_STRING("play " #music " from 0")
// ��ͷ��ʼ�������֣�ѭ������
#define MCI_MUSIC_PLAY_LOOP(music)          MCI_SEND_STRING("play " #music " repeat from 0")
// ֹͣ���ֲ���
#define MCI_MUSIC_STOP(music)               MCI_SEND_STRING("stop " #music)
// ��ͣ���ֲ���
#define MCI_MUSIC_PAUSE(music)              MCI_SEND_STRING("pause " #music)
// �������ֲ���
#define MCI_MUSIC_RESUME(music)             MCI_SEND_STRING("resume " #music)
// �ر�����
#define MCI_MUSIC_CLOSE(music)              MCI_SEND_STRING("close " #music)



///////////////////////////////////////////
// ���ߺ���ģ�壬��ģ��

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


// ������ģ��
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
// ���ߺ���

class Camera;

// ʹ��ͼƬ��͸��ͨ�����л���
void putimage_alpha(int x, int y, IMAGE* img);
// ʹ��ͼƬ��͸��ͨ�����л��ƣ�ָ������ü���ʾ
void putimage_alpha(int dst_x, int dst_y, int width, int height, IMAGE* img, int src_x, int src_y);
void putimage_alpha(const POINT& pos, IMAGE* img);
void putimage_alpha(const Camera& camera, const POINT& pos, IMAGE* img);

// ��תͼƬ
void flip_image(IMAGE* src, IMAGE* dst);

// �������֣�������ӰЧ��
void outtextxy_shaded(int x, int y, LPCTSTR str, 
    COLORREF color = RGB(45, 45, 45), 
    COLORREF shadow_color = RGB(255, 255, 255));

// ������������Ļ���ֱ��
void line(const Camera& camera, int x1, int y1, int x2, int y2);
