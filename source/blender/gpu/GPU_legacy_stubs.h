/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2017 Blender Foundation.
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s): Blender Foundation, Dalai Felinto.
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file GPU_legacy_stubs.h
 *  \ingroup gpu
 *
 *  This is to mark the transition to OpenGL core profile
 *  The idea is to allow Blender 2.8 to be built with OpenGL 3.3 even if it means breaking things
 *
 *  This file should be removed in the future
 */

#ifndef __GPU_LEGACY_STUBS_H__
#define __GPU_LEGACY_STUBS_H__

#if defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#include "GPU_glew.h"
#include "BLI_utildefines.h"

#ifdef WITH_LEGACY_OPENGL

#define GL_RET_VOID(_FUNC_, ...) \
	gl##_FUNC_(__VA_ARGS__);
#define GL_RET_INT(_FUNC_, ...) \
	return gl##_FUNC_(__VA_ARGS__);

#else /* WITH_LEGACY_OPENGL */

#define GL_RET_VOID(_FUNC_, ...) \
	return;
#define GL_RET_INT(_FUNC_, ...) \
	return 0;

#endif  /* WITH_LEGACY_OPENGL */

static void disable_enable_check(GLenum cap)
{
	BLI_assert(ELEM(cap,
	                GL_ALPHA_TEST,
	                GL_LINE_STIPPLE,
	                GL_POINT_SPRITE,
	                GL_TEXTURE_1D,
	                GL_TEXTURE_2D,
	                GL_TEXTURE_GEN_S,
	                GL_TEXTURE_GEN_T,
	                -1
	                ));
	UNUSED_VARS_NDEBUG(cap);
}

static void tex_env_check(GLenum target, GLenum pname)
{
	BLI_assert(ELEM(target, GL_TEXTURE_ENV) ||
	           (target == GL_TEXTURE_FILTER_CONTROL && pname == GL_TEXTURE_LOD_BIAS));
	UNUSED_VARS_NDEBUG(target, pname);
}

static inline void oldAlphaFunc(GLenum func, GLclampf ref)
{
	GL_RET_VOID(AlphaFunc, func, ref);
}

static inline void oldBegin(GLenum mode)
{
	GL_RET_VOID(Begin, mode);
}

static inline void oldBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap)
{
	GL_RET_VOID(Bitmap, width, height, xorig, yorig, xmove, ymove, bitmap);
}

static inline void oldClipPlane(GLenum plane, const GLdouble *equation)
{
	GL_RET_VOID(ClipPlane, plane, equation);
}

static inline void oldColor3f(GLfloat red, GLfloat green, GLfloat blue)
{
	GL_RET_VOID(Color3f, red, green, blue);
}

static inline void oldColor3fv(const GLfloat *v)
{
	GL_RET_VOID(Color3fv, v);
}

static inline void oldColor3ub(GLubyte red, GLubyte green, GLubyte blue)
{
	GL_RET_VOID(Color3ub, red, green, blue);
}

static inline void oldColor3ubv(const GLubyte *v)
{
	GL_RET_VOID(Color3ubv, v);
}

static inline void oldColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	GL_RET_VOID(Color4f, red, green, blue, alpha);
}

static inline void oldColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
{
	GL_RET_VOID(Color4ub, red, green, blue, alpha);
}

static inline void oldColor4ubv(const GLubyte *v)
{
	GL_RET_VOID(Color4ubv, v);
}

static inline void oldColorPointer(GLint size, GLenum type, GLsizei stride, const void *pointer)
{
	GL_RET_VOID(ColorPointer, size, type, stride, pointer);
}

static inline void oldDisable(GLenum cap)
{
	disable_enable_check(cap);
	GL_RET_VOID(Disable, cap);
}

static inline void oldDisableClientState(GLenum array)
{
	GL_RET_VOID(DisableClientState, array);
}

static inline void oldEnable(GLenum cap)
{
	disable_enable_check(cap);
	GL_RET_VOID(Disable, cap);
}

static inline void oldEnableClientState(GLenum array)
{
	GL_RET_VOID(EnableClientState, array);
}

