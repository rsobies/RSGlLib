#pragma once

#include <assert.h>

/// <summary>
/// Class represents opegnGl buffer object.
/// </summary>
template<class T>
class GLBuffer
{
public:
	/// <summary>
	/// Contructs buffer of givent type.
	/// </summary>
	/// <param name="bufferType">OpenGl buffer type.</param>
	GLBuffer(GLenum bufferType) {

		_bufferType = bufferType;
		glGenBuffers(1, &id);
		assert(id != 0);		
	}

	/// <summary>
	/// Destroys the buffer.
	/// </summary>
	virtual ~GLBuffer() {
		glDeleteBuffers(1, &id);
	}

	/// <summary>
	/// Binds the buffer.
	/// </summary>
	void bind() const {
		assert(id != 0);
		glBindBuffer(_bufferType, id);
	}

	/// <summary>
	/// Sends data to buffer.
	/// </summary>
	/// <param name="data">Data to send.</param>
	void setData(const vector<T>& data) {
		bind();
		glBufferData(_bufferType, sizeof(T) * data.size(),
			&data[0], GL_STATIC_DRAW);
		_size = data.size();
	}

	/// <summary>
	/// Retrives the number of elements in the buffer.
	/// </summary>
	/// <returns>Elements of the buffer.</returns>
	size_t size() const {
		return _size;
	}
protected:
	/// <summary>
	/// Id of this buffer.
	/// </summary>
	GLuint id = 0;

	/// <summary>
	/// Buffer type.
	/// </summary>
	GLenum _bufferType = 0;

	/// <summary>
	/// Numer of elements in the buffer.
	/// </summary>
	size_t _size=0;
};


