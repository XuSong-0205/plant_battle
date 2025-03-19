#pragma once

#include <vector>
#include <memory>
#include <easyx.h>



// ͼ����
class Atlas
{
public:
	Atlas() = default;
	~Atlas() = default;

	void clear() {  m_img_list.clear(); }
	size_t get_size() { return m_img_list.size(); }
	// ����ͼ��
	void load_from_file(LPCTSTR path_template, int num);
	IMAGE* get_image(size_t index);
	void add_image(const IMAGE& img);


public:
	// ��תͼ��
	static void flip_atlas(Atlas& src, Atlas& dst);


private:
	std::vector<IMAGE> m_img_list;
};

