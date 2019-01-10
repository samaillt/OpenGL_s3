#include "project_classes/Model.hpp"

using namespace glimac;

Model::Model(const std::string obj, const FilePath &applicationPath)
:_obj(obj){
		Geometry geometry;
		FilePath modelPath = applicationPath.dirPath() + "../src/assets/models/" + obj + "/" + obj;
		FilePath objPath(modelPath.addExt(".obj")); 
		FilePath mtlPath(modelPath.addExt(".mtl")); 
		bool ret = geometry.loadOBJ(objPath, mtlPath, true);
		if (!ret)
			exit(1); 

		_geometry = geometry;
		setVbo();
		setIbo();
		setVao();
}

Model::Model(){}

Model::Model(const Model &model)
: _geometry(model._geometry){
	setVbo();
	setIbo();
	setVao();
};

void Model::setVbo(){
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, _geometry.getVertexCount() * sizeof(Geometry::Vertex), _geometry.getVertexBuffer(), GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	_vbo = vbo;
}

void Model::setIbo(){
	GLuint ibo;
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _geometry.getIndexCount() * sizeof(uint32_t), _geometry.getIndexBuffer(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	_ibo = ibo;
}


void Model::setVao(){
	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);

	const GLuint VERTEX_ATTR_POSITION = 0;
	const GLuint VERTEX_ATTR_NORMAL = 1;
	const GLuint VERTEX_ATTR_TEXCOORD = 2;
	glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
	glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
	glEnableVertexAttribArray(VERTEX_ATTR_TEXCOORD);

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Geometry::Vertex), (const GLvoid*) offsetof(Geometry::Vertex, m_Position));
	glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(Geometry::Vertex), (const GLvoid*) offsetof(Geometry::Vertex, m_Normal));
	glVertexAttribPointer(VERTEX_ATTR_TEXCOORD, 2, GL_FLOAT, GL_FALSE, sizeof(Geometry::Vertex), (const GLvoid*) offsetof(Geometry::Vertex, m_TexCoords));
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
	_vao = vao;
}

Geometry Model::getGeometry(){
    return _geometry;
}

GLuint Model::getVao(){
    return _vao;
}

GLuint Model::getIbo(){
    return _ibo;
}

GLuint Model::getVbo(){
    return _vbo;
}

std::string Model::getObj(){
    return _obj;
}

//destructor
Model::~Model(){
	glDeleteBuffers(1, &_vbo);
    glDeleteVertexArrays(1, &_vao);
}