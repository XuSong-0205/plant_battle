#pragma once

#include <vector>
#include <memory>
#include <easyx.h>



// 图集类
class Atlas
{
public:
	Atlas() = default;
	~Atlas() = default;

	void clear() {  m_img_list.clear(); }
	size_t get_size() { return m_img_list.size(); }
	// 加载图集
	void load_from_file(LPCTSTR path_template, int num);
	IMAGE* get_image(size_t index);
	void add_image(const IMAGE& img);


public:
	// 翻转图集
	static void flip_atlas(Atlas& src, Atlas& dst);


private:
	std::vector<IMAGE> m_img_list;
};

