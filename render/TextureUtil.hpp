#ifndef _DEEP_TERRAIN_RL_RENDER_TEXTUREUTIL_H_
#define _DEEP_TERRAIN_RL_RENDER_TEXTUREUTIL_H_

#include <stdlib.h>
#include <GL/glew.h>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
#include <fstream>

#include "util/MathUtil.hpp"

void CreateFrameBuffer( GLuint& buffer_obj, GLuint& texture, GLuint& depth_stencil,
					   int width, int height, int depth, int channels, GLenum format, GLenum type, bool mipmaps = false );
void ReshapeFrameBuffer( GLuint& buffer_obj, GLuint& texture, GLuint& depth_stencil,
					   int width, int height );
void DeleteFrameBuffer( GLuint& buffer_obj, GLuint& texture, GLuint& depth_stencil );
tVector ReadTexel(int x, int y, int w, int h, const std::vector<GLubyte>& data);

#endif