static inline void oldEnd(void)
{
	GL_RET_VOID(End);
}

static inline void oldInitNames(void)
{
	GL_RET_VOID(InitNames);
}

static inline void oldLightf(GLenum light, GLenum pname, GLfloat param)
{
	GL_RET_VOID(Lightf, light, pname, param);
}

static inline void oldLightfv(GLenum light, GLenum pname, const GLfloat *params)
{
	GL_RET_VOID(Lightfv, light, pname, params);
}

static inline void oldLineStipple(GLint factor, GLushort pattern)
{
	GL_RET_VOID(LineStipple, factor, pattern);
}

static inline void oldLoadName(GLuint name)
{
	GL_RET_VOID(LoadName, name);
}

static inline void oldMaterialfv(GLenum face, GLenum pname, const GLfloat *params)
{
	GL_RET_VOID(Materialfv, face, pname, params);
}

static inline void oldMateriali(GLenum face, GLenum pname, GLint param)
{
	GL_RET_VOID(Materiali, face, pname, param);
}

static inline void oldNormal3fv(const GLfloat *v)
{
	GL_RET_VOID(Normal3fv, v);
}

static inline void oldNormal3sv(const GLshort *v)
{
	GL_RET_VOID(Normal3sv, v);
}

static inline void oldNormalPointer(GLenum type, GLsizei stride, const void *pointer)
{
	GL_RET_VOID(NormalPointer, type, stride, pointer);
}

static inline void oldPopName(void)
{
	GL_RET_VOID(PopName);
}

static inline void oldPushName(GLuint name)
{
	GL_RET_VOID(PushName, name);
}

static inline void oldRasterPos2f(GLfloat x, GLfloat y)
{
	GL_RET_VOID(RasterPos2f, x, y);
}

static inline GLint oldRenderMode(GLenum mode)
{
	GL_RET_INT(RenderMode, mode);
}

static inline void oldSelectBuffer(GLsizei size, GLuint *buffer)
{
	GL_RET_VOID(SelectBuffer, size, buffer);
}

static inline void oldShadeModel(GLenum mode)
{
	GL_RET_VOID(ShadeModel, mode);
}

static inline void oldTexCoord2fv(const GLfloat *v)
{
	GL_RET_VOID(TexCoord2fv, v);
}

static inline void oldTexEnvf(GLenum target, GLenum pname, GLint param)
{
	tex_env_check(target, pname);
	GL_RET_VOID(TexEnvf, target, pname, param);
}

static inline void oldTexEnvfv(GLenum target, GLenum pname, const GLfloat *params)
{
	tex_env_check(target, pname);
	GL_RET_VOID(TexEnvfv, target, pname, params);
}

static inline void oldTexEnvi(GLenum target, GLenum pname, GLint param)
{
	tex_env_check(target, pname);
	GL_RET_VOID(TexEnvi, target, pname, param);
}

static inline void oldTexGeni(GLenum coord, GLenum pname, GLint param)
{
	BLI_assert(pname == GL_TEXTURE_GEN_MODE);
	GL_RET_VOID(TexGeni, coord, pname, param);
}

static inline void oldVertex2f(GLfloat x, GLfloat y)
{
	GL_RET_VOID(Vertex2f, x, y);
}

static inline void oldVertex3f(GLfloat x, GLfloat y, GLfloat z)
{
	GL_RET_VOID(Vertex3f, x, y, z);
}

static inline void oldTexCoord3fv(const GLfloat *v)
{
	GL_RET_VOID(TexCoord3fv, v);
}

static inline void oldTexCoordPointer(GLint size, GLenum type, GLsizei stride, const void *pointer)
{
	GL_RET_VOID(TexCoordPointer, size, type, stride, pointer);
}

static inline void oldVertexPointer(GLint size, GLenum type, GLsizei stride, const void *pointer)
{
	GL_RET_VOID(VertexPointer, size, type, stride, pointer);
}

static inline void oldVertex3fv(const GLfloat *v)
{
	GL_RET_VOID(Vertex3fv, v);
}

#undef GL_RET_VOID
#undef GL_RET_INT

#endif /* __GPU_LEGACY_STUBS_H__ */
