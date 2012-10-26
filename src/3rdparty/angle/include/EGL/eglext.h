begin_unit
begin_ifndef
ifndef|#
directive|ifndef
name|__eglext_h_
end_ifndef
begin_define
DECL|macro|__eglext_h_
define|#
directive|define
name|__eglext_h_
end_define
begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef
begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* ** Copyright (c) 2007-2012 The Khronos Group Inc. ** ** Permission is hereby granted, free of charge, to any person obtaining a ** copy of this software and/or associated documentation files (the ** "Materials"), to deal in the Materials without restriction, including ** without limitation the rights to use, copy, modify, merge, publish, ** distribute, sublicense, and/or sell copies of the Materials, and to ** permit persons to whom the Materials are furnished to do so, subject to ** the following conditions: ** ** The above copyright notice and this permission notice shall be included ** in all copies or substantial portions of the Materials. ** ** THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, ** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF ** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. ** IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY ** CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, ** TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE ** MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS. */
include|#
directive|include
file|<EGL/eglplatform.h>
comment|/*************************************************************/
comment|/* Header file version number */
comment|/* Current version at http://www.khronos.org/registry/egl/ */
comment|/* $Revision: 16473 $ on $Date: 2012-01-04 02:20:48 -0800 (Wed, 04 Jan 2012) $ */
DECL|macro|EGL_EGLEXT_VERSION
define|#
directive|define
name|EGL_EGLEXT_VERSION
value|11
ifndef|#
directive|ifndef
name|EGL_KHR_config_attribs
DECL|macro|EGL_KHR_config_attribs
define|#
directive|define
name|EGL_KHR_config_attribs
value|1
DECL|macro|EGL_CONFORMANT_KHR
define|#
directive|define
name|EGL_CONFORMANT_KHR
value|0x3042
comment|/* EGLConfig attribute */
DECL|macro|EGL_VG_COLORSPACE_LINEAR_BIT_KHR
define|#
directive|define
name|EGL_VG_COLORSPACE_LINEAR_BIT_KHR
value|0x0020
comment|/* EGL_SURFACE_TYPE bitfield */
DECL|macro|EGL_VG_ALPHA_FORMAT_PRE_BIT_KHR
define|#
directive|define
name|EGL_VG_ALPHA_FORMAT_PRE_BIT_KHR
value|0x0040
comment|/* EGL_SURFACE_TYPE bitfield */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_KHR_lock_surface
DECL|macro|EGL_KHR_lock_surface
define|#
directive|define
name|EGL_KHR_lock_surface
value|1
DECL|macro|EGL_READ_SURFACE_BIT_KHR
define|#
directive|define
name|EGL_READ_SURFACE_BIT_KHR
value|0x0001
comment|/* EGL_LOCK_USAGE_HINT_KHR bitfield */
DECL|macro|EGL_WRITE_SURFACE_BIT_KHR
define|#
directive|define
name|EGL_WRITE_SURFACE_BIT_KHR
value|0x0002
comment|/* EGL_LOCK_USAGE_HINT_KHR bitfield */
DECL|macro|EGL_LOCK_SURFACE_BIT_KHR
define|#
directive|define
name|EGL_LOCK_SURFACE_BIT_KHR
value|0x0080
comment|/* EGL_SURFACE_TYPE bitfield */
DECL|macro|EGL_OPTIMAL_FORMAT_BIT_KHR
define|#
directive|define
name|EGL_OPTIMAL_FORMAT_BIT_KHR
value|0x0100
comment|/* EGL_SURFACE_TYPE bitfield */
DECL|macro|EGL_MATCH_FORMAT_KHR
define|#
directive|define
name|EGL_MATCH_FORMAT_KHR
value|0x3043
comment|/* EGLConfig attribute */
DECL|macro|EGL_FORMAT_RGB_565_EXACT_KHR
define|#
directive|define
name|EGL_FORMAT_RGB_565_EXACT_KHR
value|0x30C0
comment|/* EGL_MATCH_FORMAT_KHR value */
DECL|macro|EGL_FORMAT_RGB_565_KHR
define|#
directive|define
name|EGL_FORMAT_RGB_565_KHR
value|0x30C1
comment|/* EGL_MATCH_FORMAT_KHR value */
DECL|macro|EGL_FORMAT_RGBA_8888_EXACT_KHR
define|#
directive|define
name|EGL_FORMAT_RGBA_8888_EXACT_KHR
value|0x30C2
comment|/* EGL_MATCH_FORMAT_KHR value */
DECL|macro|EGL_FORMAT_RGBA_8888_KHR
define|#
directive|define
name|EGL_FORMAT_RGBA_8888_KHR
value|0x30C3
comment|/* EGL_MATCH_FORMAT_KHR value */
DECL|macro|EGL_MAP_PRESERVE_PIXELS_KHR
define|#
directive|define
name|EGL_MAP_PRESERVE_PIXELS_KHR
value|0x30C4
comment|/* eglLockSurfaceKHR attribute */
DECL|macro|EGL_LOCK_USAGE_HINT_KHR
define|#
directive|define
name|EGL_LOCK_USAGE_HINT_KHR
value|0x30C5
comment|/* eglLockSurfaceKHR attribute */
DECL|macro|EGL_BITMAP_POINTER_KHR
define|#
directive|define
name|EGL_BITMAP_POINTER_KHR
value|0x30C6
comment|/* eglQuerySurface attribute */
DECL|macro|EGL_BITMAP_PITCH_KHR
define|#
directive|define
name|EGL_BITMAP_PITCH_KHR
value|0x30C7
comment|/* eglQuerySurface attribute */
DECL|macro|EGL_BITMAP_ORIGIN_KHR
define|#
directive|define
name|EGL_BITMAP_ORIGIN_KHR
value|0x30C8
comment|/* eglQuerySurface attribute */
DECL|macro|EGL_BITMAP_PIXEL_RED_OFFSET_KHR
define|#
directive|define
name|EGL_BITMAP_PIXEL_RED_OFFSET_KHR
value|0x30C9
comment|/* eglQuerySurface attribute */
DECL|macro|EGL_BITMAP_PIXEL_GREEN_OFFSET_KHR
define|#
directive|define
name|EGL_BITMAP_PIXEL_GREEN_OFFSET_KHR
value|0x30CA
comment|/* eglQuerySurface attribute */
DECL|macro|EGL_BITMAP_PIXEL_BLUE_OFFSET_KHR
define|#
directive|define
name|EGL_BITMAP_PIXEL_BLUE_OFFSET_KHR
value|0x30CB
comment|/* eglQuerySurface attribute */
DECL|macro|EGL_BITMAP_PIXEL_ALPHA_OFFSET_KHR
define|#
directive|define
name|EGL_BITMAP_PIXEL_ALPHA_OFFSET_KHR
value|0x30CC
comment|/* eglQuerySurface attribute */
DECL|macro|EGL_BITMAP_PIXEL_LUMINANCE_OFFSET_KHR
define|#
directive|define
name|EGL_BITMAP_PIXEL_LUMINANCE_OFFSET_KHR
value|0x30CD
comment|/* eglQuerySurface attribute */
DECL|macro|EGL_LOWER_LEFT_KHR
define|#
directive|define
name|EGL_LOWER_LEFT_KHR
value|0x30CE
comment|/* EGL_BITMAP_ORIGIN_KHR value */
DECL|macro|EGL_UPPER_LEFT_KHR
define|#
directive|define
name|EGL_UPPER_LEFT_KHR
value|0x30CF
comment|/* EGL_BITMAP_ORIGIN_KHR value */
ifdef|#
directive|ifdef
name|EGL_EGLEXT_PROTOTYPES
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglLockSurfaceKHR
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
name|EGLSurface
name|surface
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglUnlockSurfaceKHR
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
name|EGLSurface
name|surface
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* EGL_EGLEXT_PROTOTYPES */
DECL|typedef|PFNEGLLOCKSURFACEKHRPROC
typedef|typedef
name|EGLBoolean
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLLOCKSURFACEKHRPROC
function_decl|)
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
name|EGLSurface
name|surface
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
DECL|typedef|PFNEGLUNLOCKSURFACEKHRPROC
typedef|typedef
name|EGLBoolean
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLUNLOCKSURFACEKHRPROC
function_decl|)
parameter_list|(
name|EGLDisplay
name|display
parameter_list|,
name|EGLSurface
name|surface
parameter_list|)
function_decl|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_KHR_image
DECL|macro|EGL_KHR_image
define|#
directive|define
name|EGL_KHR_image
value|1
DECL|macro|EGL_NATIVE_PIXMAP_KHR
define|#
directive|define
name|EGL_NATIVE_PIXMAP_KHR
value|0x30B0
comment|/* eglCreateImageKHR target */
DECL|typedef|EGLImageKHR
typedef|typedef
name|void
modifier|*
name|EGLImageKHR
typedef|;
DECL|macro|EGL_NO_IMAGE_KHR
define|#
directive|define
name|EGL_NO_IMAGE_KHR
value|((EGLImageKHR)0)
ifdef|#
directive|ifdef
name|EGL_EGLEXT_PROTOTYPES
name|EGLAPI
name|EGLImageKHR
name|EGLAPIENTRY
name|eglCreateImageKHR
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLContext
name|ctx
parameter_list|,
name|EGLenum
name|target
parameter_list|,
name|EGLClientBuffer
name|buffer
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglDestroyImageKHR
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLImageKHR
name|image
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* EGL_EGLEXT_PROTOTYPES */
DECL|typedef|PFNEGLCREATEIMAGEKHRPROC
typedef|typedef
name|EGLImageKHR
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLCREATEIMAGEKHRPROC
function_decl|)
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLContext
name|ctx
parameter_list|,
name|EGLenum
name|target
parameter_list|,
name|EGLClientBuffer
name|buffer
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
DECL|typedef|PFNEGLDESTROYIMAGEKHRPROC
typedef|typedef
name|EGLBoolean
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLDESTROYIMAGEKHRPROC
function_decl|)
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLImageKHR
name|image
parameter_list|)
function_decl|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_KHR_vg_parent_image
DECL|macro|EGL_KHR_vg_parent_image
define|#
directive|define
name|EGL_KHR_vg_parent_image
value|1
DECL|macro|EGL_VG_PARENT_IMAGE_KHR
define|#
directive|define
name|EGL_VG_PARENT_IMAGE_KHR
value|0x30BA
comment|/* eglCreateImageKHR target */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_KHR_gl_texture_2D_image
DECL|macro|EGL_KHR_gl_texture_2D_image
define|#
directive|define
name|EGL_KHR_gl_texture_2D_image
value|1
DECL|macro|EGL_GL_TEXTURE_2D_KHR
define|#
directive|define
name|EGL_GL_TEXTURE_2D_KHR
value|0x30B1
comment|/* eglCreateImageKHR target */
DECL|macro|EGL_GL_TEXTURE_LEVEL_KHR
define|#
directive|define
name|EGL_GL_TEXTURE_LEVEL_KHR
value|0x30BC
comment|/* eglCreateImageKHR attribute */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_KHR_gl_texture_cubemap_image
DECL|macro|EGL_KHR_gl_texture_cubemap_image
define|#
directive|define
name|EGL_KHR_gl_texture_cubemap_image
value|1
DECL|macro|EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X_KHR
define|#
directive|define
name|EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_X_KHR
value|0x30B3
comment|/* eglCreateImageKHR target */
DECL|macro|EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_X_KHR
define|#
directive|define
name|EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_X_KHR
value|0x30B4
comment|/* eglCreateImageKHR target */
DECL|macro|EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Y_KHR
define|#
directive|define
name|EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Y_KHR
value|0x30B5
comment|/* eglCreateImageKHR target */
DECL|macro|EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_KHR
define|#
directive|define
name|EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_KHR
value|0x30B6
comment|/* eglCreateImageKHR target */
DECL|macro|EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Z_KHR
define|#
directive|define
name|EGL_GL_TEXTURE_CUBE_MAP_POSITIVE_Z_KHR
value|0x30B7
comment|/* eglCreateImageKHR target */
DECL|macro|EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_KHR
define|#
directive|define
name|EGL_GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_KHR
value|0x30B8
comment|/* eglCreateImageKHR target */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_KHR_gl_texture_3D_image
DECL|macro|EGL_KHR_gl_texture_3D_image
define|#
directive|define
name|EGL_KHR_gl_texture_3D_image
value|1
DECL|macro|EGL_GL_TEXTURE_3D_KHR
define|#
directive|define
name|EGL_GL_TEXTURE_3D_KHR
value|0x30B2
comment|/* eglCreateImageKHR target */
DECL|macro|EGL_GL_TEXTURE_ZOFFSET_KHR
define|#
directive|define
name|EGL_GL_TEXTURE_ZOFFSET_KHR
value|0x30BD
comment|/* eglCreateImageKHR attribute */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_KHR_gl_renderbuffer_image
DECL|macro|EGL_KHR_gl_renderbuffer_image
define|#
directive|define
name|EGL_KHR_gl_renderbuffer_image
value|1
DECL|macro|EGL_GL_RENDERBUFFER_KHR
define|#
directive|define
name|EGL_GL_RENDERBUFFER_KHR
value|0x30B9
comment|/* eglCreateImageKHR target */
endif|#
directive|endif
if|#
directive|if
name|KHRONOS_SUPPORT_INT64
comment|/* EGLTimeKHR requires 64-bit uint support */
ifndef|#
directive|ifndef
name|EGL_KHR_reusable_sync
DECL|macro|EGL_KHR_reusable_sync
define|#
directive|define
name|EGL_KHR_reusable_sync
value|1
DECL|typedef|EGLSyncKHR
typedef|typedef
name|void
modifier|*
name|EGLSyncKHR
typedef|;
DECL|typedef|EGLTimeKHR
typedef|typedef
name|khronos_utime_nanoseconds_t
name|EGLTimeKHR
typedef|;
DECL|macro|EGL_SYNC_STATUS_KHR
define|#
directive|define
name|EGL_SYNC_STATUS_KHR
value|0x30F1
DECL|macro|EGL_SIGNALED_KHR
define|#
directive|define
name|EGL_SIGNALED_KHR
value|0x30F2
DECL|macro|EGL_UNSIGNALED_KHR
define|#
directive|define
name|EGL_UNSIGNALED_KHR
value|0x30F3
DECL|macro|EGL_TIMEOUT_EXPIRED_KHR
define|#
directive|define
name|EGL_TIMEOUT_EXPIRED_KHR
value|0x30F5
DECL|macro|EGL_CONDITION_SATISFIED_KHR
define|#
directive|define
name|EGL_CONDITION_SATISFIED_KHR
value|0x30F6
DECL|macro|EGL_SYNC_TYPE_KHR
define|#
directive|define
name|EGL_SYNC_TYPE_KHR
value|0x30F7
DECL|macro|EGL_SYNC_REUSABLE_KHR
define|#
directive|define
name|EGL_SYNC_REUSABLE_KHR
value|0x30FA
DECL|macro|EGL_SYNC_FLUSH_COMMANDS_BIT_KHR
define|#
directive|define
name|EGL_SYNC_FLUSH_COMMANDS_BIT_KHR
value|0x0001
comment|/* eglClientWaitSyncKHR<flags> bitfield */
DECL|macro|EGL_FOREVER_KHR
define|#
directive|define
name|EGL_FOREVER_KHR
value|0xFFFFFFFFFFFFFFFFull
DECL|macro|EGL_NO_SYNC_KHR
define|#
directive|define
name|EGL_NO_SYNC_KHR
value|((EGLSyncKHR)0)
ifdef|#
directive|ifdef
name|EGL_EGLEXT_PROTOTYPES
name|EGLAPI
name|EGLSyncKHR
name|EGLAPIENTRY
name|eglCreateSyncKHR
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLenum
name|type
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglDestroySyncKHR
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSyncKHR
name|sync
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLint
name|EGLAPIENTRY
name|eglClientWaitSyncKHR
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSyncKHR
name|sync
parameter_list|,
name|EGLint
name|flags
parameter_list|,
name|EGLTimeKHR
name|timeout
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglSignalSyncKHR
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSyncKHR
name|sync
parameter_list|,
name|EGLenum
name|mode
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglGetSyncAttribKHR
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSyncKHR
name|sync
parameter_list|,
name|EGLint
name|attribute
parameter_list|,
name|EGLint
modifier|*
name|value
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* EGL_EGLEXT_PROTOTYPES */
DECL|typedef|PFNEGLCREATESYNCKHRPROC
typedef|typedef
name|EGLSyncKHR
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLCREATESYNCKHRPROC
function_decl|)
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLenum
name|type
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
DECL|typedef|PFNEGLDESTROYSYNCKHRPROC
typedef|typedef
name|EGLBoolean
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLDESTROYSYNCKHRPROC
function_decl|)
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSyncKHR
name|sync
parameter_list|)
function_decl|;
DECL|typedef|PFNEGLCLIENTWAITSYNCKHRPROC
typedef|typedef
name|EGLint
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLCLIENTWAITSYNCKHRPROC
function_decl|)
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSyncKHR
name|sync
parameter_list|,
name|EGLint
name|flags
parameter_list|,
name|EGLTimeKHR
name|timeout
parameter_list|)
function_decl|;
DECL|typedef|PFNEGLSIGNALSYNCKHRPROC
typedef|typedef
name|EGLBoolean
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLSIGNALSYNCKHRPROC
function_decl|)
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSyncKHR
name|sync
parameter_list|,
name|EGLenum
name|mode
parameter_list|)
function_decl|;
DECL|typedef|PFNEGLGETSYNCATTRIBKHRPROC
typedef|typedef
name|EGLBoolean
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLGETSYNCATTRIBKHRPROC
function_decl|)
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSyncKHR
name|sync
parameter_list|,
name|EGLint
name|attribute
parameter_list|,
name|EGLint
modifier|*
name|value
parameter_list|)
function_decl|;
endif|#
directive|endif
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_KHR_image_base
DECL|macro|EGL_KHR_image_base
define|#
directive|define
name|EGL_KHR_image_base
value|1
comment|/* Most interfaces defined by EGL_KHR_image_pixmap above */
DECL|macro|EGL_IMAGE_PRESERVED_KHR
define|#
directive|define
name|EGL_IMAGE_PRESERVED_KHR
value|0x30D2
comment|/* eglCreateImageKHR attribute */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_KHR_image_pixmap
DECL|macro|EGL_KHR_image_pixmap
define|#
directive|define
name|EGL_KHR_image_pixmap
value|1
comment|/* Interfaces defined by EGL_KHR_image above */
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_IMG_context_priority
DECL|macro|EGL_IMG_context_priority
define|#
directive|define
name|EGL_IMG_context_priority
value|1
DECL|macro|EGL_CONTEXT_PRIORITY_LEVEL_IMG
define|#
directive|define
name|EGL_CONTEXT_PRIORITY_LEVEL_IMG
value|0x3100
DECL|macro|EGL_CONTEXT_PRIORITY_HIGH_IMG
define|#
directive|define
name|EGL_CONTEXT_PRIORITY_HIGH_IMG
value|0x3101
DECL|macro|EGL_CONTEXT_PRIORITY_MEDIUM_IMG
define|#
directive|define
name|EGL_CONTEXT_PRIORITY_MEDIUM_IMG
value|0x3102
DECL|macro|EGL_CONTEXT_PRIORITY_LOW_IMG
define|#
directive|define
name|EGL_CONTEXT_PRIORITY_LOW_IMG
value|0x3103
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_KHR_lock_surface2
DECL|macro|EGL_KHR_lock_surface2
define|#
directive|define
name|EGL_KHR_lock_surface2
value|1
DECL|macro|EGL_BITMAP_PIXEL_SIZE_KHR
define|#
directive|define
name|EGL_BITMAP_PIXEL_SIZE_KHR
value|0x3110
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_NV_coverage_sample
DECL|macro|EGL_NV_coverage_sample
define|#
directive|define
name|EGL_NV_coverage_sample
value|1
DECL|macro|EGL_COVERAGE_BUFFERS_NV
define|#
directive|define
name|EGL_COVERAGE_BUFFERS_NV
value|0x30E0
DECL|macro|EGL_COVERAGE_SAMPLES_NV
define|#
directive|define
name|EGL_COVERAGE_SAMPLES_NV
value|0x30E1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_NV_depth_nonlinear
DECL|macro|EGL_NV_depth_nonlinear
define|#
directive|define
name|EGL_NV_depth_nonlinear
value|1
DECL|macro|EGL_DEPTH_ENCODING_NV
define|#
directive|define
name|EGL_DEPTH_ENCODING_NV
value|0x30E2
DECL|macro|EGL_DEPTH_ENCODING_NONE_NV
define|#
directive|define
name|EGL_DEPTH_ENCODING_NONE_NV
value|0
DECL|macro|EGL_DEPTH_ENCODING_NONLINEAR_NV
define|#
directive|define
name|EGL_DEPTH_ENCODING_NONLINEAR_NV
value|0x30E3
endif|#
directive|endif
if|#
directive|if
name|KHRONOS_SUPPORT_INT64
comment|/* EGLTimeNV requires 64-bit uint support */
ifndef|#
directive|ifndef
name|EGL_NV_sync
DECL|macro|EGL_NV_sync
define|#
directive|define
name|EGL_NV_sync
value|1
DECL|macro|EGL_SYNC_PRIOR_COMMANDS_COMPLETE_NV
define|#
directive|define
name|EGL_SYNC_PRIOR_COMMANDS_COMPLETE_NV
value|0x30E6
DECL|macro|EGL_SYNC_STATUS_NV
define|#
directive|define
name|EGL_SYNC_STATUS_NV
value|0x30E7
DECL|macro|EGL_SIGNALED_NV
define|#
directive|define
name|EGL_SIGNALED_NV
value|0x30E8
DECL|macro|EGL_UNSIGNALED_NV
define|#
directive|define
name|EGL_UNSIGNALED_NV
value|0x30E9
DECL|macro|EGL_SYNC_FLUSH_COMMANDS_BIT_NV
define|#
directive|define
name|EGL_SYNC_FLUSH_COMMANDS_BIT_NV
value|0x0001
DECL|macro|EGL_FOREVER_NV
define|#
directive|define
name|EGL_FOREVER_NV
value|0xFFFFFFFFFFFFFFFFull
DECL|macro|EGL_ALREADY_SIGNALED_NV
define|#
directive|define
name|EGL_ALREADY_SIGNALED_NV
value|0x30EA
DECL|macro|EGL_TIMEOUT_EXPIRED_NV
define|#
directive|define
name|EGL_TIMEOUT_EXPIRED_NV
value|0x30EB
DECL|macro|EGL_CONDITION_SATISFIED_NV
define|#
directive|define
name|EGL_CONDITION_SATISFIED_NV
value|0x30EC
DECL|macro|EGL_SYNC_TYPE_NV
define|#
directive|define
name|EGL_SYNC_TYPE_NV
value|0x30ED
DECL|macro|EGL_SYNC_CONDITION_NV
define|#
directive|define
name|EGL_SYNC_CONDITION_NV
value|0x30EE
DECL|macro|EGL_SYNC_FENCE_NV
define|#
directive|define
name|EGL_SYNC_FENCE_NV
value|0x30EF
DECL|macro|EGL_NO_SYNC_NV
define|#
directive|define
name|EGL_NO_SYNC_NV
value|((EGLSyncNV)0)
DECL|typedef|EGLSyncNV
typedef|typedef
name|void
modifier|*
name|EGLSyncNV
typedef|;
DECL|typedef|EGLTimeNV
typedef|typedef
name|khronos_utime_nanoseconds_t
name|EGLTimeNV
typedef|;
ifdef|#
directive|ifdef
name|EGL_EGLEXT_PROTOTYPES
name|EGLSyncNV
name|eglCreateFenceSyncNV
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLenum
name|condition
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
name|EGLBoolean
name|eglDestroySyncNV
parameter_list|(
name|EGLSyncNV
name|sync
parameter_list|)
function_decl|;
name|EGLBoolean
name|eglFenceNV
parameter_list|(
name|EGLSyncNV
name|sync
parameter_list|)
function_decl|;
name|EGLint
name|eglClientWaitSyncNV
parameter_list|(
name|EGLSyncNV
name|sync
parameter_list|,
name|EGLint
name|flags
parameter_list|,
name|EGLTimeNV
name|timeout
parameter_list|)
function_decl|;
name|EGLBoolean
name|eglSignalSyncNV
parameter_list|(
name|EGLSyncNV
name|sync
parameter_list|,
name|EGLenum
name|mode
parameter_list|)
function_decl|;
name|EGLBoolean
name|eglGetSyncAttribNV
parameter_list|(
name|EGLSyncNV
name|sync
parameter_list|,
name|EGLint
name|attribute
parameter_list|,
name|EGLint
modifier|*
name|value
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* EGL_EGLEXT_PROTOTYPES */
DECL|typedef|PFNEGLCREATEFENCESYNCNVPROC
typedef|typedef
name|EGLSyncNV
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLCREATEFENCESYNCNVPROC
function_decl|)
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLenum
name|condition
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
DECL|typedef|PFNEGLDESTROYSYNCNVPROC
typedef|typedef
name|EGLBoolean
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLDESTROYSYNCNVPROC
function_decl|)
parameter_list|(
name|EGLSyncNV
name|sync
parameter_list|)
function_decl|;
DECL|typedef|PFNEGLFENCENVPROC
typedef|typedef
name|EGLBoolean
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLFENCENVPROC
function_decl|)
parameter_list|(
name|EGLSyncNV
name|sync
parameter_list|)
function_decl|;
DECL|typedef|PFNEGLCLIENTWAITSYNCNVPROC
typedef|typedef
name|EGLint
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLCLIENTWAITSYNCNVPROC
function_decl|)
parameter_list|(
name|EGLSyncNV
name|sync
parameter_list|,
name|EGLint
name|flags
parameter_list|,
name|EGLTimeNV
name|timeout
parameter_list|)
function_decl|;
DECL|typedef|PFNEGLSIGNALSYNCNVPROC
typedef|typedef
name|EGLBoolean
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLSIGNALSYNCNVPROC
function_decl|)
parameter_list|(
name|EGLSyncNV
name|sync
parameter_list|,
name|EGLenum
name|mode
parameter_list|)
function_decl|;
DECL|typedef|PFNEGLGETSYNCATTRIBNVPROC
typedef|typedef
name|EGLBoolean
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLGETSYNCATTRIBNVPROC
function_decl|)
parameter_list|(
name|EGLSyncNV
name|sync
parameter_list|,
name|EGLint
name|attribute
parameter_list|,
name|EGLint
modifier|*
name|value
parameter_list|)
function_decl|;
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
name|KHRONOS_SUPPORT_INT64
comment|/* Dependent on EGL_KHR_reusable_sync which requires 64-bit uint support */
ifndef|#
directive|ifndef
name|EGL_KHR_fence_sync
DECL|macro|EGL_KHR_fence_sync
define|#
directive|define
name|EGL_KHR_fence_sync
value|1
comment|/* Reuses most tokens and entry points from EGL_KHR_reusable_sync */
DECL|macro|EGL_SYNC_PRIOR_COMMANDS_COMPLETE_KHR
define|#
directive|define
name|EGL_SYNC_PRIOR_COMMANDS_COMPLETE_KHR
value|0x30F0
DECL|macro|EGL_SYNC_CONDITION_KHR
define|#
directive|define
name|EGL_SYNC_CONDITION_KHR
value|0x30F8
DECL|macro|EGL_SYNC_FENCE_KHR
define|#
directive|define
name|EGL_SYNC_FENCE_KHR
value|0x30F9
endif|#
directive|endif
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_HI_clientpixmap
DECL|macro|EGL_HI_clientpixmap
define|#
directive|define
name|EGL_HI_clientpixmap
value|1
comment|/* Surface Attribute */
DECL|macro|EGL_CLIENT_PIXMAP_POINTER_HI
define|#
directive|define
name|EGL_CLIENT_PIXMAP_POINTER_HI
value|0x8F74
comment|/*  * Structure representing a client pixmap  * (pixmap's data is in client-space memory).  */
DECL|struct|EGLClientPixmapHI
struct|struct
name|EGLClientPixmapHI
block|{
DECL|member|pData
name|void
modifier|*
name|pData
decl_stmt|;
DECL|member|iWidth
name|EGLint
name|iWidth
decl_stmt|;
DECL|member|iHeight
name|EGLint
name|iHeight
decl_stmt|;
DECL|member|iStride
name|EGLint
name|iStride
decl_stmt|;
block|}
struct|;
ifdef|#
directive|ifdef
name|EGL_EGLEXT_PROTOTYPES
name|EGLAPI
name|EGLSurface
name|EGLAPIENTRY
name|eglCreatePixmapSurfaceHI
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLConfig
name|config
parameter_list|,
name|struct
name|EGLClientPixmapHI
modifier|*
name|pixmap
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* EGL_EGLEXT_PROTOTYPES */
DECL|typedef|PFNEGLCREATEPIXMAPSURFACEHIPROC
typedef|typedef
name|EGLSurface
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLCREATEPIXMAPSURFACEHIPROC
function_decl|)
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLConfig
name|config
parameter_list|,
name|struct
name|EGLClientPixmapHI
modifier|*
name|pixmap
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* EGL_HI_clientpixmap */
ifndef|#
directive|ifndef
name|EGL_HI_colorformats
DECL|macro|EGL_HI_colorformats
define|#
directive|define
name|EGL_HI_colorformats
value|1
comment|/* Config Attribute */
DECL|macro|EGL_COLOR_FORMAT_HI
define|#
directive|define
name|EGL_COLOR_FORMAT_HI
value|0x8F70
comment|/* Color Formats */
DECL|macro|EGL_COLOR_RGB_HI
define|#
directive|define
name|EGL_COLOR_RGB_HI
value|0x8F71
DECL|macro|EGL_COLOR_RGBA_HI
define|#
directive|define
name|EGL_COLOR_RGBA_HI
value|0x8F72
DECL|macro|EGL_COLOR_ARGB_HI
define|#
directive|define
name|EGL_COLOR_ARGB_HI
value|0x8F73
endif|#
directive|endif
comment|/* EGL_HI_colorformats */
ifndef|#
directive|ifndef
name|EGL_MESA_drm_image
DECL|macro|EGL_MESA_drm_image
define|#
directive|define
name|EGL_MESA_drm_image
value|1
DECL|macro|EGL_DRM_BUFFER_FORMAT_MESA
define|#
directive|define
name|EGL_DRM_BUFFER_FORMAT_MESA
value|0x31D0
comment|/* CreateDRMImageMESA attribute */
DECL|macro|EGL_DRM_BUFFER_USE_MESA
define|#
directive|define
name|EGL_DRM_BUFFER_USE_MESA
value|0x31D1
comment|/* CreateDRMImageMESA attribute */
DECL|macro|EGL_DRM_BUFFER_FORMAT_ARGB32_MESA
define|#
directive|define
name|EGL_DRM_BUFFER_FORMAT_ARGB32_MESA
value|0x31D2
comment|/* EGL_IMAGE_FORMAT_MESA attribute value */
DECL|macro|EGL_DRM_BUFFER_MESA
define|#
directive|define
name|EGL_DRM_BUFFER_MESA
value|0x31D3
comment|/* eglCreateImageKHR target */
DECL|macro|EGL_DRM_BUFFER_STRIDE_MESA
define|#
directive|define
name|EGL_DRM_BUFFER_STRIDE_MESA
value|0x31D4
DECL|macro|EGL_DRM_BUFFER_USE_SCANOUT_MESA
define|#
directive|define
name|EGL_DRM_BUFFER_USE_SCANOUT_MESA
value|0x00000001
comment|/* EGL_DRM_BUFFER_USE_MESA bits */
DECL|macro|EGL_DRM_BUFFER_USE_SHARE_MESA
define|#
directive|define
name|EGL_DRM_BUFFER_USE_SHARE_MESA
value|0x00000002
comment|/* EGL_DRM_BUFFER_USE_MESA bits */
ifdef|#
directive|ifdef
name|EGL_EGLEXT_PROTOTYPES
name|EGLAPI
name|EGLImageKHR
name|EGLAPIENTRY
name|eglCreateDRMImageMESA
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglExportDRMImageMESA
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLImageKHR
name|image
parameter_list|,
name|EGLint
modifier|*
name|name
parameter_list|,
name|EGLint
modifier|*
name|handle
parameter_list|,
name|EGLint
modifier|*
name|stride
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* EGL_EGLEXT_PROTOTYPES */
DECL|typedef|PFNEGLCREATEDRMIMAGEMESAPROC
typedef|typedef
name|EGLImageKHR
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLCREATEDRMIMAGEMESAPROC
function_decl|)
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
specifier|const
name|EGLint
modifier|*
name|attrib_list
parameter_list|)
function_decl|;
DECL|typedef|PFNEGLEXPORTDRMIMAGEMESAPROC
typedef|typedef
name|EGLBoolean
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLEXPORTDRMIMAGEMESAPROC
function_decl|)
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLImageKHR
name|image
parameter_list|,
name|EGLint
modifier|*
name|name
parameter_list|,
name|EGLint
modifier|*
name|handle
parameter_list|,
name|EGLint
modifier|*
name|stride
parameter_list|)
function_decl|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_NV_post_sub_buffer
DECL|macro|EGL_NV_post_sub_buffer
define|#
directive|define
name|EGL_NV_post_sub_buffer
value|1
DECL|macro|EGL_POST_SUB_BUFFER_SUPPORTED_NV
define|#
directive|define
name|EGL_POST_SUB_BUFFER_SUPPORTED_NV
value|0x30BE
ifdef|#
directive|ifdef
name|EGL_EGLEXT_PROTOTYPES
name|EGLAPI
name|EGLBoolean
name|EGLAPIENTRY
name|eglPostSubBufferNV
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSurface
name|surface
parameter_list|,
name|EGLint
name|x
parameter_list|,
name|EGLint
name|y
parameter_list|,
name|EGLint
name|width
parameter_list|,
name|EGLint
name|height
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* EGL_EGLEXT_PROTOTYPES */
DECL|typedef|PFNEGLPOSTSUBBUFFERNVPROC
typedef|typedef
name|EGLBoolean
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLPOSTSUBBUFFERNVPROC
function_decl|)
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSurface
name|surface
parameter_list|,
name|EGLint
name|x
parameter_list|,
name|EGLint
name|y
parameter_list|,
name|EGLint
name|width
parameter_list|,
name|EGLint
name|height
parameter_list|)
function_decl|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_ANGLE_query_surface_pointer
DECL|macro|EGL_ANGLE_query_surface_pointer
define|#
directive|define
name|EGL_ANGLE_query_surface_pointer
value|1
ifdef|#
directive|ifdef
name|EGL_EGLEXT_PROTOTYPES
name|EGLAPI
name|EGLBoolean
name|eglQuerySurfacePointerANGLE
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSurface
name|surface
parameter_list|,
name|EGLint
name|attribute
parameter_list|,
name|void
modifier|*
modifier|*
name|value
parameter_list|)
function_decl|;
endif|#
directive|endif
DECL|typedef|PFNEGLQUERYSURFACEPOINTERANGLEPROC
typedef|typedef
name|EGLBoolean
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLQUERYSURFACEPOINTERANGLEPROC
function_decl|)
parameter_list|(
name|EGLDisplay
name|dpy
parameter_list|,
name|EGLSurface
name|surface
parameter_list|,
name|EGLint
name|attribute
parameter_list|,
name|void
modifier|*
modifier|*
name|value
parameter_list|)
function_decl|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_ANGLE_software_display
DECL|macro|EGL_ANGLE_software_display
define|#
directive|define
name|EGL_ANGLE_software_display
value|1
DECL|macro|EGL_SOFTWARE_DISPLAY_ANGLE
define|#
directive|define
name|EGL_SOFTWARE_DISPLAY_ANGLE
value|((EGLNativeDisplayType)-1)
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_ANGLE_surface_d3d_texture_2d_share_handle
DECL|macro|EGL_ANGLE_surface_d3d_texture_2d_share_handle
define|#
directive|define
name|EGL_ANGLE_surface_d3d_texture_2d_share_handle
value|1
DECL|macro|EGL_D3D_TEXTURE_2D_SHARE_HANDLE_ANGLE
define|#
directive|define
name|EGL_D3D_TEXTURE_2D_SHARE_HANDLE_ANGLE
value|0x3200
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_NV_coverage_sample_resolve
DECL|macro|EGL_NV_coverage_sample_resolve
define|#
directive|define
name|EGL_NV_coverage_sample_resolve
value|1
DECL|macro|EGL_COVERAGE_SAMPLE_RESOLVE_NV
define|#
directive|define
name|EGL_COVERAGE_SAMPLE_RESOLVE_NV
value|0x3131
DECL|macro|EGL_COVERAGE_SAMPLE_RESOLVE_DEFAULT_NV
define|#
directive|define
name|EGL_COVERAGE_SAMPLE_RESOLVE_DEFAULT_NV
value|0x3132
DECL|macro|EGL_COVERAGE_SAMPLE_RESOLVE_NONE_NV
define|#
directive|define
name|EGL_COVERAGE_SAMPLE_RESOLVE_NONE_NV
value|0x3133
endif|#
directive|endif
if|#
directive|if
name|KHRONOS_SUPPORT_INT64
comment|/* EGLTimeKHR requires 64-bit uint support */
ifndef|#
directive|ifndef
name|EGL_NV_system_time
DECL|macro|EGL_NV_system_time
define|#
directive|define
name|EGL_NV_system_time
value|1
DECL|typedef|EGLuint64NV
typedef|typedef
name|khronos_utime_nanoseconds_t
name|EGLuint64NV
typedef|;
ifdef|#
directive|ifdef
name|EGL_EGLEXT_PROTOTYPES
name|EGLAPI
name|EGLuint64NV
name|EGLAPIENTRY
name|eglGetSystemTimeFrequencyNV
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|EGLAPI
name|EGLuint64NV
name|EGLAPIENTRY
name|eglGetSystemTimeNV
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* EGL_EGLEXT_PROTOTYPES */
DECL|typedef|PFNEGLGETSYSTEMTIMEFREQUENCYNVPROC
typedef|typedef
name|EGLuint64NV
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLGETSYSTEMTIMEFREQUENCYNVPROC
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
DECL|typedef|PFNEGLGETSYSTEMTIMENVPROC
typedef|typedef
name|EGLuint64NV
function_decl|(
name|EGLAPIENTRYP
name|PFNEGLGETSYSTEMTIMENVPROC
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
endif|#
directive|endif
endif|#
directive|endif
ifndef|#
directive|ifndef
name|EGL_EXT_create_context_robustness
DECL|macro|EGL_EXT_create_context_robustness
define|#
directive|define
name|EGL_EXT_create_context_robustness
value|1
DECL|macro|EGL_CONTEXT_OPENGL_ROBUST_ACCESS_EXT
define|#
directive|define
name|EGL_CONTEXT_OPENGL_ROBUST_ACCESS_EXT
value|0x30BF
DECL|macro|EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY_EXT
define|#
directive|define
name|EGL_CONTEXT_OPENGL_RESET_NOTIFICATION_STRATEGY_EXT
value|0x3138
DECL|macro|EGL_NO_RESET_NOTIFICATION_EXT
define|#
directive|define
name|EGL_NO_RESET_NOTIFICATION_EXT
value|0x31BE
DECL|macro|EGL_LOSE_CONTEXT_ON_RESET_EXT
define|#
directive|define
name|EGL_LOSE_CONTEXT_ON_RESET_EXT
value|0x31BF
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern
begin_endif
endif|#
directive|endif
end_endif
begin_endif
endif|#
directive|endif
end_endif
end_unit
