#pragma once
#include <vector>
#include <map>
#include <string>

class OBJModel {

public:
	OBJModel();
	~OBJModel();

	void Loadfromfile(const char* filename);
	std::vector<float> GetVertexData();
	int GetVertexCount();

private:
	struct Position { float x, y, z; };
	struct Color    { float r, g, b; };
	struct Normal   { float x, y, z; };

	void LoadMaterialFile(const char* fileName);
	bool StarWith(std::string& line, const char* text);
	void AddVertexData(int vIdx, int nIdx, const char* mtl,
		std::vector<Position>& vertices, std::vector<Normal>& normals);
	std::map<std::string, Color> mMaterialMap;
	std::vector<float> mVertexData;
}