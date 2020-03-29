#pragma once

#include <assert.h>

template<class T>
class GLBuffer
{
public:
	GLBuffer(GLenum bufferType) {
		_bufferType = bufferType;
		glGenBuffers(1, &id);
		assert(id != 0);		
	}
	virtual ~GLBuffer() {
		glDeleteBuffers(1, &id);
	}

	void bind() const {
		assert(id != 0);
		glBindBuffer(_bufferType, id);
	}

	void setData(const vector<T>& data) {
		bind();
		glBufferData(_bufferType, sizeof(T) * data.size(),
			&data[0], GL_STATIC_DRAW);
		_size = data.size();
	}
	size_t size() const {
		return _size;
	}
protected:
	GLuint id = 0;
	GLenum _bufferType = 0;
	size_t _size=0;
};


