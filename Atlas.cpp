#include "Atlas.h"
#include "Utils.h"

void Atlas::load_from_file(LPCTSTR path_template, int num)
{
	m_img_list.clear();
	m_img_list.resize(num);

	TCHAR path[256]{};
	for (int i = 0; i < num; i++)
	{
		_stprintf_s(path, path_template, i + 1);
		loadimage(&m_img_list[i], path);
	}

}

IMAGE* Atlas::get_image(size_t index)
{
	if (index >= m_img_list.size()) 
		return nullptr;
	return &m_img_list[index];
}

void Atlas::add_image(const IMAGE& img)
{
	m_img_list.push_back(img);
}

void Atlas::flip_atlas(Atlas& src, Atlas& dst)
{
	dst.m_img_list.clear();
	for (auto& img : src.m_img_list)
	{
		IMAGE img_flipped;
		flip_image(&img, &img_flipped);
		dst.m_img_list.push_back(img_flipped);
	}
}
