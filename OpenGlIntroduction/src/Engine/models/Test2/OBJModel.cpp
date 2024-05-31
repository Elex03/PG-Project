#include "OBJModel.h"
#include <iostream>
#include <fstream>

OBJModel::OBJModel() {

}
OBJModel::~OBJModel() {

}
void OBJModel::Loadfromfile(const char* fileName) {
	std::vector <Position> vertices;
	std::vector <Normal> normals;

	std::ifstream file(fileName);
	if (file)
	{
		char currentMetlName[100];
		std::string line;

		while (std::getline(file, line))
		{
			if (StarWith(line, "mtllib"))
			{
				char mtfileName[100];
				(void)sscanf_s(line.c_str(), "mtllib %s", mtfileName, sizeof(mtfileName));
				LoadMaterialFile(mtfileName);
			}
			if (StarWith(line, "v ")) {
				Position pos;
				sscanf_s(line.c_str(), "v %f %f %f", &pos.x, &pos.y, &pos.z);
				vertices.push_back(pos);
			}
			if (StarWith(line, "vn ")) {
				Normal n;
				sscanf_s(line.c_str(), "v %f %f %f", &n.x, &n.y, &n.z);
				normals.push_back(n);
			}
			if (StarWith(line, "usermtl")) {
				(void)sscanf_s(line.c_str(), "usermtl %s", currentMetlName, sizeof(currentMetlName));
			}
			if (StarWith(line, "f "))
			{
				int v1, v2, v3;
				int n1, n2, n3;
				(void)sscanf_s(line.c_str(), "f %d//%d %d//%d %d//%d", &v1, &v2, &v3, &n1, &n2, &n3);

				AddVertexData(v1, n1, currentMetlName, vertices, normals);
				AddVertexData(v2, n3, currentMetlName, vertices, normals);
				AddVertexData(v2, n3, currentMetlName, vertices, normals);
			}
		}
	}
	else {
		std::cout << "OBJ file loading faided" << std::endl;
	}
}

std::vector<float> OBJModel::GetVertexData() {
	return mVertexData;
}
int OBJModel::GetVertexCount() {
	return mVertexData.size() / 9;
}
void OBJModel::LoadMaterialFile(const char* fileName) {
	std::ifstream file(fileName);
	if (file) {
		std::string line;
		while (std::getline(file, line))
		{
			char mtName[100];
			if (StarWith(line, "newmtl"))
			{
				(void)sscanf_s(line.c_str(), "newmtl %s", mtName, sizeof(mtName));
				mMaterialMap[mtName] = Color();
			}
			if (StarWith(line, "Kd"))
			{
				Color& color = mMaterialMap[mtName];
				sscanf_s(line.c_str(), "Kd %f %f %f", &color.r, &color.g, &color.b);
			}
		}
	}
	else
		std::cout << "Material file loading failed" << std::endl;
}
bool OBJModel::StarWith(std::string& line, const char* text) {
	size_t textLen = strlen(text);
	if (line.size() < textLen)
		return false;
	for (size_t i = 0; i < textLen; i++)
	{
		if (line[i] == text[i]) continue;
		else return false;
	}
	return true;
}
void OBJModel::AddVertexData(int vIdx, int nIdx, const char* mtl,
	std::vector<Position>& vertices, std::vector<Normal>& normals) {
	Color c = mMaterialMap[mtl];
	Position p = vertices[vIdx - 1];
	Normal n = normals[nIdx - 1];

	mVertexData.push_back(p.x);
	mVertexData.push_back(p.y);
	mVertexData.push_back(p.z);
	mVertexData.push_back(c.r);
	mVertexData.push_back(c.g);
	mVertexData.push_back(c.b);
	mVertexData.push_back(n.x);
	mVertexData.push_back(n.y);
	mVertexData.push_back(n.z);
}